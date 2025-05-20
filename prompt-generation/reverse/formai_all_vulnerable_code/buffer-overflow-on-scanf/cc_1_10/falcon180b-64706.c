//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 256
#define TRUE 1
#define FALSE 0

void main() {
    int fd_parent, fd_child;
    char buffer[BUFFER_SIZE];
    pid_t child_pid;

    fd_parent = open("parent_pipe", O_WRONLY);
    if (fd_parent == -1) {
        printf("Error opening parent pipe\n");
        exit(1);
    }

    child_pid = fork();

    if (child_pid == -1) {
        printf("Error forking\n");
        exit(2);
    }

    if (child_pid == 0) {
        // Child process
        close(fd_parent);
        fd_child = open("child_pipe", O_RDONLY);
        if (fd_child == -1) {
            printf("Error opening child pipe\n");
            exit(3);
        }

        while (TRUE) {
            memset(buffer, 0, BUFFER_SIZE);
            read(fd_child, buffer, BUFFER_SIZE);
            printf("Child received: %s\n", buffer);
        }

        close(fd_child);
        exit(0);
    } else {
        // Parent process
        close(fd_parent);
        fd_parent = open("parent_pipe", O_RDONLY);
        if (fd_parent == -1) {
            printf("Error opening parent pipe\n");
            exit(4);
        }

        while (TRUE) {
            printf("Enter message to send to child: ");
            scanf("%s", buffer);
            write(fd_parent, buffer, strlen(buffer));
        }

        close(fd_parent);
        wait(NULL);
        exit(0);
    }
}