//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_PROCESSES 100

struct process_info {
    int pid;
    char name[16];
    float cpu_usage;
};

void get_process_info(struct process_info *processes, int num_processes) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL && i < num_processes) {
        token = strtok(line, " ");
        if (token!= NULL) {
            sscanf(token, "%d", &processes[i].pid);
            token = strtok(NULL, " ");
            if (token!= NULL) {
                strncpy(processes[i].name, token, sizeof(processes[i].name) - 1);
                processes[i].name[sizeof(processes[i].name) - 1] = '\0';
            } else {
                strcpy(processes[i].name, "Unknown");
            }
            token = strtok(NULL, " ");
            if (token!= NULL) {
                processes[i].cpu_usage = atof(token);
            } else {
                processes[i].cpu_usage = 0.0;
            }
            i++;
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    int num_processes = 0;
    struct process_info processes[MAX_PROCESSES];

    if (argc > 1) {
        sscanf(argv[1], "%d", &num_processes);
    } else {
        num_processes = MAX_PROCESSES;
    }

    get_process_info(processes, num_processes);

    printf("Process ID\tProcess Name\tCPU Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%.2f%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage * 100.0);
    }

    return 0;
}