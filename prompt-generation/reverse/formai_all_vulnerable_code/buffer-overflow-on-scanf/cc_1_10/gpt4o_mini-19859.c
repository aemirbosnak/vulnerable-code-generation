//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_FACES 20

void printDice(int rolls[], int numRolls);
void rollDice(int rolls[], int numDice, int numFaces);
void displayMenu();
int getValidInput(char* prompt, int min, int max);
void clearBuffer();

int main() {
    srand(time(NULL));

    while (1) {
        displayMenu();
        
        int numDice = getValidInput("Enter the number of dice to roll (1-10): ", 1, MAX_DICE);
        int numFaces = getValidInput("Enter the number of faces per die (2-20): ", 2, MAX_FACES);
        
        int rolls[MAX_DICE];
        rollDice(rolls, numDice, numFaces);
        printDice(rolls, numDice);
        
        char choice;
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'n' || choice == 'N') {
            printf("Thank you for using the Dice Roller. Goodbye!\n");
            break;
        }
        clearBuffer();
    }

    return 0;
}

void displayMenu() {
    printf("\n===================\n");
    printf("   Dice Roller     \n");
    printf("===================\n");
    printf("Welcome to the Dice Roller! Roll dice to your heart's content.\n");
}

int getValidInput(char* prompt, int min, int max) {
    int input;

    while (1) {
        printf("%s", prompt);
        scanf("%d", &input);
        
        if (input >= min && input <= max) {
            return input;
        } else {
            printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
        }
        clearBuffer();
    }
}

void rollDice(int rolls[], int numDice, int numFaces) {
    for (int i = 0; i < numDice; i++) {
        rolls[i] = (rand() % numFaces) + 1; // Roll the die
    }
}

void printDice(int rolls[], int numRolls) {
    printf("\nYou rolled the following dice:\n");
    for (int i = 0; i < numRolls; i++) {
        printf("Die %d: %d\n", i + 1, rolls[i]);
    }
    printf("===================\n");
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}