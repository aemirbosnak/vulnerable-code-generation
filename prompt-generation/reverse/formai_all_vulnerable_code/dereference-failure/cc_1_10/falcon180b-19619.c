//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/resource.h>

#define MAX_LINE_LENGTH 1024
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct process_info {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int cpu_usage;
} ProcessInfo;

void get_cpu_usage(int pid, float *cpu_percent) {
    struct rusage usage;
    if (getrusage(RUSAGE_CHILDREN, &usage) == -1) {
        perror("getrusage");
        exit(1);
    }

    *cpu_percent = (float)usage.ru_utime.tv_sec + (float)usage.ru_stime.tv_sec +
                    (float)usage.ru_utime.tv_usec + (float)usage.ru_stime.tv_usec;
}

void print_process_info(ProcessInfo *process_info, int num_processes) {
    printf("PID\tName\tCPU Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%.2f%%\n", process_info[i].pid, process_info[i].name, process_info[i].cpu_usage);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <interval_in_seconds>\n", argv[0]);
        return 1;
    }

    int interval = atoi(argv[1]);
    int num_processes = 0;
    ProcessInfo *process_info = malloc(sizeof(ProcessInfo) * MAX_PROCESS_NAME_LENGTH);

    while (1) {
        char line[MAX_LINE_LENGTH];
        FILE *fp = fopen("/proc/self/status", "r");
        if (fp == NULL) {
            perror("fopen");
            exit(1);
        }

        while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
            if (strncmp(line, "Name:", 5) == 0) {
                strcpy(process_info[num_processes].name, line + 6);
            } else if (strncmp(line, "State:", 6) == 0) {
                if (strncmp(line + 7, "S", 1) == 0) {
                    process_info[num_processes].pid = getpid();
                    num_processes++;
                }
            }
        }

        fclose(fp);

        for (int i = 0; i < num_processes; i++) {
            get_cpu_usage(process_info[i].pid, &process_info[i].cpu_usage);
        }

        print_process_info(process_info, num_processes);
        sleep(interval);
    }

    return 0;
}