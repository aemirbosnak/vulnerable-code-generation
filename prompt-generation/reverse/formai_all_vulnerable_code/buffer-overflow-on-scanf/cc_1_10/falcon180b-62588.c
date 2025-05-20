//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROCESSES 100

typedef struct process {
    char name[50];
    int pid;
    int status;
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(char* name, int pid) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    strcpy(processes[num_processes].name, name);
    processes[num_processes].pid = pid;
    processes[num_processes].status = 1;

    num_processes++;
}

void remove_process(int pid) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = 0;
            break;
        }
    }
}

void print_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].status == 1) {
            printf("%s (%d)\n", processes[i].name, processes[i].pid);
        }
    }
}

int main() {
    char command[100];

    while (1) {
        printf("> ");
        fgets(command, 100, stdin);

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            char name[50];
            int pid;

            printf("Enter process name: ");
            fgets(name, 50, stdin);

            printf("Enter process ID: ");
            scanf("%d", &pid);

            add_process(name, pid);
        } else if (strcmp(command, "remove") == 0) {
            int pid;

            printf("Enter process ID: ");
            scanf("%d", &pid);

            remove_process(pid);
        } else if (strcmp(command, "list") == 0) {
            print_processes();
        }
    }

    return 0;
}