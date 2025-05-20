//FormAI DATASET v1.0 Category: Dice Roller ; Style: curious
// Welcome to the Curious Dice Roller Program!
// Have you ever wondered how fair your dice actually are? Let's find out!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome! How many dice would you like to roll? ");
    
    int numDice;
    scanf("%d", &numDice);
    
    printf("How many sides should each die have? ");
    
    int numSides;
    scanf("%d", &numSides);
    
    printf("Great! Rolling %d %d-sided dice...\n", numDice, numSides);
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    int sum = 0;
    for (int i = 0; i < numDice; i++) {
        int roll = rand() % numSides + 1;
        printf("Roll %d: %d\n", i+1, roll);
        sum += roll;
    }
    
    printf("Total: %d\n", sum);
    
    // Let's add a curious twist - what if we want to roll with a weighted die?
    printf("Would you like to roll with a weighted die? (y/n) ");
    
    char choice;
    scanf(" %c", &choice); // notice the space before %c - this eats up any whitespace before the character
    
    if (choice == 'y') {
        printf("Enter the probability (as a percentage) of rolling the maximum value: ");
        
        int prob;
        scanf("%d", &prob);
        
        // Determine the maximum value and the probability of rolling it
        int maxVal = numSides;
        double maxProb = prob / 100.0;
        
        printf("Rolling with a %d-sided die, with maximum value %d and probability %.2f%%...\n", numSides, maxVal, maxProb*100);
        
        sum = 0;
        for (int i = 0; i < numDice; i++) {
            double rollProb = (double) rand() / RAND_MAX; // generate a random number between 0 and 1
            int roll;
            if (rollProb < maxProb) {
                roll = maxVal;
            } else {
                roll = rand() % (numSides-1) + 1; // generate a random number between 1 and numSides-1
            }
            printf("Roll %d: %d\n", i+1, roll);
            sum += roll;
        }
        
        printf("Total: %d\n", sum);
    }
    
    printf("Thanks for rolling with us! Come back soon.\n");
    
    return 0;
}