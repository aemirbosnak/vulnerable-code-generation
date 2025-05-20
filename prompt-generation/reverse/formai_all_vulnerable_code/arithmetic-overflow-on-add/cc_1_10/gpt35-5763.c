//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// This program will monitor the CPU usage in real time

void *cpu_usage_monitor(void *arg)
{
    float total_usage = 0;
    int num_cores = sysconf(_SC_NPROCESSORS_ONLN); // get the number of CPU cores
    long int prev_user[num_cores], prev_nice[num_cores], prev_system[num_cores], prev_idle[num_cores];
    long int curr_user[num_cores], curr_nice[num_cores], curr_system[num_cores], curr_idle[num_cores];
    char cpu_file[20];

    for (int i=0; i<num_cores; i++) {
        sprintf(cpu_file, "/proc/stat");
        FILE *fp = fopen(cpu_file, "r");
        fscanf(fp, "cpu%d %ld %ld %ld %ld", &i, &prev_user[i], &prev_nice[i], &prev_system[i], &prev_idle[i]);
        fclose(fp);
    }

    while(1) {
        for (int i=0; i<num_cores; i++) {
            sprintf(cpu_file, "/proc/stat");
            FILE *fp = fopen(cpu_file, "r");
            fscanf(fp, "cpu%d %ld %ld %ld %ld", &i, &curr_user[i], &curr_nice[i], &curr_system[i], &curr_idle[i]);
            fclose(fp);
        }

        for (int i=0; i<num_cores; i++) {
            long int prev_total = prev_user[i] + prev_nice[i] + prev_system[i] + prev_idle[i];
            long int curr_total = curr_user[i] + curr_nice[i] + curr_system[i] + curr_idle[i];
            long int total_delta = curr_total - prev_total;
            float usage = ((float)(total_delta - (curr_idle[i] - prev_idle[i])) / total_delta) * 100;
            total_usage += usage;
            printf("CPU%d usage: %.2f%%\n", i, usage);
        }

        printf("Overall CPU usage: %.2f%%\n", total_usage / num_cores);
        total_usage = 0;

        sleep(1);

        for (int i=0; i<num_cores; i++) {
            prev_user[i] = curr_user[i];
            prev_nice[i] = curr_nice[i];
            prev_system[i] = curr_system[i];
            prev_idle[i] = curr_idle[i];
        }
    }

    return NULL;
}

int main()
{
    pthread_t cpu_monitor_thread;
    if (pthread_create(&cpu_monitor_thread, NULL, cpu_usage_monitor, NULL)) {
        printf("Error creating CPU monitor thread\n");
        return 1;
    }

    pthread_join(cpu_monitor_thread, NULL);
    return 0;
}