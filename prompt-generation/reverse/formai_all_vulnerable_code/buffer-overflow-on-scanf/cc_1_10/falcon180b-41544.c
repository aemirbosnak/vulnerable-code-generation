//Falcon-180B DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 20

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME];
    int status;
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(int pid, char* name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strcpy(processes[num_processes].name, name);
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

void list_processes() {
    int i;
    printf("Processes:\n");
    for (i = 0; i < num_processes; i++) {
        if (processes[i].status == 1) {
            printf("%d: %s\n", processes[i].pid, processes[i].name);
        }
    }
}

int main() {
    int choice, pid, status;
    char name[MAX_PROCESS_NAME];

    while (1) {
        printf("1. Add process\n2. Remove process\n3. List processes\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter process name: ");
            scanf("%s", name);
            printf("Enter process ID: ");
            scanf("%d", &pid);
            add_process(pid, name);
            break;

        case 2:
            printf("Enter process ID: ");
            scanf("%d", &pid);
            remove_process(pid);
            break;

        case 3:
            list_processes();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}