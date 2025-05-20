//GEMINI-pro DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFSIZE 1024

// Function to read a line from a file
char *readline(int fd) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    do {
        nread = getline(&line, &len, fd);
    } while (nread != -1 && line[nread - 1] == '\n');

    return line;
}

// Function to execute a command
int execute_command(char *command) {
    int status;
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        // Child process
        execlp("/bin/sh", "sh", "-c", command, NULL);
        _exit(127);
    } else if (pid > 0) {
        // Parent process
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    } else {
        // Error
        perror("fork");
        return -1;
    }
}

// Function to read a configuration file and execute the commands
int read_config(char *filename) {
    int fd, ret;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    while ((line = readline(fd)) != NULL) {
        ret = execute_command(line);
        if (ret != 0) {
            fprintf(stderr, "Error executing command: %s\n", line);
            close(fd);
            return ret;
        }
    }

    close(fd);
    return 0;
}

int main(int argc, char *argv[]) {
    int ret;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <config file>\n", argv[0]);
        return -1;
    }

    ret = read_config(argv[1]);
    if (ret != 0) {
        fprintf(stderr, "Error reading config file: %s\n", argv[1]);
        return ret;
    }

    return 0;
}