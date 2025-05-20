//FormAI DATASET v1.0 Category: System boot optimizer ; Style: irregular
/* 
   Welcome to the C System Boot Optimizer program. This program will optimize 
   your system boot speeds by optimizing the initialization process. 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    // Display program welcome message
    printf("Welcome to the C System Boot Optimizer program!\n");

    // Define variables
    int bootTime = 10000; // in milliseconds
    int initTime = 5000; // in milliseconds
    int totalTime = bootTime + initTime;

    // Display current boot and initialization times
    printf("Current boot time: %dms\n", bootTime);
    printf("Current initialization time: %dms\n", initTime);
    printf("Total time: %dms\n\n", totalTime);

    // Prompt user for optimization preference
    printf("Would you like to optimize boot time or initialization time?\n");
    printf("Type '1' for boot time or '2' for initialization time: ");
    int choice;
    scanf("%d", &choice);

    // Optimize boot time
    if (choice == 1) {

        // Generate random seed for optimization calculation
        srand(time(NULL));

        // Calculate new boot time by subtracting a random amount of milliseconds
        int randNum = rand() % 3000 + 1000; // generates random number between 1000 and 4000
        bootTime -= randNum;

        // Calculate new total time
        totalTime = bootTime + initTime;

        // Display optimized boot and initialization times
        printf("\nOptimized boot time: %dms\n", bootTime);
        printf("Current initialization time: %dms\n", initTime);
        printf("New total time: %dms\n", totalTime);
    }

    // Optimize initialization time
    else if (choice == 2) {

        // Generate random seed for optimization calculation
        srand(time(NULL));

        // Calculate new initialization time by subtracting a random amount of milliseconds
        int randNum = rand() % 2000 + 1000; // generates random number between 1000 and 3000
        initTime -= randNum;

        // Calculate new total time
        totalTime = bootTime + initTime;

        // Display optimized boot and initialization times
        printf("\nCurrent boot time: %dms\n", bootTime);
        printf("Optimized initialization time: %dms\n", initTime);
        printf("New total time: %dms\n", totalTime);
    }

    // Error message for invalid input
    else {
        printf("\nError: Invalid input. Please try again.");
    }

    // End of program message
    printf("\nThank you for using the C System Boot Optimizer program!");

    return 0;
}