//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define PIPE_SIZE 1024

void generate_random_number(int *number) {
    srand(time(NULL));
    *number = rand() % 10 + 1;
}

int main() {
    int parent_fd[2], child_fd[2], number;

    if (pipe(parent_fd) < 0 || pipe(child_fd) < 0) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (child_pid > 0) {
        close(parent_fd[0]);
        close(child_fd[0]);

        generate_random_number(&number);
        write(parent_fd[1], &number, sizeof(int));
        close(parent_fd[1]);

        wait(NULL);
    } else {
        close(parent_fd[1]);
        close(child_fd[1]);

        read(child_fd[0], &number, sizeof(int));
        close(child_fd[0]);

        int result = number * 2;
        printf("Child process result: %d\n", result);
        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}