//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num_dice, sides, i, j, max_rolls, total_rolls, roll_count, highest_roll, lowest_roll, sum, count;
    char play_again = 'y';
    srand(time(0));

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides do the dice have? ");
    scanf("%d", &sides);

    printf("How many times do you want to roll the dice? ");
    scanf("%d", &max_rolls);

    total_rolls = 0;
    while(total_rolls < max_rolls)
    {
        for(i = 0; i < num_dice; i++)
        {
            roll_count = 0;
            highest_roll = 0;
            lowest_roll = 100;
            sum = 0;

            while(roll_count < 6)
            {
                printf("Rolling dice %d... ", i+1);
                count = rand() % sides + 1;
                printf("%d\n", count);

                if(count > highest_roll)
                {
                    highest_roll = count;
                }
                if(count < lowest_roll)
                {
                    lowest_roll = count;
                }
                sum += count;
                roll_count++;
            }

            printf("Dice %d rolled %d times.\n", i+1, roll_count);
            printf("Highest roll: %d\n", highest_roll);
            printf("Lowest roll: %d\n", lowest_roll);
            printf("Total rolls: %d\n", sum);
            printf("\n");

            total_rolls++;
        }

        printf("Do you want to roll the dice again? (y/n) ");
        scanf(" %c", &play_again);
    }

    return 0;
}