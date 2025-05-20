//FormAI DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);

int main(void)
{
    int roll1, roll2, sum;
    srand((unsigned) time(NULL)); // seed random number generator with current time

    printf("Dice roll simulator!\n\n");

    char input;
    do {
        printf("Press ENTER to roll the dice...");
        scanf("%c", &input);
        if (input == '\n') // only roll if ENTER is pressed
        {
            roll1 = roll_dice();
            roll2 = roll_dice();

            printf("\nYou rolled a %d and a %d!\n", roll1, roll2);

            sum = roll1 + roll2;

            if (sum == 7 || sum == 11)
            {
                printf("You win!\n");
            }
            else if (sum == 2 || sum == 3 || sum == 12)
            {
                printf("You lose!\n");
            }
            else
            {
                printf("Your point is %d.\n", sum);
                do {
                    printf("Press ENTER to roll the dice again...");
                    scanf("%c", &input);
                } while (input != '\n');

                do {
                    roll1 = roll_dice();
                    roll2 = roll_dice();
                    printf("\nYou rolled a %d and a %d!\n", roll1, roll2);
                    if (roll1 + roll2 == sum)
                    {
                        printf("You win!\n");
                        break;
                    }
                    else if (roll1 + roll2 == 7)
                    {
                        printf("You lose!\n");
                        break;
                    }
                    else
                    {
                        printf("Your point is still %d.\n", sum);
                        do {
                            printf("Press ENTER to roll the dice again...");
                            scanf("%c", &input);
                        } while (input != '\n');
                    }
                } while (1);
            }
        }
    } while (1);

    return 0;
}

int roll_dice(void)
{
    return rand() % 6 + 1; // generate a random number between 1 and 6
}