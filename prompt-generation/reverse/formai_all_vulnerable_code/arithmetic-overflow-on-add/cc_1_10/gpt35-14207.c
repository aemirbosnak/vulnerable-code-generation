//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void checkMemory();
void printUsage(int usage);
void sleep(int seconds);

int main() {
    int availableMemory = 1000;
    int currentUsage = 0;

    printf("Starting C RAM Usage Monitor...\n");

    while (1) {
        // Simulate random memory usage
        srand(time(0));
        int randomNum = rand() % 101;
        currentUsage += randomNum;

        // Check if memory usage exceeds available memory
        if (currentUsage > availableMemory) {
            printf("Error: Memory usage has exceeded available memory!\n");
            break;
        }

        // Print current memory usage
        printUsage(currentUsage);

        // Check memory usage every 5 seconds
        sleep(5);
        checkMemory();
    }

    printf("Exiting C RAM Usage Monitor...\n");
    return 0;
}

void checkMemory() {
    int memoryCheck = rand() % 3;

    if (memoryCheck == 0) {
        printf("System is running low on memory.\n");
    } else {
        printf("Memory usage is in check.\n");
    }
}

void printUsage(int usage) {
    printf("Current Memory Usage: %d MB\n", usage);
}

void sleep(int seconds) {
    clock_t goalTime = seconds * CLOCKS_PER_SEC + clock();
    while (goalTime > clock());
}