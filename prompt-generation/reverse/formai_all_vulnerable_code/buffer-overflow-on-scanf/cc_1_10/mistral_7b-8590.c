//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PIPE_NAME "parent_child_pipe"

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int fd_parent_to_child[2];
    int fd_child_to_parent[2];
    pid_t pid;
    char input_string[100];
    int received_number;

    // Create parent-to-child pipe
    if (pipe(fd_parent_to_child) < 0) {
        error("pipe: parent to child");
    }

    // Create child-to-parent pipe
    if (pipe(fd_child_to_parent) < 0) {
        close(fd_parent_to_child[0]);
        close(fd_parent_to_child[1]);
        error("pipe: child to parent");
    }

    pid = fork();

    if (pid < 0) {
        error("fork");
    } else if (pid > 0) { // Parent process
        // Parent writes a string into the pipe
        printf("Parent writes a string:\n");
        scanf("%s", input_string);
        write(fd_parent_to_child[1], input_string, strlen(input_string) + 1);
        close(fd_parent_to_child[0]);
        close(fd_parent_to_child[1]);

        // Parent reads an integer from the pipe
        fd_parent_to_child[0] = fd_child_to_parent[1];
        read(fd_parent_to_child[0], &received_number, sizeof(int));
        close(fd_parent_to_child[0]);
        printf("Parent received number: %d\n", received_number);

    } else { // Child process
        // Child closes the unnecessary file descriptors
        close(fd_parent_to_child[1]);
        close(fd_child_to_parent[0]);

        // Child reads a string from the pipe
        read(fd_parent_to_child[0], input_string, sizeof(input_string));
        close(fd_parent_to_child[0]);

        // Child processes the string and sends the result as an integer
        int result = strlen(input_string);
        write(fd_child_to_parent[1], &result, sizeof(int));
        close(fd_child_to_parent[1]);
        printf("Child processed string: %s\n", input_string);
        printf("Child sent length: %d\n", result);
        exit(EXIT_SUCCESS);
    }

    unlink(PIPE_NAME);
    unlink(PIPE_NAME);

    return EXIT_SUCCESS;
}