//Falcon-180B DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10
#define BUFFER_SIZE 1024

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    int num_args;
    int status;
    int i;

    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        num_args = 0;
        args[num_args] = strtok(command, " ");
        while (args[num_args]!= NULL) {
            num_args++;
            args[num_args] = strtok(NULL, " ");
        }

        pid_t pid = fork();
        if (pid == -1) {
            printf("Error forking process\n");
            exit(1);
        } else if (pid == 0) {
            if (num_args == 0) {
                printf("No command specified\n");
                exit(1);
            }

            char *file = args[0];
            int file_fd = open(file, O_RDONLY);
            if (file_fd == -1) {
                printf("Error opening file: %s\n", strerror(errno));
                exit(1);
            }

            char buffer[BUFFER_SIZE];
            while (read(file_fd, buffer, BUFFER_SIZE) > 0) {
                write(1, buffer, strlen(buffer));
            }

            close(file_fd);
            exit(0);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}