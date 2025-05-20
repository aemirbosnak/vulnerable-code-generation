//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_LINE_SIZE 1024

/* Function to print the current usage stats of the system */
void get_cpu_usage() {
    FILE *fp;
    char buff[MAX_LINE_SIZE];
    unsigned long long int user_time, nice_time, system_time, idle_time, iowait_time, irq_time, softirq_time, steal_time, guest_time, guest_nice_time;
    unsigned long long int total_time, non_idle_time;
    int cpu_count = -1;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/stat file.\n");
        return;
    }

    /* Read first line of the file, which contains the overall usage stats */
    if (fgets(buff, MAX_LINE_SIZE, fp) != NULL) {
        sscanf(buff, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", 
            &user_time, &nice_time, &system_time, &idle_time, &iowait_time, &irq_time, &softirq_time, &steal_time, &guest_time, &guest_nice_time);
        total_time = user_time + nice_time + system_time + idle_time + iowait_time + irq_time + softirq_time + steal_time;
        non_idle_time = user_time + nice_time + system_time + irq_time + softirq_time + steal_time;
        cpu_count++;
    }

    /* Read the remaining lines of the file, which contain usage stats for individual CPUs */
    while (fgets(buff, MAX_LINE_SIZE, fp) != NULL) {
        if (strncmp(buff, "cpu", 3) == 0 && isdigit(buff[3])) {
            sscanf(buff, "cpu%*d %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", 
                &user_time, &nice_time, &system_time, &idle_time, &iowait_time, &irq_time, &softirq_time, &steal_time, &guest_time, &guest_nice_time);
            total_time += user_time + nice_time + system_time + idle_time + iowait_time + irq_time + softirq_time + steal_time;
            non_idle_time += user_time + nice_time + system_time + irq_time + softirq_time + steal_time;
            cpu_count++;
        }
    }

    fclose(fp);

    /* Calculate and print the overall CPU usage percentage */
    float cpu_usage = ((float)(non_idle_time - user_time - nice_time) * 100) / (non_idle_time - idle_time);
    printf("Overall CPU usage: %.2f%%\n", cpu_usage);

    /* Calculate and print the CPU usage percentage for individual CPUs */
    if (cpu_count > 0) {
        float cpu_usage_avg = cpu_usage / cpu_count;
        printf("CPU usage per core:\n");

        fp = fopen("/proc/cpuinfo", "r");
        if (fp == NULL) {
            printf("Error: could not open /proc/cpuinfo file.\n");
            return;
        }

        int i = 0;
        char model_name[MAX_LINE_SIZE];

        while (fgets(buff, MAX_LINE_SIZE, fp) != NULL) {
            if (strncmp(buff, "model name", 10) == 0) {
                sscanf(buff, "model name : %[^\n]s", model_name);
                printf("%s: %.2f%%\n", model_name, cpu_usage_avg);
                i++;
            }
            if (i == cpu_count) {
                break;
            }
        }

        fclose(fp);
    }
}

int main() {
    while (1) {
        get_cpu_usage();
        sleep(1);
    }
    return 0;
}