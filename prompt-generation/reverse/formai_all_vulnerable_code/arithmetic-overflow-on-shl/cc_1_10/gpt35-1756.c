//FormAI DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_BITS 32 // Maximum number of bits to be operated on
#define MAX_RANDOM_NUM 10000 // Maximum value of random number to be generated

// Function to generate random number between 0 and MAX_RANDOM_NUM
int generateRandomNumber() {
    return rand() % MAX_RANDOM_NUM;
}

// Function to set a bit in the given position to 1
void setBitToOne(int *number, int position) {
    *number |= 1 << position;
}

// Function to set a bit in the given position to 0
void setBitToZero(int *number, int position) {
    *number &= ~(1 << position);
}

// Function to get the value of a bit in the given position
int getBitValue(int number, int position) {
    return (number >> position) & 1;
}

// Function to perform a random bitwise operation on a given number
int performRandomBitwiseOperation(int number) {
    int operation = rand() % 3; // Generate random number between 0 and 2 to choose bitwise operation
    
    switch(operation) {
        case 0:
            // Bitwise OR operation
            number |= generateRandomNumber();
            break;
        case 1:
            // Bitwise AND operation
            number &= generateRandomNumber();
            break;
        case 2:
            // Bitwise XOR operation
            number ^= generateRandomNumber();
            break;
    }
    
    return number;
}

// Signal handler to handle SIGUSR1 signal
void signalHandler(int signum) {
    printf("Caught signal SIGUSR1\n");
}

// Function to run the asynchronous task that generates random number and performs random bitwise operations on it
void* asyncTask(void *arg) {
    // Register signal handler for SIGUSR1 signal
    signal(SIGUSR1, signalHandler);
    
    printf("Async Task started\n");
    int number = generateRandomNumber();
    printf("Initial number: %d\n", number);
    
    while(true) {
        sleep(1);
        number = performRandomBitwiseOperation(number);
        printf("Number after bitwise operation: %d\n", number);
    }
}

int main() {
    srand(time(NULL));
    int number = generateRandomNumber();
    int position = rand() % MAX_BITS; // Choose random bit position to set to 1

    printf("Initial number: %d\n", number);
    printf("Setting bit at position %d to 1\n", position);
    setBitToOne(&number, position);
    printf("Number after setting bit to 1: %d\n", number);

    position = rand() % MAX_BITS; // Choose random bit position to set to 0
    printf("Setting bit at position %d to 0\n", position);
    setBitToZero(&number, position);
    printf("Number after setting bit to 0: %d\n", number);

    printf("Value of bit at position %d: %d\n", position, getBitValue(number, position));

    // Create new thread to run the asynchronous task
    pthread_t thread;
    if(pthread_create(&thread, NULL, asyncTask, NULL) != 0) {
        printf("Error creating thread\n");
        exit(1);
    }

    // Wait for user input to send SIGUSR1 signal to the running thread
    printf("Press ENTER to send signal to the async task\n");
    getchar();
    pthread_kill(thread, SIGUSR1);

    return 0;
}