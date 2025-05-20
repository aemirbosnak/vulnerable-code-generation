//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <sys/stat.h>

#define FIFO_NAME "data_fifo"
#define NUM_PRODUCERS 5
#define NUM_DATA 20

void create_fifo() {
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
}

void clean_fifo() {
    unlink(FIFO_NAME);
}

void producer(int id) {
    int fd;
    double number;

    char fifo_path[30];
    sprintf(fifo_path, FIFO_NAME);

    fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("Producer: open");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_DATA; i++) {
        number = rand() % 100;  // Generate random number between 0-99
        write(fd, &number, sizeof(number));
        printf("Producer %d: Sent %.2f\n", id, number);
        sleep(1);  // Sleep for a while to simulate real-time data generation
    }

    close(fd);
}

void collector() {
    int fd;
    double number;
    double sum = 0.0, sum_squared = 0.0;
    int count = 0;

    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Collector: open");
        exit(EXIT_FAILURE);
    }

    while (count < NUM_PRODUCERS * NUM_DATA) {
        read(fd, &number, sizeof(number));
        sum += number;
        sum_squared += number * number;
        count++;
    }

    close(fd);

    double mean = sum / count;
    double variance = (sum_squared / count) - (mean * mean);
    double stddev = sqrt(variance);

    printf("Collector: Mean = %.2f, Standard Deviation = %.2f\n", mean, stddev);
}

int main() {
    srand(time(NULL));

    create_fifo();

    // Forking processes for producers
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        if (fork() == 0) {
            producer(i + 1);
            exit(0);  // End child process after producing data
        }
    }

    // Parent process will be the collector
    collector();

    // Wait for all producers to finish
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        wait(NULL);
    }

    clean_fifo(); // Clean up the FIFO file

    return 0;
}