//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r_num, p_num, d_num, side_num, choice, winner;
    char team_a, team_b;

    printf("Welcome to the epic battle of Romeo and Juliet!\n");
    printf("Choose your side: (A) Romeo or (B) Juliet\n");
    scanf("%c", &team_a);

    printf("Enter the number of rolls you want to make: ");
    scanf("%d", &r_num);

    for (int i = 0; i < r_num; i++)
    {
        printf("Roll the dice: ");
        d_num = rand() % 6 + 1;

        switch (d_num)
        {
            case 1:
                side_num = 2;
                break;
            case 2:
                side_num = 3;
                break;
            case 3:
                side_num = 4;
                break;
            case 4:
                side_num = 5;
                break;
            case 5:
                side_num = 6;
                break;
            case 6:
                side_num = 1;
                break;
        }

        printf("You rolled a %d, which is side %d.\n", d_num, side_num);
    }

    // Determine the winner
    if (side_num == team_a)
    {
        winner = 'A';
    }
    else if (side_num == team_b)
    {
        winner = 'B';
    }
    else
    {
        winner = 'N';
    }

    // Announce the winner
    printf("The winner is: %c!\n", winner);

    return 0;
}