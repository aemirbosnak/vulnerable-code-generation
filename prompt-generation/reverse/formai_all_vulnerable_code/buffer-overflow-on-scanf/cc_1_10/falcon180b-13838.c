//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_CORES 8
#define MAX_CPU_USAGE 100

int main() {
    int num_cores;
    double cpu_usage[MAX_CORES];
    char core_names[MAX_CORES][16];
    int i, j;

    printf("Enter the number of CPU cores: ");
    scanf("%d", &num_cores);

    for (i = 0; i < num_cores; i++) {
        sprintf(core_names[i], "core%d", i);
        cpu_usage[i] = 0.0;
    }

    while (1) {
        for (i = 0; i < num_cores; i++) {
            FILE *fp;
            char filename[64];
            sprintf(filename, "/sys/devices/system/cpu/cpu%d/cpufreq/cpuinfo_max_freq", i);

            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("Error: Failed to open file %s.\n", filename);
                exit(1);
            }

            double max_freq;
            fscanf(fp, "%lf", &max_freq);
            fclose(fp);

            sprintf(filename, "/sys/devices/system/cpu/cpu%d/cpufreq/scaling_cur_freq", i);
            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("Error: Failed to open file %s.\n", filename);
                exit(1);
            }

            double cur_freq;
            fscanf(fp, "%lf", &cur_freq);
            fclose(fp);

            cpu_usage[i] = (cur_freq / max_freq) * 100.0;
        }

        for (i = 0; i < num_cores; i++) {
            printf("%s: %.2f%%\n", core_names[i], cpu_usage[i]);
        }

        for (i = 0; i < num_cores; i++) {
            if (cpu_usage[i] > MAX_CPU_USAGE) {
                printf("Warning: CPU core %s usage exceeds %d%%!\n", core_names[i], MAX_CPU_USAGE);
            }
        }

        sleep(1);
    }

    return 0;
}