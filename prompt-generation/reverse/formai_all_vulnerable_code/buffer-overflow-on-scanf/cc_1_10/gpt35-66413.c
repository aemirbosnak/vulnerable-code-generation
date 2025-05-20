//FormAI DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random integers in the range [a, b]
int randInRange(int a, int b)
{
    return (a + (rand() % (b - a + 1)));
}

int main()
{
    srand(time(0)); // Seed the random number generator with current time
    
    printf("Greetings adventurer! Welcome to the Math Calculations Challenge!\n");
    printf("You will be put to the test with a series of math problems. Answer them correctly to earn gold.\n");
    printf("But beware! Failure to answer correctly will result in a loss of gold. Are you ready?\n\n");

    int gold = 100; // Starting gold amount
    
    while(gold > 0) // Keep playing until gold is depleted
    {
        int num1 = randInRange(1, 50);
        int num2 = randInRange(1, 50);
        int result;

        printf("What is the sum of %d and %d?\n", num1, num2);
        scanf("%d", &result);

        if(result == (num1 + num2)) // Correct answer
        {
            int earnedGold = randInRange(1, 10);
            gold += earnedGold;

            printf("Well done, adventurer! You have earned %d gold.\n", earnedGold);
            printf("You now have %d gold.\n\n", gold);
        }
        else // Incorrect answer
        {
            int lostGold = randInRange(5, 20);
            gold -= lostGold;

            printf("Sorry adventurer, you have lost %d gold.\n", lostGold);
            printf("You now have %d gold.\n\n", gold);
        }
    }

    printf("You have run out of gold, adventurer. Farewell!\n");

    return 0;
}