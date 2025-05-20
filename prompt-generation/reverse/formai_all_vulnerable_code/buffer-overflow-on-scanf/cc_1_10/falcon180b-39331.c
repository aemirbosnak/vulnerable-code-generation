//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>

#define MAX_PROCESSES 50
#define BUFFER_SIZE 1024

struct process {
    int pid;
    char name[100];
};

int get_processes(struct process *processes) {
    char buffer[BUFFER_SIZE];
    char *token;
    FILE *fp;
    int count = 0;

    fp = popen("ps -ef", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute ps command.\n");
        return -1;
    }

    while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
        token = strtok(buffer, " ");
        if (token!= NULL) {
            processes[count].pid = atoi(token);
            strcpy(processes[count].name, strtok(NULL, " "));
            count++;
        }
    }

    pclose(fp);
    return count;
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes;
    char input[100];

    printf("Enter number of processes to view (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    num_processes = get_processes(processes);

    if (num_processes < 0) {
        return -1;
    }

    printf("PID\tNAME\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }

    printf("Enter PID of process to kill: ");
    scanf("%d", &processes[0].pid);

    kill(processes[0].pid, SIGKILL);

    return 0;
}