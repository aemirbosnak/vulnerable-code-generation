//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define PIPE_SIZE 1024

void generate_random_numbers(int fd[2]) {
    int random_numbers[5];
    int i;

    for (i = 0; i < 5; i++) {
        random_numbers[i] = rand() % 10;
        write(fd[1], &random_numbers[i], sizeof(int));
    }

    close(fd[0]);
    close(fd[1]);
}

void receive_and_process_numbers(int fd[2]) {
    int sum = 0, product = 1, i;
    int received_number;

    close(fd[1]);

    for (i = 0; i < 5; i++) {
        read(fd[0], &received_number, sizeof(int));
        sum += received_number;
        product *= received_number;
    }

    printf("Sum: %d, Product: %d\n", sum, product);

    close(fd[0]);
}

int main() {
    int fd[2];
    pid_t child_pid;

    if (pipe(fd) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    child_pid = fork();

    if (child_pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid > 0) { // Parent process
        generate_random_numbers(fd);
    } else { // Child process
        receive_and_process_numbers(fd);
    }

    wait(NULL);

    close(fd[0]);
    close(fd[1]);

    return EXIT_SUCCESS;
}