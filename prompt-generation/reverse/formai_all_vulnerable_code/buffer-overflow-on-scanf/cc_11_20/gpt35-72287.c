//FormAI DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numOfDice, numOfSides, bonus;
    char input;
    srand(time(NULL));
    
    printf("Welcome to the Dice Roller program!\n\n");
    
    do {
        printf("How many dice would you like to roll (1-10)? ");
        scanf(" %d", &numOfDice);
        
        if (numOfDice < 1 || numOfDice > 10) {
            printf("Invalid input, please enter a number between 1 and 10.\n\n");
            continue;
        }
        
        printf("How many sides should each die have (4, 6, 8, 10, 12, 20)? ");
        scanf(" %d", &numOfSides);
        
        switch(numOfSides) {
            case 4:
            case 6:
            case 8:
            case 10:
            case 12:
            case 20:
                break;
            default:
                printf("Invalid input, please enter a valid number of sides.\n\n");
                continue;
        }
        
        printf("Would you like to add a bonus to the roll? (y/n) ");
        scanf(" %c", &input);
        
        if (input == 'y' || input == 'Y') {
            printf("Enter the bonus amount: ");
            scanf(" %d", &bonus);
        }
        else {
            bonus = 0;
        }
        
        printf("\nRolling %d %d-sided dice...\n\n", numOfDice, numOfSides);
        int total = 0;
        for (int i = 0; i < numOfDice; i++) {
            int roll = rand() % numOfSides + 1;
            printf("Die %d: %d\n", i+1, roll);
            total += roll;
        }
        printf("\nTotal: %d\n", total + bonus);
        
        printf("\nWould you like to roll again? (y/n) ");
        scanf(" %c", &input);
        printf("\n");
    } while (input == 'y' || input == 'Y');
    
    printf("Thank you for using the Dice Roller program!\n");
    return 0;
}