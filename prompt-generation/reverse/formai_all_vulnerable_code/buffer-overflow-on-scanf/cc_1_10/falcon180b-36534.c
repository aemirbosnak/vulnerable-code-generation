//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

void print_processes(process_t processes[], int num_processes) {
    printf("Process ID   Command\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%5d %s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (num_processes < MAX_PROCESSES) {
        pid_t pid = fork();

        if (pid == -1) {
            printf("Error forking\n");
            exit(1);
        } else if (pid == 0) {
            char command[MAX_COMMAND_LENGTH];
            printf("Enter command: ");
            scanf("%s", command);
            processes[num_processes].pid = getpid();
            strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH - 1);
            processes[num_processes].command[MAX_COMMAND_LENGTH - 1] = '\0';
            exit(0);
        } else {
            int status;
            waitpid(pid, &status, WUNTRACED);
            processes[num_processes].pid = pid;
            strncpy(processes[num_processes].command, "Unknown", MAX_COMMAND_LENGTH - 1);
            processes[num_processes].command[MAX_COMMAND_LENGTH - 1] = '\0';
            processes[num_processes].status = status;
            num_processes++;
        }
    }

    print_processes(processes, num_processes);

    return 0;
}