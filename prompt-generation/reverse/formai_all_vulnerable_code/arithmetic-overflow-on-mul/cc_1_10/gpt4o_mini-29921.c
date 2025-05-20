//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 20
#define NUM_COUNT 10

void generate_numbers(int write_fd) {
    srand(time(NULL));
    for (int i = 0; i < NUM_COUNT; i++) {
        int num = rand() % 100; // Generate numbers 0-99
        write(write_fd, &num, sizeof(num));
        printf("Generated number: %d\n", num);
        sleep(1);  // Sleep for a second between generations
    }
    close(write_fd);
}

void calculate_square(int read_fd) {
    int num;
    while (read(read_fd, &num, sizeof(num)) > 0) {
        int square = num * num;
        printf("Received number: %d, Square: %d\n", num, square);
    }
    close(read_fd);
}

int main() {
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) { // Child Process
        close(pipefd[1]); // Close unused write end
        calculate_square(pipefd[0]);
        exit(EXIT_SUCCESS);
    } else { // Parent Process
        close(pipefd[0]); // Close unused read end
        generate_numbers(pipefd[1]);
        wait(NULL); // Wait for child process to finish
        printf("All computations done.\n");
        exit(EXIT_SUCCESS);
    }
}