//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define BUFFER_SIZE 10

void producer(int write_fd) {
    srand(time(NULL)); // Seed for randomness
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        int fruit = rand() % 100; // Produce random "fruit" between 0 and 99
        write(write_fd, &fruit, sizeof(fruit)); // Send fruit to consumer
        printf("Producer: Produced fruit: %d\n", fruit);
        sleep(1); // Simulate time taken to produce
    }
    close(write_fd); // Close write end after sending all data
    printf("Producer: Finished producing fruits.\n");
}

void consumer(int read_fd) {
    int fruit;
    int collected_fruits[BUFFER_SIZE];
    int count = 0;
    
    while (read(read_fd, &fruit, sizeof(fruit)) > 0) { // Read until EOF
        collected_fruits[count++] = fruit; // Collect the fruit
        printf("Consumer: Collected fruit: %d\n", fruit);
        sleep(2); // Simulate time taken to consume
    }
    
    printf("Consumer: Finished collecting fruits. Total fruits collected: %d\n", count);
    for (int i = 0; i < count; ++i) {
        printf("Fruits collected: %d\n", collected_fruits[i]);
    }
    close(read_fd); // Close read end
}

int main() {
    int pipe_fd[2];
    
    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid_t pid = fork();
    
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // In child process (Consumer)
        close(pipe_fd[1]); // Close unused write end
        consumer(pipe_fd[0]); // Call the consumer function
    } else {
        // In parent process (Producer)
        close(pipe_fd[0]); // Close unused read end
        producer(pipe_fd[1]); // Call the producer function
        wait(NULL); // Wait for the child process to finish
    }
    
    printf("Main: All processes finished executing.\n");
    return 0;
}