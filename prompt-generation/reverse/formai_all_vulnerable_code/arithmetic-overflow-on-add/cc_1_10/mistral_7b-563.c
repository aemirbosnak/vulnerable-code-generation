//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

// Define constants
#define MAX_READ_SIZE 1024
#define STEP_COUNT_FILE "/tmp/step_count.txt"
#define SLEEP_TIME 1000

// Define struct for storing step data
typedef struct {
    time_t timestamp;
    int steps;
} StepData;

// Function to read step data from file
StepData readStepDataFromFile(int fd) {
    StepData data;
    read(fd, &data, sizeof(StepData));
    return data;
}

// Function to write step data to file
void writeStepDataToFile(int fd, StepData data) {
    write(fd, &data, sizeof(StepData));
}

// Function to open step count file for reading and writing
int openStepCountFile() {
    int fd = open(STEP_COUNT_FILE, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("Error opening step count file");
        exit(EXIT_FAILURE);
    }
    return fd;
}

// Function to increment step count and write to file
void incrementStepCount(int fd) {
    StepData currentData = readStepDataFromFile(fd);
    currentData.steps++;
    writeStepDataToFile(fd, currentData);
}

// Function to print current step count in retro ASCII style
void printStepCountInRetroStyle(int steps) {
    printf("\n");
    printf(" _____ _____ _____\n");
    printf("|S    |S    |S    |\n");
    printf("|_oOo_|_oOo_|_oOo_|\n");
    printf("|:::::|:::::|:::::|\n");
    printf("|_oo__|_oo__|_oo__|\n");
    printf("|    |    |    |\n");
    printf("|    |____|____|\n");
    printf("|    |  %d  |    |\n", steps);
    printf("|____|____|____|\n");
}

int main() {
    int fd;

    // Open step count file for reading and writing
    fd = openStepCountFile();

    // Initialize step count to 0
    StepData zeroData = {0, 0};
    writeStepDataToFile(fd, zeroData);

    while (1) {
        // Read current step count from file
        StepData currentData = readStepDataFromFile(fd);

        // Wait for a short period of time
        usleep(SLEEP_TIME);

        // Increment step count and write to file
        incrementStepCount(fd);

        // Print current step count in retro ASCII style
        printStepCountInRetroStyle(currentData.steps);
    }

    close(fd);
    return 0;
}