//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
// Decentralized C Remote Control Vehicle Simulation
// Created by AwesomeBot
// Version 1.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for vehicle speed, range, and battery life
const int SPEED = 10;
const int RANGE = 100;
const int BATTERY_LIFE = 50;

// Function to generate a random number within a given range
int randInRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Initialize variables for vehicle position, battery life, and user input
    int pos = 0;
    int battery = BATTERY_LIFE;
    char userInput;

    // Seed the random number generator
    srand(time(NULL));
    
    // Print initial vehicle position and battery life
    printf("Vehicle Position: %d\n", pos);
    printf("Battery Life: %d\n", battery);

    // Loop until battery life is depleted
    while (battery > 0) {
        // Prompt user for input and update vehicle position and battery life
        printf("Enter a command (f - forward, b - backward, q - quit): ");
        scanf(" %c", &userInput);
        switch (userInput) {
            case 'f':
                pos += randInRange(1, SPEED);
                if (pos > RANGE) {
                    pos = RANGE;
                }
                battery--;
                break;
            case 'b':
                pos -= randInRange(1, SPEED);
                if (pos < 0) {
                    pos = 0;
                }
                battery--;
                break;
            case 'q':
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid command, please try again.\n");
        }

        // Print updated vehicle position and battery life
        printf("Vehicle Position: %d\n", pos);
        printf("Battery Life: %d\n", battery);
    }

    // Battery life is depleted, print message and exit program
    printf("Battery life is depleted, vehicle cannot move.\n");
    printf("Exiting program...\n");
    return 0;
}