//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1000

struct process {
    int pid;
    char name[80];
    int status;
};

void get_processes(struct process *processes, int count) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = popen("ps -ef", "r");
    if (fp == NULL) {
        printf("Error: Failed to run ps command.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL && i < count) {
        token = strtok(line, " ");
        processes[i].pid = atoi(token);
        token = strtok(NULL, " ");
        strcpy(processes[i].name, token);
        processes[i].status = 1;
        i++;
    }

    pclose(fp);
}

void display_processes(struct process *processes, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%-5d %-16s %-10s\n", processes[i].pid, processes[i].name, processes[i].status? "Running" : "Stopped");
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int count;

    printf("Enter the number of processes to display (up to %d): ", MAX_PROCESSES);
    scanf("%d", &count);

    get_processes(processes, count);
    display_processes(processes, count);

    return 0;
}