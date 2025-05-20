//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_OPERAND 50

// Function prototypes
void displayMenu();
int generateRandomOperation();
void performOperation(int operand1, int operand2, int operation);
void memoryChallenge(int operation);
void countdown(int seconds);
void clearBuffer();

int main() {
    srand(time(0)); // Seed for random number generation
    int choice;

    do {
        displayMenu();
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the input buffer

        switch (choice) {
            case 1: {
                int operand1 = rand() % MAX_OPERAND;
                int operand2 = rand() % MAX_OPERAND;
                int operation = generateRandomOperation();
                printf("Performing Operation %d: %d\n", operation, operand1);
                performOperation(operand1, operand2, operation);
                break;
            }
            case 2: {
                int operation = generateRandomOperation();
                memoryChallenge(operation);
                break;
            }
            case 3:
                printf("Countdown to the next adventure: \n");
                countdown(5); // Give the player a 5 second countdown
                break;
            case 4:
                printf("Goodbye, fellow adventurer!\n");
                break;
            default:
                printf("Invalid option! Please choose a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n--- Welcome to the Mind-Bending Arithmetic Adventure ---\n");
    printf("1. Perform a random arithmetic operation\n");
    printf("2. Memory Challenge: Remember the result!\n");
    printf("3. Countdown Challenge\n");
    printf("4. Exit the program\n");
}

int generateRandomOperation() {
    return rand() % 4; // Returns a number from 0 to 3 representing different operations (+, -, *, /)
}

void performOperation(int operand1, int operand2, int operation) {
    int result;
    switch (operation) {
        case 0: // Addition
            result = operand1 + operand2;
            printf("Operation: %d + %d = %d\n", operand1, operand2, result);
            break;
        case 1: // Subtraction
            result = operand1 - operand2;
            printf("Operation: %d - %d = %d\n", operand1, operand2, result);
            break;
        case 2: // Multiplication
            result = operand1 * operand2;
            printf("Operation: %d * %d = %d\n", operand1, operand2, result);
            break;
        case 3: // Division with error handling
            if (operand2 != 0) {
                result = operand1 / operand2;
                printf("Operation: %d / %d = %d\n", operand1, operand2, result);
            } else {
                printf("Operation: Division by zero is undefined!\n");
            }
            break;
        default:
            printf("Invalid operation!\n");
    }
}

void memoryChallenge(int operation) {
    int operand1 = rand() % MAX_OPERAND;
    int operand2 = rand() % MAX_OPERAND;
    int result;

    switch (operation) {
        case 0:
            result = operand1 + operand2;
            printf("Remember this result: %d + %d = ?\n", operand1, operand2);
            break;
        case 1:
            result = operand1 - operand2;
            printf("Remember this result: %d - %d = ?\n", operand1, operand2);
            break;
        case 2:
            result = operand1 * operand2;
            printf("Remember this result: %d * %d = ?\n", operand1, operand2);
            break;
        case 3:
            if (operand2 != 0) {
                result = operand1 / operand2;
                printf("Remember this result: %d / %d = ?\n", operand1, operand2);
            } else {
                printf("Learning to deal with undefined results. Let's move on!\n");
                return;
            }
            break;
    }
    
    printf("How well did you remember it? Enter the result: ");
    int userAnswer;
    scanf("%d", &userAnswer);
    clearBuffer(); // Clear input buffer

    if (userAnswer == result) {
        printf("Correct! You are a memory wizard!\n");
    } else {
        printf("Oops! The correct answer was %d. Better luck next time!\n", result);
    }
}

void countdown(int seconds) {
    for (int i = seconds; i > 0; i--) {
        printf("%d... ", i);
        fflush(stdout);
        sleep(1); // Sleep for a second
    }
    printf("Blast off!\n");
}

void clearBuffer() {
    while(getchar() != '\n');
}