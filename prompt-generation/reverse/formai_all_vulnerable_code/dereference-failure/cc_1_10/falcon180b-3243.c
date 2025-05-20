//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 16

struct process_info {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    float cpu_usage;
};

void get_process_info(struct process_info *processes, int num_processes) {
    FILE *fp;
    char line[1024];
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    float cpu_usage;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening /proc/stat\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char *token = strtok(line, " ");
    while (token!= NULL) {
        if (strcmp(token, "cpu") == 0) {
            token = strtok(NULL, " ");
            cpu_usage = atof(token);
            break;
        }
        token = strtok(NULL, " ");
    }
    fclose(fp);

    fp = fopen("/proc/self/stat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening /proc/self/stat\n");
        exit(1);
    }

    fscanf(fp, "%d %s %*s %*s %*s %*s %*s %*s %*s", &pid, name);
    fclose(fp);

    strcpy(processes[num_processes - 1].name, name);
    processes[num_processes - 1].pid = pid;
    processes[num_processes - 1].cpu_usage = cpu_usage;
}

void print_process_info(struct process_info *processes, int num_processes) {
    printf("PID\tName\tCPU Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%.2f%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }
}

int main() {
    struct process_info processes[MAX_PROCESSES];
    int num_processes = 0;

    while (num_processes < MAX_PROCESSES) {
        get_process_info(processes, num_processes);
        num_processes++;
    }

    print_process_info(processes, num_processes);

    return 0;
}