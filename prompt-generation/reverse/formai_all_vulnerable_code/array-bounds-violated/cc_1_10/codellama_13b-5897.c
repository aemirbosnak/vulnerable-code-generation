//Code Llama-13B DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>

#define MAX_ARGS 10
#define MAX_CMD_LEN 100

int main(int argc, char **argv) {
    int status, fd, pid;
    char *cmd, *args[MAX_ARGS];
    char *logfile = "/var/log/admin.log";

    // Check if the command is provided
    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    // Get the command and arguments
    cmd = argv[1];
    for (int i = 2; i < argc; i++) {
        args[i - 2] = argv[i];
    }

    // Open the log file
    fd = open(logfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1) {
        printf("Error opening log file: %s\n", logfile);
        return 1;
    }

    // Execute the command
    pid = fork();
    if (pid == 0) {
        // Child process
        close(fd);
        execvp(cmd, args);
        printf("Error executing command: %s\n", cmd);
        exit(1);
    } else if (pid == -1) {
        // Error forking
        printf("Error forking process\n");
        return 1;
    } else {
        // Parent process
        waitpid(pid, &status, 0);
        if (status != 0) {
            // Error executing command
            printf("Error executing command: %s\n", cmd);
        } else {
            // Command executed successfully
            printf("Command executed successfully: %s\n", cmd);
        }
    }

    // Close the log file
    close(fd);

    return 0;
}