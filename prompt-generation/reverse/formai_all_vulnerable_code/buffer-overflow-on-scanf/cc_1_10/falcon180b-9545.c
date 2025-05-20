//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void add_process(int pid, char *name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LENGTH);
    processes[num_processes].pid = pid;
    num_processes++;
}

void remove_process(int pid) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            memmove(&processes[i], &processes[i + 1], sizeof(Process) * (num_processes - i - 1));
            num_processes--;
            break;
        }
    }
}

void print_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    char input[100];

    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        if (strcmp(input, "list") == 0) {
            print_processes();
        } else if (strcmp(input, "add") == 0) {
            int pid;
            char name[MAX_PROCESS_NAME_LENGTH];

            printf("Enter process ID: ");
            scanf("%d", &pid);
            printf("Enter process name: ");
            scanf("%s", name);

            add_process(pid, name);
        } else if (strcmp(input, "remove") == 0) {
            int pid;

            printf("Enter process ID: ");
            scanf("%d", &pid);

            remove_process(pid);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}