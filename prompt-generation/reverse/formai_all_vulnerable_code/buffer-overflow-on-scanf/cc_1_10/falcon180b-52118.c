//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define NUM_SIDES 6

int rollDice(int numDice, int numSides) {
    int diceRolls[NUM_DICE];
    int i;
    
    for (i = 0; i < numDice; i++) {
        diceRolls[i] = rand() % numSides + 1;
    }
    
    return diceRolls[0];
}

int main() {
    int numDice;
    int numSides;
    int totalRolls = 0;
    int highestRoll = 0;
    int lowestRoll = 999;
    int currentRoll;
    
    printf("Welcome to the Dice Roller!\n");
    printf("Enter the number of dice (1-6): ");
    scanf("%d", &numDice);
    
    printf("Enter the number of sides on each dice (1-6): ");
    scanf("%d", &numSides);
    
    while (1) {
        currentRoll = rollDice(numDice, numSides);
        printf("You rolled: %d\n", currentRoll);
        totalRolls++;
        
        if (currentRoll > highestRoll) {
            highestRoll = currentRoll;
        }
        
        if (currentRoll < lowestRoll) {
            lowestRoll = currentRoll;
        }
        
        if (totalRolls == 10) {
            printf("Your average roll is: %d\n", (totalRolls - highestRoll - lowestRoll) / 8);
            break;
        }
    }
    
    return 0;
}