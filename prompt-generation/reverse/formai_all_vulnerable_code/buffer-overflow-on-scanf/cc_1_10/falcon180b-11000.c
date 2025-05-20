//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
};

void print_processes(struct process processes[], int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("\nEnter 'q' to quit or 'r' to refresh process list:\n");
        char choice;
        scanf("%c", &choice);

        if (choice == 'q') {
            break;
        } else if (choice == 'r') {
            num_processes = 0;
            FILE *fp;
            char line[MAX_COMMAND_LENGTH];

            fp = popen("ps ax", "r");

            if (fp == NULL) {
                printf("Error: Failed to execute ps command.\n");
                exit(1);
            }

            while (fgets(line, MAX_COMMAND_LENGTH, fp)!= NULL) {
                int pid = atoi(line);
                char *command = strtok(line, " ");

                if (command!= NULL) {
                    strcpy(processes[num_processes].command, command);
                    processes[num_processes].pid = pid;
                    num_processes++;
                }
            }

            pclose(fp);
            print_processes(processes, num_processes);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}