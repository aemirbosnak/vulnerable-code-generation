//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
};

void print_processes(struct process *processes, int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command to search for processes or type 'exit' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        FILE *fp;
        char line[MAX_COMMAND_LENGTH];
        fp = popen(input, "r");
        if (fp == NULL) {
            printf("Error: Failed to run command.\n");
            continue;
        }

        while (fgets(line, MAX_COMMAND_LENGTH, fp)!= NULL) {
            int pid = atoi(line);
            if (num_processes >= MAX_PROCESSES) {
                printf("Error: Maximum number of processes reached.\n");
                break;
            }
            processes[num_processes].pid = pid;
            strncpy(processes[num_processes].command, input, MAX_COMMAND_LENGTH - 1);
            num_processes++;
        }

        pclose(fp);
    }

    print_processes(processes, num_processes);

    return 0;
}