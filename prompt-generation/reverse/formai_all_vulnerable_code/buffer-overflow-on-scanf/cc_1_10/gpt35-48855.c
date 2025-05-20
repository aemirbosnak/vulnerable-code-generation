//FormAI DATASET v1.0 Category: Browser Plugin ; Style: innovative
#include <stdio.h>

// Define the function prototypes
void incrementCounter();
void displayCounter();

// Global variable to track counter
int counter = 0;

// Implementation of incrementCounter function
void incrementCounter() {
    counter++;
}

// Implementation of displayCounter function
void displayCounter() {
    printf("The current counter value is: %d\n", counter);
}

int main() {
    int choice;
    // Display the options to the user
    printf("Choose an option:\n");
    printf("1. Increment counter\n");
    printf("2. Display counter\n");
    printf("3. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Call incrementCounter function to increment the counter variable
                incrementCounter();
                printf("Counter incremented!\n");
                break;

            case 2:
                // Call displayCounter function to display the current counter value
                displayCounter();
                break;

            case 3:
                // Exit the program
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        // Display the options again
        printf("\nChoose an option:\n");
        printf("1. Increment counter\n");
        printf("2. Display counter\n");
        printf("3. Exit\n");
    }
    return 0;
}