//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

int main(void) {
    char buff[BUFF_SIZE];

    while (1) {
        FILE *cpu_file = fopen("/proc/stat", "r");
        if (cpu_file == NULL) {
            perror("Failed to open file");
            exit(EXIT_FAILURE);
        }

        float total_time_1 = 0, sys_time_1 = 0, idle_time_1 = 0;

        fgets(buff, BUFF_SIZE, cpu_file);
        sscanf(buff + 5, "%f %*f %*f %*f %f", &sys_time_1, &idle_time_1);

        for (int i = 0; i < 7; i++) {
            fgets(buff, BUFF_SIZE, cpu_file);
            sscanf(buff, "%*s %f", &total_time_1);
            sys_time_1 += total_time_1;
        }
        fclose(cpu_file);

        sleep(1);

        cpu_file = fopen("/proc/stat", "r");
        if (cpu_file == NULL) {
            perror("Failed to open file");
            exit(EXIT_FAILURE);
        }

        float total_time_2 = 0, sys_time_2 = 0, idle_time_2 = 0;

        fgets(buff, BUFF_SIZE, cpu_file);
        sscanf(buff + 5, "%f %*f %*f %*f %f", &sys_time_2, &idle_time_2);

        for (int i = 0; i < 7; i++) {
            fgets(buff, BUFF_SIZE, cpu_file);
            sscanf(buff, "%*s %f", &total_time_2);
            sys_time_2 += total_time_2;
        }
        fclose(cpu_file);

        float diff_sys_time = sys_time_2 - sys_time_1;
        float diff_idle_time = idle_time_2 - idle_time_1;

        float cpu_usage = ((diff_sys_time - diff_idle_time) / diff_sys_time) * 100;

        printf("Current CPU usage: %.2f%%\n", cpu_usage);
    }

    return 0;
}