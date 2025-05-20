//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 20
#define NUM_COUNT 10

void create_fifo() {
    // Create a named pipe (FIFO)
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
}

void writer_process() {
    int fd;
    int numbers[NUM_COUNT];

    // Open the FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open writer");
        exit(EXIT_FAILURE);
    }

    // Generate random numbers and write to FIFO
    srand(time(NULL));
    for (int i = 0; i < NUM_COUNT; i++) {
        numbers[i] = rand() % 100; // Random numbers between 0-99
        if (write(fd, &numbers[i], sizeof(numbers[i])) == -1) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }
        printf("Writer: wrote %d\n", numbers[i]);
    }

    // Close the FIFO
    close(fd);
}

void reader_process() {
    int fd;
    int number;
    int sum = 0;

    // Open the FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open reader");
        exit(EXIT_FAILURE);
    }

    // Read from FIFO and calculate sum
    for (int i = 0; i < NUM_COUNT; i++) {
        if (read(fd, &number, sizeof(number)) == -1) {
            perror("read");
            close(fd);
            exit(EXIT_FAILURE);
        }
        printf("Reader: read %d\n", number);
        sum += number;
    }

    printf("Total sum of numbers: %d\n", sum);
    // Close the FIFO
    close(fd);
}

int main() {
    create_fifo(); // Create the FIFO before forking

    pid_t pid = fork(); // Fork the process

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process - Writer
        writer_process();
    } else {
        // Parent process - Reader
        sleep(1); // Ensure writer runs first
        reader_process();

        // Parent process waits for child to finish
        wait(NULL); // Optional, but good practice
        
        // Remove the FIFO after usage
        unlink(FIFO_NAME);
    }

    return 0;
}