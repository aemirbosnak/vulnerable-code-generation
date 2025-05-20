//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void clearBuffer();
int getValidIntInput();
void rollDice(int sides, int times);
void displayMenu();

int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice, sides, times;

    do {
        displayMenu();
        choice = getValidIntInput();

        switch (choice) {
            case 1:
                printf("Enter the number of sides on the dice (e.g., 6, 20): ");
                sides = getValidIntInput();
                printf("Enter the number of times to roll: ");
                times = getValidIntInput();
                rollDice(sides, times);
                break;
            case 2:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}

// Function to display menu options
void displayMenu() {
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll a dice\n");
    printf("2. Exit\n");
    printf("Please select an option: ");
}

// Function to roll dice and display results
void rollDice(int sides, int times) {
    printf("Rolling a %d-sided dice %d time(s):\n", sides, times);
    for (int i = 0; i < times; i++) {
        int result = (rand() % sides) + 1; // Generate a random result between 1 and sides
        printf("Roll %d: %d\n", i + 1, result);
    }
}

// Function to get a valid integer input from user
int getValidIntInput() {
    int num;
    while (1) {
        if (scanf("%d", &num) != 1) {
            printf("Invalid input! Please enter a valid integer.\n");
            clearBuffer();
        } else {
            clearBuffer();
            if (num <= 0) {
                printf("Please enter a positive integer.\n");
            } else {
                return num;
            }
        }
    }
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n'); // Discard invalid input
}