//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAX_DICE 100

int main()
{
    int num_dice, i, j, result;
    char play_again;
    struct dice
    {
        int value;
        int sides;
    } dice[MAX_DICE];

    srand(time(NULL));

    do
    {
        printf("Enter the number of dice (1-100): ");
        scanf("%d", &num_dice);
        if(num_dice < 1 || num_dice > MAX_DICE)
        {
            printf("Invalid input. Please try again.\n");
        }
    } while(num_dice < 1 || num_dice > MAX_DICE);

    for(i = 0; i < num_dice; i++)
    {
        printf("Enter the number of sides for dice %d (2-100): ", i+1);
        scanf("%d", &dice[i].sides);
        if(dice[i].sides < 2 || dice[i].sides > SIDES)
        {
            printf("Invalid input. Please try again.\n");
            i--;
        }
    }

    printf("Rolling dice...\n");
    for(i = 0; i < num_dice; i++)
    {
        result = rand() % dice[i].sides + 1;
        printf("Dice %d rolled a %d\n", i+1, result);
    }

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &play_again);

    if(play_again == 'y' || play_again == 'Y')
    {
        main();
    }

    return 0;
}