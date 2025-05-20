//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define BUFFER_SIZE 10
#define NUM_COUNT 5

void generate_random_numbers(int fd) {
    for (int i = 0; i < NUM_COUNT; i++) {
        int num = rand() % 100; // Generate random number between 0 and 99
        write(fd, &num, sizeof(num)); // Send random number to child
        printf("Parent: Sent number %d\n", num);
        sleep(1); // Sleep for a second to simulate time taken to generate
    }
    int end_signal = -1; // Signal end of data
    write(fd, &end_signal, sizeof(end_signal));
}

void calculate_squares(int fd) {
    int num;
    while (1) {
        read(fd, &num, sizeof(num)); // Read number from parent
        if (num == -1) { // Check for end signal
            printf("Child: Received end signal. Exiting...\n");
            break;
        }
        printf("Child: Received number %d, square is %d\n", num, num * num);
    }
}

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {  // Child process
        close(pipefd[1]); // Close write end
        calculate_squares(pipefd[0]);
        close(pipefd[0]); // Close read end
        exit(EXIT_SUCCESS);
    } else {  // Parent process
        close(pipefd[0]); // Close read end
        srand(time(NULL)); // Seed random number generator
        generate_random_numbers(pipefd[1]);
        close(pipefd[1]); // Close write end
        wait(NULL); // Wait for child to finish
        printf("Parent: Child process finished. Exiting...\n");
    }

    return 0;
}