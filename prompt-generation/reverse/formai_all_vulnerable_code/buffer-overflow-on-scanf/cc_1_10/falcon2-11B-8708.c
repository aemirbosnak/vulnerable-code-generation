//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid;
    char command[100];
    FILE *pipe;
    int status;

    // Prompt user to enter a command
    printf("Enter a command to monitor RAM usage: ");
    fflush(stdout);
    scanf("%s", command);

    // Fork a child process to run the command
    pid = fork();

    // If parent process, wait for child process to complete
    if (pid == 0) {
        // Redirect stdin, stdout, and stderr to /dev/null
        dup2(STDIN_FILENO, STDIN_FILENO);
        dup2(STDOUT_FILENO, STDOUT_FILENO);
        dup2(STDERR_FILENO, STDERR_FILENO);

        // Run the command
        execlp("ps", "ps", "-o", "pcpu,rss", (char*) NULL);
    } else if (pid > 0) {
        // Create a pipe to communicate with the child process
        pipe = popen(command, "r");

        // Wait for the child process to complete
        waitpid(pid, &status, 0);

        // Check if the pipe is still open
        if (pipe) {
            // Close the pipe
            pclose(pipe);

            // Print the output from the command
            printf("%s", command);
        } else {
            // Print an error message if the pipe is not open
            printf("Error: Unable to run command\n");
        }
    }

    // Clean up the pipe
    close(pipe);

    return 0;
}