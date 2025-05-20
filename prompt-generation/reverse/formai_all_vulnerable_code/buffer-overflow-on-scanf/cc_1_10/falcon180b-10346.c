//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LEN 50

typedef struct {
    char name[MAX_PROCESS_NAME_LEN];
    int pid;
    int status;
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void add_process(char* name, int pid) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LEN);
    processes[num_processes].pid = pid;
    processes[num_processes].status = 0;

    num_processes++;
}

void update_process_status(int pid, int status) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            processes[i].status = status;
            break;
        }
    }
}

void display_processes() {
    printf("Processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s (%d) Status: %d\n", processes[i].name, processes[i].pid, processes[i].status);
    }
}

int main() {
    char input[100];
    int status;

    printf("Post-Apocalyptic Process Viewer\n");

    while (1) {
        printf("Enter command: ");
        fgets(input, 100, stdin);

        if (strcmp(input, "list") == 0) {
            display_processes();
        } else if (strcmp(input, "add") == 0) {
            scanf("%s", input);
            add_process(input, getpid());
        } else if (strcmp(input, "remove") == 0) {
            scanf("%d", &status);
            for (int i = 0; i < num_processes; i++) {
                if (processes[i].status == status) {
                    processes[i].status = 0;
                }
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}