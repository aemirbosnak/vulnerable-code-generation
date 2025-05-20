//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 1000
#define MAX_PROCESS_NAME_LENGTH 100

struct process_info {
    pid_t pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    float cpu_usage;
};

void get_process_info(struct process_info *processes, int num_processes) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = popen("ps -e -o %p %u %cpu", "r");

    if (fp == NULL) {
        printf("Error: Cannot execute ps command.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL && i < num_processes) {
        token = strtok(line, " ");
        processes[i].pid = atoi(token);
        token = strtok(NULL, " ");
        strncpy(processes[i].name, token, MAX_PROCESS_NAME_LENGTH - 1);
        token = strtok(NULL, " ");
        processes[i].cpu_usage = atof(token);
        i++;
    }

    pclose(fp);
}

int main() {
    int num_processes = 0;
    struct process_info processes[MAX_PROCESSES];

    printf("Enter the number of processes you want to monitor (max %d): ", MAX_PROCESSES - 1);
    scanf("%d", &num_processes);

    get_process_info(processes, num_processes);

    printf("\nProcess ID\tName\tCPU Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%.2f%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage * 100);
    }

    return 0;
}