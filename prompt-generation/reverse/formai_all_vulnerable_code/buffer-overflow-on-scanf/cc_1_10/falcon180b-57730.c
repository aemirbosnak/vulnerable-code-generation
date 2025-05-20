//Falcon-180B DATASET v1.0 Category: System administration ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 20

// Process structure
typedef struct {
    char name[MAX_PROCESS_NAME];
    int pid;
    int status;
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

// Function to add a new process
void add_process(char *name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    strcpy(processes[num_processes].name, name);
    processes[num_processes].pid = num_processes + 1;
    processes[num_processes].status = 0;

    num_processes++;
}

// Function to remove a process by PID
void remove_process(int pid) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = 1;
            break;
        }
    }
}

// Function to list all processes
void list_processes() {
    int i;

    printf("Processes:\n");
    for (i = 0; i < num_processes; i++) {
        if (processes[i].status == 0) {
            printf("%s (PID %d)\n", processes[i].name, processes[i].pid);
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add process\n2. Remove process\n3. List processes\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter process name: ");
                scanf("%s", processes[num_processes - 1].name);
                break;
            case 2:
                printf("Enter PID: ");
                scanf("%d", &processes[num_processes - 1].pid);
                break;
            case 3:
                list_processes();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}