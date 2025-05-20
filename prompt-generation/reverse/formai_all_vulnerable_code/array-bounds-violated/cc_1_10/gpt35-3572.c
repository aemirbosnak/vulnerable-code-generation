//FormAI DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 10

pid_t processes[MAX_PROCESSES]; // array to hold child processes
int num_processes = 0; // current number of child processes

// signal handler for SIGINT
void sigint_handler(int signum) {
    printf("Received SIGINT, killing child processes...\n");
    for (int i = 0; i < num_processes; i++) {
        kill(processes[i], SIGTERM); // terminate child processes
    }
    exit(0);
}

// function to execute a command asynchronously
pid_t execute_command(char *command) {
    pid_t pid = fork(); // create new process
    if (pid == 0) {
        // child process
        printf("Executing command: %s\n", command);
        system(command); // execute command
        exit(0); // exit child process
    } else if (pid < 0) {
        // fork failed
        perror("fork");
    } else {
        // parent process
        processes[num_processes++] = pid; // add pid to list of child processes
        printf("Started process with PID: %d\n", pid);
    }
    return pid;
}

int main(int argc, char *argv[]) {
    signal(SIGINT, sigint_handler); // register signal handler for SIGINT

    // loop to read commands from stdin and execute them asynchronously
    char command[256];
    while (1) {
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break; // exit loop on EOF or error
        }
        if (num_processes == MAX_PROCESSES) {
            printf("Maximum number of child processes reached!\n");
            continue;
        }
        // replace newline with null character
        if (command[strlen(command)-1] == '\n') {
            command[strlen(command)-1] = '\0';
        }

        pid_t pid = execute_command(command); // execute command
        if (pid < 0) {
            printf("Failed to execute command: %s\n", command);
            continue;
        }
    }

    // wait for all child processes to terminate
    for (int i = 0; i < num_processes; i++) {
        waitpid(processes[i], NULL, 0);
    }

    return 0;
}