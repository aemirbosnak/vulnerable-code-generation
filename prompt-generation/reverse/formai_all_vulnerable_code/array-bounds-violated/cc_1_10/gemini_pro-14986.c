//GEMINI-pro DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

// Define the maximum size of the command buffer.
#define MAX_CMD_SIZE 1024

// Define the maximum number of arguments in a command.
#define MAX_ARGS 32

// Define the maximum number of environment variables.
#define MAX_ENV 1024

// Declare the main function.
int main(int argc, char *argv[]) {
    // Check if the number of arguments is valid.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arguments]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the command and arguments from the command line.
    char *cmd = argv[1];
    char *args[MAX_ARGS];
    for (int i = 2; i < argc; i++) {
        args[i - 2] = argv[i];
    }

    // Set the environment variables.
    char *env[MAX_ENV];
    for (int i = 0; i < MAX_ENV; i++) {
        env[i] = NULL;
    }

    // fork() creates a new process.
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // The child process executes the command.
    if (pid == 0) {
        if (execve(cmd, args, env) < 0) {
            fprintf(stderr, "execve() failed: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }
    }

    // The parent process waits for the child process to finish.
    int status;
    if (waitpid(pid, &status, 0) < 0) {
        fprintf(stderr, "waitpid() failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Check if the child process exited successfully.
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}