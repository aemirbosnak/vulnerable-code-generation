//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void clearInputBuffer() {
    while (getchar() != '\n');
}

void rollDice(int numDice, int numSides) {
    int total = 0;
    int *results = (int *)malloc(numDice * sizeof(int));
    
    if (results == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Rolling %d dice with %d sides:\n", numDice, numSides);
    for (int i = 0; i < numDice; i++) {
        results[i] = (rand() % numSides) + 1;
        total += results[i];
        printf("Die %d: %d\n", i + 1, results[i]);
    }
    
    printf("Total: %d\n", total);
    free(results);
}

int getPositiveInteger(const char *prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1 || value < 1) {
            printf("Invalid input. Please enter a positive integer.\n");
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return value;
        }
    }
}

char getYesNo(const char *prompt) {
    char response;
    while (1) {
        printf("%s (y/n): ", prompt);
        response = getchar();
        clearInputBuffer(); // Clear any extra characters
        if (response == 'y' || response == 'Y' || response == 'n' || response == 'N') {
            return response;
        }
        printf("Invalid input. Please enter 'y' or 'n'.\n");
    }
}

int main() {
    srand(time(NULL));
    
    int numDice, numSides;
    char rollAgain;

    do {
        numDice = getPositiveInteger("Enter the number of dice to roll (1-10): ");
        if (numDice > MAX_DICE) {
            printf("Limiting to maximum of %d dice.\n", MAX_DICE);
            numDice = MAX_DICE;
        }

        numSides = getPositiveInteger("Enter the number of sides on each die (1-20): ");
        if (numSides > MAX_SIDES) {
            printf("Limiting to maximum of %d sides.\n", MAX_SIDES);
            numSides = MAX_SIDES;
        }

        rollDice(numDice, numSides);
        
        rollAgain = getYesNo("Do you want to roll again?");
        
    } while (rollAgain == 'y' || rollAgain == 'Y');

    printf("Thank you for using the Dice Roller!\n");
    return 0;
}