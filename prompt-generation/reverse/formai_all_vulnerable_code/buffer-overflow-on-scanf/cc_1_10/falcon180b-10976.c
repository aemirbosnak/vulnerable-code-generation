//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20

typedef struct process {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int status;
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void add_process(int pid, char* name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Cannot add more processes. Maximum limit reached.\n");
        return;
    }

    strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LENGTH);
    processes[num_processes].pid = pid;
    processes[num_processes].status = 0;

    num_processes++;
}

void remove_process(int pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = 1;
            num_processes--;
            break;
        }
    }
}

void print_processes() {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].status == 0) {
            printf("%d - %s\n", processes[i].pid, processes[i].name);
        }
    }
}

int main() {
    int choice, pid, status;
    char name[MAX_PROCESS_NAME_LENGTH];

    while (1) {
        printf("1. Add process\n2. Remove process\n3. Print processes\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter process ID: ");
                scanf("%d", &pid);
                printf("Enter process name: ");
                scanf("%s", name);
                add_process(pid, name);
                break;
            case 2:
                printf("Enter process ID to remove: ");
                scanf("%d", &pid);
                remove_process(pid);
                break;
            case 3:
                print_processes();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}