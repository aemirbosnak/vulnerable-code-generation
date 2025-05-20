//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 10

void producer(int fd) {
    close(fd); // Close unused read end
    for (int i = 0; i < 10; i++) {
        write(fd, &i, sizeof(int));
        printf("Produced: %d\n", i);
        sleep(1); // Simulate work
    }
    int eof = -1; // Signal end of the data stream
    write(fd, &eof, sizeof(int));
    close(fd);
}

void consumer(int fd) {
    close(fd); // Close unused write end
    int number;
    while (1) {
        if (read(fd, &number, sizeof(int)) <= 0) {
            break; // Exit on read failure or EOF
        }
        if (number == -1) break; // End signal
        printf("Consumed: %d, Square: %d\n", number, number * number);
    }
    close(fd);
}

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent Process - Producer
        printf("Starting producer...\n");
        producer(pipefd[1]);
        wait(NULL); // Wait for child to finish
    } else {
        // Child Process - Consumer
        printf("Starting consumer...\n");
        consumer(pipefd[0]);
    }

    return 0;
}