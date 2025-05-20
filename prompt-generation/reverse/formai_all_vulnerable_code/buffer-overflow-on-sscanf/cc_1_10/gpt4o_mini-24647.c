//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define STAT_PATH "/proc/stat"
#define CPU_USAGE_INTERVAL 1
#define NUM_CPU 4

void read_cpu_times(long long *user, long long *nice, long long *system, long long *idle) {
    FILE *file = fopen(STAT_PATH, "r");
    if (file == NULL) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[256];
    fgets(line, sizeof(line), file);
    fclose(file);

    sscanf(line, "cpu %lld %lld %lld %lld", user, nice, system, idle);
}

double calculate_cpu_usage(long long prev_total, long long prev_idle, long long total, long long idle) {
    long long total_diff = total - prev_total;
    long long idle_diff = idle - prev_idle;

    if (total_diff == 0) {
        return 0.0;
    }

    return 100.0 * (total_diff - idle_diff) / total_diff;
}

void get_cpu_usage() {
    long long user, nice, system, idle;
    long long prev_user, prev_nice, prev_system, prev_idle;
    long long prev_total, total;

    read_cpu_times(&prev_user, &prev_nice, &prev_system, &prev_idle);
    prev_total = prev_user + prev_nice + prev_system + prev_idle;

    while (1) {
        sleep(CPU_USAGE_INTERVAL);

        // Read the CPU times again.
        read_cpu_times(&user, &nice, &system, &idle);
        total = user + nice + system + idle;

        double usage = calculate_cpu_usage(prev_total, prev_idle, total, idle);
        printf("CPU Usage: %.2f%%\n", usage);

        // Update previous values for the next iteration.
        prev_user = user;
        prev_nice = nice;
        prev_system = system;
        prev_idle = idle;
        prev_total = total;
    }
}

int main(int argc, char *argv[]) {
    printf("\n========= CPU Usage Monitor =========\n");
    printf("Press Ctrl+C to exit.\n");

    get_cpu_usage();

    return 0;
}