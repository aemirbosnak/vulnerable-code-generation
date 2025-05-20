//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

int main() {
    int num_processes = 0;
    int process_ids[MAX_PROCESSES];
    char command_strings[MAX_PROCESSES][MAX_COMMAND_LENGTH];
    char input_buffer[1024];
    int input_length;
    pid_t child_pid;

    // initialize signal handler
    signal(SIGCHLD, SIG_IGN);

    while (1) {
        printf("\nEnter a command to run in the background (or type 'q' to quit):\n");
        fgets(input_buffer, sizeof(input_buffer), stdin);
        input_length = strlen(input_buffer);
        if (input_buffer[input_length - 1] == '\n') {
            input_buffer[--input_length] = '\0';
        }

        if (strcmp(input_buffer, "q") == 0) {
            break;
        }

        if (num_processes >= MAX_PROCESSES) {
            printf("Maximum number of processes reached.\n");
            continue;
        }

        child_pid = fork();

        if (child_pid == 0) {
            // child process
            strcpy(command_strings[num_processes], input_buffer);
            execlp("/bin/sh", "sh", "-c", input_buffer, NULL);
            perror("execlp");
            exit(1);
        } else if (child_pid < 0) {
            // error forking process
            perror("fork");
        } else {
            // parent process
            process_ids[num_processes] = child_pid;
            num_processes++;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        wait(NULL);
    }

    return 0;
}