//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CPU_CORES 64 // Maximum number of CPU cores supported

float get_cpu_usage(int cpu_core) {
    static long long prev_total_ticks[MAX_CPU_CORES];
    static long long prev_idle_ticks[MAX_CPU_CORES];
    static int initialized[MAX_CPU_CORES];
    
    // Obtain CPU statistics from /proc/stat file
    char buffer[1024];
    char filename[32];
    sprintf(filename, "/proc/stat");
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Failed to obtain CPU statistics\n");
        exit(1);
    }
    fgets(buffer, sizeof(buffer), fp); // Read the first line
    char* line = buffer;
    if (cpu_core > 0) { // Obtain stats of specific core (ignoring first line)
        for (int i = 0; i < cpu_core; i++) {
            fgets(buffer, sizeof(buffer), fp);
            line = buffer;
        }
    }
    fclose(fp);
    
    // Parse CPU statistics to calculate CPU usage percentage
    long long user_ticks, nice_ticks, system_ticks, idle_ticks, iowait_ticks, irq_ticks, softirq_ticks;
    sscanf(line, "cpu %lld %lld %lld %lld %lld %lld %lld", &user_ticks, &nice_ticks, &system_ticks, &idle_ticks, &iowait_ticks, &irq_ticks, &softirq_ticks);
    if (initialized[cpu_core]) {
        long long total_ticks, idle_diff, total_diff;
        total_ticks = user_ticks + nice_ticks + system_ticks + idle_ticks + iowait_ticks + irq_ticks + softirq_ticks;
        idle_diff = idle_ticks - prev_idle_ticks[cpu_core];
        total_diff = total_ticks - prev_total_ticks[cpu_core];
        return (100.0 * (total_diff - idle_diff) / total_diff);
    } else {
        initialized[cpu_core] = 1;
        prev_total_ticks[cpu_core] = user_ticks + nice_ticks + system_ticks + idle_ticks + iowait_ticks + irq_ticks + softirq_ticks;
        prev_idle_ticks[cpu_core] = idle_ticks;
        return 0.0;
    }
}

int main() {
    int num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    if (num_cpus > MAX_CPU_CORES) {
        fprintf(stderr, "Error: Maximum number of CPU cores supported is %d\n", MAX_CPU_CORES);
        return 1;
    } else if (num_cpus <= 0) {
        fprintf(stderr, "Error: Failed to obtain number of CPU cores\n");
        return 1;
    }

    // Continuously display CPU usage percentage
    while (1) {
        for (int i = 0; i < num_cpus; i++) {
            printf("CPU %d usage: %.2f%%\n", i, get_cpu_usage(i));
        }
        printf("\n");
        sleep(1);
    }

    return 0;
}