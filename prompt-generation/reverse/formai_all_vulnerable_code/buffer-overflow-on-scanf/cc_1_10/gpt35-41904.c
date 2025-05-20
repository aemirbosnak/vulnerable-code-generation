//FormAI DATASET v1.0 Category: Dice Roller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 to 6
int roll_dice(void)
{
    return rand() % 6 + 1;
}

int main()
{
    int dice_1, dice_2, total, game_point;
    char choice;

    printf("Welcome to Dice Roller!\nPress any key to roll the dice.\n");

    // Seed the random function with current time
    srand(time(NULL));

    do
    {
        printf("Rolling...\n");
        // Call the roll_dice function to generate two random numbers
        dice_1 = roll_dice();
        dice_2 = roll_dice();
        total = dice_1 + dice_2;

        printf("Dice 1: %d\n", dice_1);
        printf("Dice 2: %d\n", dice_2);
        printf("Total: %d\n", total);

        // Check the current game point
        if (game_point != 0)
        {
            if (total == game_point)
            {
                printf("Congratulations! You won!\n");
                break;
            }
            else if (total == 7)
            {
                printf("Sorry, you lost!\n");
                break;
            }
        }

        // If game point is not yet set
        if (game_point == 0)
        {
            if (total == 7 || total == 11)
            {
                printf("Congratulations! You won!\n");
                break;
            }
            else if (total == 2 || total == 3 || total == 12)
            {
                printf("Sorry, you lost!\n");
                break;
            }
            else
            {
                game_point = total;
                printf("Your game point is: %d\n", game_point);
            }
        }

        printf("Do you want to roll again? (Y/N) ");
        scanf("%c", &choice);

        // To handle extra newline character
        getchar();

    } while (choice == 'Y' || choice == 'y');

    printf("Thank you for playing Dice Roller!\n");

    return 0;
}