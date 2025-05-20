//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int heart_rate = 0;
int step_count = 0;
int calories_burned = 0;

// Function to generate random integer between two values
int randnum(int min, int max) {
    return (rand() % (max - min)) + min;
}

int main() {
    // Set seed for random number generator
    srand(time(NULL));

    printf("Welcome to the C Fitness Tracker!\n");
    printf("Press 'h' to log heart rate, 's' to log steps, 'c' to log calories burned, or 'q' to quit.\n");

    // Loop through options until user quits
    char option = ' ';
    while (option != 'q') {
        printf("\nEnter your selection: ");
        scanf(" %c", &option);

        switch(option) {
            case 'h':
                heart_rate = randnum(60, 120); // generate random heart rate
                printf("Your heart rate is %d bpm\n", heart_rate);
                break;
            case 's':
                step_count += randnum(1000, 5000); // generate random step count
                printf("You have taken %d steps today\n", step_count);
                break;
            case 'c':
                calories_burned += randnum(100, 500); // generate random calorie count
                printf("You have burned %d calories today\n", calories_burned);
                break;
            case 'q':
                printf("Thank you for using the C Fitness Tracker. Keep on moving!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}