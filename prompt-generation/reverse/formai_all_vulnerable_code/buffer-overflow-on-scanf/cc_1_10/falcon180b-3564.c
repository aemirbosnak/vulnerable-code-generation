//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[20];
    int pid;
    int status;
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(char* name, int pid) {
    if (num_processes >= MAX_PROCESSES) {
        printf("No more space for processes.\n");
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
    char input[100];

    while (1) {
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "add") == 0) {
            char name[20];
            int pid;

            printf("Enter process name: ");
            fgets(name, sizeof(name), stdin);
            strtok(name, "\n");

            printf("Enter process ID: ");
            scanf("%d", &pid);

            add_process(name, pid);
        } else if (strcmp(input, "remove") == 0) {
            int pid;

            printf("Enter process ID: ");
            scanf("%d", &pid);

            remove_process(pid);
        } else if (strcmp(input, "list") == 0) {
            print_processes();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}