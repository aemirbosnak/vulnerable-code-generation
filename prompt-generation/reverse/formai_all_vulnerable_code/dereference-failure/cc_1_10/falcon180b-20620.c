//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME_LENGTH 20

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void add_process(int pid, char* name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }
    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LENGTH);
    num_processes++;
}

void remove_process(int pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            num_processes--;
            memmove(&processes[i], &processes[i+1], sizeof(process_t) * (num_processes - i));
            break;
        }
    }
}

void list_processes() {
    if (num_processes == 0) {
        printf("No processes running.\n");
        return;
    }
    printf("Processes running:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d: %s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    char input[80];
    while (1) {
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\r\n")] = '\0';
        if (strlen(input) == 0) {
            continue;
        }
        char* cmd = strtok(input, " ");
        if (strcmp(cmd, "add") == 0) {
            int pid = atoi(strtok(NULL, " "));
            char* name = strtok(NULL, " ");
            add_process(pid, name);
        } else if (strcmp(cmd, "remove") == 0) {
            int pid = atoi(strtok(NULL, " "));
            remove_process(pid);
        } else if (strcmp(cmd, "list") == 0) {
            list_processes();
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}