//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("Enter command to search for processes or type 'q' to quit: ");
        char command[MAX_COMMAND_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "q") == 0) {
            break;
        }

        FILE *fp;
        char line[MAX_COMMAND_LENGTH];
        fp = popen(command, "r");

        if (fp == NULL) {
            printf("Error: Failed to execute command.\n");
            continue;
        }

        while (fgets(line, MAX_COMMAND_LENGTH, fp)!= NULL) {
            int pid = atoi(line);
            strcpy(processes[num_processes].command, command);
            processes[num_processes].pid = pid;
            num_processes++;
        }

        pclose(fp);
    }

    print_processes(processes, num_processes);

    return 0;
}