//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10

// Function prototypes
void rollDice(int numDice, int numSides, int rolls[]);
void printRolls(int rolls[], int numDice);
void printStatistics(int rolls[], int numDice);
void displayMenu();
int getUserInput(const char* prompt);

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    int numDice, numSides;
    int rolls[MAX_DICE];

    while (1) {
        displayMenu();
        int choice = getUserInput("Choose an option (1-6): ");
        
        switch (choice) {
            case 1:
                numDice = getUserInput("Enter the number of dice to roll (1-10): ");
                numSides = getUserInput("Enter the number of sides on the dice (4, 6, 8, 10, 12, 20): ");
                
                if (numDice < 1 || numDice > MAX_DICE || (numSides != 4 && numSides != 6 && numSides != 8 && numSides != 10 && numSides != 12 && numSides != 20)) {
                    printf("Invalid input. Please try again.\n");
                    break;
                }

                rollDice(numDice, numSides, rolls);
                printRolls(rolls, numDice);
                printStatistics(rolls, numDice);
                break;
            case 2:
                printf("Stay tuned for more features!\n");
                break;
            case 3:
                printf("Currently not available!\n");
                break;
            case 4:
                printf("Currently not available!\n");
                break;
            case 5:
                printf("Currently not available!\n");
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
    return 0;
}

// Function to roll the dice
void rollDice(int numDice, int numSides, int rolls[]) {
    for (int i = 0; i < numDice; i++) {
        rolls[i] = (rand() % numSides) + 1; // Roll the die
    }
}

// Function to print the rolls
void printRolls(int rolls[], int numDice) {
    printf("You rolled: ");
    for (int i = 0; i < numDice; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

// Function to calculate and print statistics
void printStatistics(int rolls[], int numDice) {
    int sum = 0;
    int min = rolls[0];
    int max = rolls[0];
    
    for (int i = 0; i < numDice; i++) {
        sum += rolls[i];
        if (rolls[i] < min) min = rolls[i];
        if (rolls[i] > max) max = rolls[i];
    }
    
    double average = (double)sum / numDice;

    printf("Statistics:\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
}

// Function to display a menu
void displayMenu() {
    printf("\n------ Dice Roller Menu ------\n");
    printf("1. Roll Dice\n");
    printf("2. Feature Placeholder\n");
    printf("3. Feature Placeholder\n");
    printf("4. Feature Placeholder\n");
    printf("5. Feature Placeholder\n");
    printf("6. Exit\n");
}

// Function to get user input
int getUserInput(const char* prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}