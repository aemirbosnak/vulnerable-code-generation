//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating1, rating2;
    char side1, side2;

    printf("Enter the side you are on (R/L): ");
    scanf(" %c", &side1);

    printf("Enter your rating (1-10): ");
    scanf(" %d", &rating1);

    printf("Enter the side your opponent is on (R/L): ");
    scanf(" %c", &side2);

    printf("Enter your opponent's rating (1-10): ");
    scanf(" %d", &rating2);

    if (side1 == side2)
    {
        printf("Error: You cannot fight yourself.\n");
    }
    else
    {
        int outcome = 0;

        if (rating1 > rating2)
        {
            outcome = 1;
        }
        else if (rating1 < rating2)
        {
            outcome = 2;
        }
        else
        {
            outcome = 3;
        }

        switch (outcome)
        {
            case 1:
                printf("You win!\n");
                break;
            case 2:
                printf("You lose.\n");
                break;
            case 3:
                printf("It's a draw.\n");
                break;
        }
    }

    return 0;
}