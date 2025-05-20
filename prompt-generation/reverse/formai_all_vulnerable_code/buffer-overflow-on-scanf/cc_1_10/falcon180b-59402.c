//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} Process;

void print_processes(Process *processes, int count) {
    printf("Process ID | Command\n");
    for (int i = 0; i < count; i++) {
        printf("%d | %s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int count = 0;

    while (true) {
        printf("Enter 'q' to quit or any other key to refresh process list:\n");
        char input[2];
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        count = 0;
        FILE *fp;
        char line[MAX_COMMAND_LENGTH];
        fp = popen("ps aux", "r");
        if (fp == NULL) {
            printf("Error: Failed to execute ps command.\n");
            return 1;
        }

        while (fgets(line, sizeof(line), fp)!= NULL) {
            if (count >= MAX_PROCESSES) {
                printf("Maximum number of processes reached.\n");
                break;
            }

            char *token = strtok(line, " ");
            int pid = atoi(token);

            strcpy(processes[count].command, "");

            while ((token = strtok(NULL, " "))!= NULL) {
                strcat(processes[count].command, token);
                strcat(processes[count].command, " ");
            }

            processes[count].pid = pid;
            count++;
        }

        pclose(fp);

        print_processes(processes, count);
    }

    return 0;
}