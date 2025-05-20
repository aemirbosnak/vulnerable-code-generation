//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcomeMessage() {
    printf("*******************************************\n");
    printf("                  DICE ROLLER              \n");
    printf("*******************************************\n");
    printf("Roll your favorite dice!\n");
    printf("You can roll:\n");
    printf("d4 (4 sides), d6 (6 sides), d8 (8 sides), d10 (10 sides), d12 (12 sides), d20 (20 sides), d100 (100 sides)\n");
    printf("Type 'exit' to quit the program at any time.\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1; // Return a random number between 1 and 'sides'
}

void rollMultipleDice(int numDice, int sides) {
    int total = 0;
    printf("Rolling %d d%d:\n", numDice, sides);
    for (int i = 0; i < numDice; i++) {
        int roll = rollDice(sides);
        printf("Roll %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
}

int getNumberOfDice() {
    int numDice;
    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);
    
    while(numDice <= 0) {
        printf("Invalid input. Please enter a positive number: ");
        scanf("%d", &numDice);
    }
    return numDice;
}

int getDiceSides() {
    char input[10];
    int sides = 0;
    
    printf("Enter the type of dice (e.g., d6 for a six-sided die): ");
    scanf("%s", input);
    
    if (input[0] == 'd') {
        switch(atoi(&input[1])) {
            case 4: sides = 4; break;
            case 6: sides = 6; break;
            case 8: sides = 8; break;
            case 10: sides = 10; break;
            case 12: sides = 12; break;
            case 20: sides = 20; break;
            case 100: sides = 100; break;
            default: 
                printf("Invalid die type. Please refer to the available dice.\n");
                sides = -1; // mark as invalid
                break;
        }
    } else {
        printf("Invalid format. Please start with 'd' followed by the number of sides.\n");
    }
    
    return sides;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    printWelcomeMessage();
    
    while (1) {
        char command[10];
        printf("Would you like to roll some dice? (yes/no): ");
        scanf("%s", command);
        
        if (strcmp(command, "no") == 0 || strcmp(command, "exit") == 0) {
            printf("Thank you for playing! Goodbye!\n");
            break;
        } else if (strcmp(command, "yes") != 0) {
            printf("Please respond with 'yes' or 'no'.\n");
            continue;
        }

        int numDice = getNumberOfDice();
        int sides;
        while ((sides = getDiceSides()) == -1); // Keep asking until valid sides are provided

        rollMultipleDice(numDice, sides);
    }
    
    return 0;
}