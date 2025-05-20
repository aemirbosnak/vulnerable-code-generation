//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20

typedef struct process {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    struct rusage usage;
} Process;

void get_processes(Process *processes) {
    int num_processes = 0;
    FILE *fp;
    char line[80];
    char *token;
    fp = popen("ps -e -o pid= -o comm=", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute ps command.\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_processes >= MAX_PROCESSES) {
            printf("Error: Maximum number of processes reached.\n");
            exit(1);
        }
        processes[num_processes].pid = atoi(line);
        token = strtok(line, " ");
        strcpy(processes[num_processes].name, token);
        num_processes++;
    }
    pclose(fp);
}

void get_cpu_usage(Process *processes) {
    int i;
    for (i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].pid > 0) {
            if (waitpid(processes[i].pid, NULL, WNOHANG) == 0) {
                getrusage(RUSAGE_CHILDREN, &processes[i].usage);
            }
        }
    }
}

void print_cpu_usage(Process *processes) {
    int i;
    double cpu_percentage;
    for (i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].pid > 0) {
            cpu_percentage = (double)processes[i].usage.ru_utime.tv_sec + (double)processes[i].usage.ru_stime.tv_sec + (double)processes[i].usage.ru_utime.tv_usec + (double)processes[i].usage.ru_stime.tv_usec / 1000000.0;
            printf("PID: %d, Name: %s, CPU Usage: %.2f%%\n", processes[i].pid, processes[i].name, cpu_percentage);
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int i;
    get_processes(processes);
    while (1) {
        get_cpu_usage(processes);
        print_cpu_usage(processes);
        sleep(5);
    }
    return 0;
}