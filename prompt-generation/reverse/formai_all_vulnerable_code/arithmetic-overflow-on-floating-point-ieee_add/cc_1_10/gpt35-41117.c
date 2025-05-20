//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROC 10000
#define INTERVAL 1

int main()
{
    char proc_info[MAX_PROC][50] = {0};
    int proc_count = 0;
    char proc_pid[10];
    char proc_cpu[10];
    char proc_name[50];
    float cpu_usage = 0.0;
    float cpu_usage_avg = 0.0;
    int num_procs = 0;
    int i;

    while(1) {
        system("clear");

        proc_count = 0;
        cpu_usage_avg = 0.0;

        FILE* fp = popen("ps aux", "r");
        if (fp == NULL) {
            printf("Failed to run command\n" );
            exit(1);
        }

        /* Read the output a line at a time - save process info */
        while (fgets(proc_info[proc_count], sizeof(proc_info[0]), fp) != NULL) {
            sscanf(proc_info[proc_count], "%s %s %*s %*s %*s %*s %s %*s %*s %*s %[^\n]",
                   proc_name, proc_pid, proc_cpu, proc_name);
            if (strcmp(proc_name, "cmonitor") != 0) {
                cpu_usage += atof(proc_cpu);
                proc_count++;
            }
        }

        num_procs = proc_count;
        cpu_usage_avg = cpu_usage / (float)num_procs;
        cpu_usage = 0.0;

        printf("\nCPU Usage Monitor\n");
        printf("----------------------------------------\n");
        printf("    PID | CPU USAGE | PROCESS NAME\n");
        printf("----------------------------------------\n");

        for (i = 0; i < num_procs; i++) {
            sscanf(proc_info[i], "%s %s %*s %*s %*s %*s %s %*s %*s %*s %[^\n]",
                   proc_name, proc_pid, proc_cpu, proc_name);
            if (strcmp(proc_name, "cmonitor") != 0) {
                cpu_usage += atof(proc_cpu);
                printf(" %6d | %6s%%     | %s\n", atoi(proc_pid), proc_cpu, proc_name);
            }
        }

        printf("\n CPU Average Usage: %.2f%%\n", cpu_usage_avg);
        pclose(fp);
        usleep(INTERVAL * 1000000);
    }

    return 0;
}