//FormAI DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    
    int sides, numDice, numRolls;
    bool validInput;
    
    do
    {
        validInput = true;
        
        printf("How many sides do your dice have? ");
        if (scanf("%d", &sides) != 1 || sides < 2)
        {
            validInput = false;
            printf("Invalid input. Dice must have at least 2 sides.\n");
        }
        
        printf("How many dice do you want to roll? ");
        if (scanf("%d", &numDice) != 1 || numDice < 1)
        {
            validInput = false;
            printf("Invalid input. Must roll at least 1 die.\n");
        }
        
        printf("How many times do you want to roll? ");
        if (scanf("%d", &numRolls) != 1 || numRolls < 1)
        {
            validInput = false;
            printf("Invalid input. Must roll at least once.\n");
        }
        
        fflush(stdin);
    } while (!validInput);
    
    printf("\nRolling %d %d-sided dice %d times...\n\n", numDice, sides, numRolls);
    
    int rollTotal = 0;
    for (int i = 0; i < numRolls; i++)
    {
        printf("Roll %d: ", i+1);
        int individualRollTotal = 0;
        for (int j = 0; j < numDice; j++)
        {
            int roll = rand() % sides + 1; // Generate a random number in the range [1, sides]
            individualRollTotal += roll;
            printf("%d ", roll);
        }
        printf("(Total: %d)\n", individualRollTotal);
        rollTotal += individualRollTotal;
    }
    
    printf("\nAverage roll: %.2f\n", (float)rollTotal / numRolls);
    
    return 0;
}