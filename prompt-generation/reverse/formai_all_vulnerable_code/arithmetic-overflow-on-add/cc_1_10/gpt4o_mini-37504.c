//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

#define FIFO_NAME "my_fifo"
#define MAX_RANDOM 100
#define ITEMS_TO_PRODUCE 20

void create_fifo() {
    // Create the FIFO if it doesn't exist
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("Failed to create FIFO");
        exit(EXIT_FAILURE);
    }
}

void producer() {
    // Open the FIFO for writing
    int fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Producer: Failed to open FIFO for writing");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL)); // Seed for random number generation

    for (int i = 0; i < ITEMS_TO_PRODUCE; i++) {
        int num = rand() % MAX_RANDOM; // Generate random number
        write(fd, &num, sizeof(num));   // Write to FIFO
        printf("Producer: Produced %d\n", num);
        sleep(1); // Simulate time delay for producing
    }

    close(fd);
    printf("Producer: Finished producing!\n");
}

void consumer() {
    // Open the FIFO for reading
    int fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Consumer: Failed to open FIFO for reading");
        exit(EXIT_FAILURE);
    }

    int num;
    int total = 0;

    while (read(fd, &num, sizeof(num)) > 0) {
        total += num; // Sum up the received numbers
        printf("Consumer: Consumed %d; Current Total: %d\n", num, total);
    }

    close(fd);
    printf("Consumer: Finished consuming! Total Sum: %d\n", total);
}

int main() {
    create_fifo();

    // Forking the processes
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process acts as producer
        producer();
        wait(NULL); // Wait for the child to finish
    } else {
        // Child process acts as consumer
        consumer();
    }

    // Cleanup: Remove the FIFO
    unlink(FIFO_NAME);

    return 0;
}