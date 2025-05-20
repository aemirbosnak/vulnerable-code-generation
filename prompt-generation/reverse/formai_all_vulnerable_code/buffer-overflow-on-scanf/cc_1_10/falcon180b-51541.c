//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to generate a random number between min and max
int rand_num(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to roll the dice
void roll_dice()
{
    int dice1, dice2, dice3;

    // Roll the first dice
    dice1 = rand_num(1, 6);

    // Roll the second dice
    dice2 = rand_num(1, 6);

    // Roll the third dice
    dice3 = rand_num(1, 6);

    // Display the result
    printf("You rolled a %d, %d, and %d.\n", dice1, dice2, dice3);
}

int main()
{
    int choice, num_rolls;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Display the menu options
    printf("Welcome to the Cyberpunk Dice Roller!\n\n");
    printf("1. Roll the dice\n");
    printf("2. Roll the dice 10 times\n");
    printf("3. Exit\n\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Check the user's choice
    switch(choice)
    {
        case 1:
            // Roll the dice once
            roll_dice();
            break;

        case 2:
            // Roll the dice 10 times
            printf("Rolling the dice 10 times...\n\n");
            for(int i = 0; i < 10; i++)
            {
                roll_dice();
            }
            break;

        case 3:
            // Exit the program
            printf("Exiting program...\n");
            break;

        default:
            // Invalid choice
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}