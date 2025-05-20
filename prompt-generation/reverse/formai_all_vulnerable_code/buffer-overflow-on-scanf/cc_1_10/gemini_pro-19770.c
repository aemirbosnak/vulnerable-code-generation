//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: irregular
// Unorthodox IPC Conundrum

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Pipe-Within-Pipe: A Culinary Delight
int main() {
    int pipe1[2];
    int pipe2[2];

    // Pipeception!
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) return 1;

    // Summon Junior to Orchestrate the Symphony
    pid_t child = fork();

    if (child == -1) return 1; // Exiting on Failure
    if (child == 0) {
        // The Junior's Script
        while (1) {
            // Gathering Orders from the Pipe Maestro
            char msg[100];
            read(pipe1[0], msg, sizeof(msg));

            // Culinary Magic! (Simulating Message Processing)
            sleep(1);

            // Sending Results Back to the Pipe Conductor
            write(pipe2[1], msg, sizeof(msg));
        }
    }

    // The Senior's Grand Design
    while (1) {
        // Gathering Commands from the Command Line
        char command[100];
        printf("> ");
        scanf("%s", command);

        // Issuing Commands to Junior via Pipe
        write(pipe1[1], command, sizeof(command));

        // Patiently Awaiting Junior's Response
        char result[100];
        read(pipe2[0], result, sizeof(result));

        // Unraveling Junior's Culinary Masterpiece
        printf("%s\n", result);
    }
    return 0;
}