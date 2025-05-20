//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    float cpu_usage;
} process_info;

void get_cpu_usage(int pid, float* cpu_usage) {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        *cpu_usage = (float)usage.ru_utime.tv_sec + (float)usage.ru_utime.tv_usec / 1000000;
    }
}

void get_processes(process_info* processes) {
    FILE* file = popen("ps -eo pid,%cpu", "r");
    char line[1024];
    int i = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* token = strtok(line, " ");
        int pid = atoi(token);
        float cpu_usage;
        get_cpu_usage(pid, &cpu_usage);
        strcpy(processes[i].name, token + strlen("pid="));
        processes[i].pid = pid;
        processes[i].cpu_usage = cpu_usage;
        i++;
        if (i >= MAX_PROCESSES) {
            break;
        }
    }
    pclose(file);
}

void sort_processes(process_info* processes) {
    for (int i = 0; i < MAX_PROCESSES - 1; i++) {
        for (int j = i + 1; j < MAX_PROCESSES; j++) {
            if (processes[j].cpu_usage > processes[i].cpu_usage) {
                process_info temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void print_processes(process_info* processes) {
    printf("Process\tPID\tCPU Usage\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].pid == 0) {
            break;
        }
        printf("%s\t%d\t%.2f%%\n", processes[i].name, processes[i].pid, processes[i].cpu_usage * 100);
    }
}

int main() {
    process_info processes[MAX_PROCESSES];
    get_processes(processes);
    sort_processes(processes);
    print_processes(processes);
    return 0;
}