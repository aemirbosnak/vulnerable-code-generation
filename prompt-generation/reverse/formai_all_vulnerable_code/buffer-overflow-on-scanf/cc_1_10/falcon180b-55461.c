//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_NAME_LENGTH 20

typedef struct {
    pid_t pid;
    char name[MAX_NAME_LENGTH];
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void add_process(pid_t pid, char* name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Maximum number of processes reached!\n");
        return;
    }
    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].name, name, MAX_NAME_LENGTH);
    num_processes++;
}

void remove_process(pid_t pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i] = processes[num_processes - 1];
            num_processes--;
            break;
        }
    }
}

void print_processes() {
    printf("PID\tName\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }
}

void monitor_processes() {
    while (1) {
        print_processes();
        sleep(5);
    }
}

int main() {
    char command[100];
    pid_t pid;
    int status;
    FILE* fp;

    printf("Enter command to execute: ");
    scanf("%s", command);

    pid = fork();
    if (pid == -1) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        if (execlp(command, command, NULL) == -1) {
            printf("Command execution failed!\n");
            return 1;
        }
    } else {
        add_process(pid, command);
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            remove_process(pid);
        }
    }

    monitor_processes();

    return 0;
}