//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 10

void producer(int write_fd) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("Producer: Producing %d\n", i);
        write(write_fd, &i, sizeof(i));
        sleep(1);  // Simulate time delay in production
    }
    close(write_fd);  // Close write end of pipe when done
}

void consumer(int read_fd) {
    int value;
    int sum = 0;
    
    while (read(read_fd, &value, sizeof(value)) > 0) {
        printf("Consumer: Consumed %d\n", value);
        sum += value;
    }
    
    printf("Consumer: Total sum = %d\n", sum);
    close(read_fd);  // Close read end of pipe after reading all values
}

int main() {
    int pipefd[2];  // Pipe file descriptors
    pid_t pid;

    if (pipe(pipefd) == -1) {  // Creating the pipe
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();  // Forking the process
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process (Consumer)
        close(pipefd[1]);  // Close unused write end
        consumer(pipefd[0]);  // Pass read end to consumer
    } else {  // Parent process (Producer)
        close(pipefd[0]);  // Close unused read end
        producer(pipefd[1]);  // Pass write end to producer
        wait(NULL);  // Wait for child process to finish
    }

    return 0;
}