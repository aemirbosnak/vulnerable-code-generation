//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num_rolls, i, j;
    int num_sides;
    int roll;
    int sum = 0;
    int max_roll;
    int min_roll;
    float avg_roll;
    char play_again;

    srand(time(0));

    printf("Welcome to the Dice Roller Game!\n");
    printf("How many sides does your dice have? ");
    scanf("%d", &num_sides);

    printf("How many times do you want to roll the dice? ");
    scanf("%d", &num_rolls);

    max_roll = num_sides * num_rolls;
    min_roll = 1;

    for(i = 0; i < num_rolls; i++)
    {
        roll = rand() % num_sides + 1;
        sum += roll;
        if(i == 0 || roll > max_roll)
        {
            max_roll = roll;
        }
        if(i == 0 || roll < min_roll)
        {
            min_roll = roll;
        }
    }

    avg_roll = (float)sum / num_rolls;

    printf("\nYou rolled the dice %d times.\n", num_rolls);
    printf("The maximum roll was %d.\n", max_roll);
    printf("The minimum roll was %d.\n", min_roll);
    printf("The average roll was %.2f.\n", avg_roll);

    printf("\nDo you want to play again? (y/n) ");
    scanf(" %c", &play_again);

    if(play_again == 'y' || play_again == 'Y')
    {
        main();
    }
    else
    {
        printf("\nThanks for playing!");
    }

    return 0;
}