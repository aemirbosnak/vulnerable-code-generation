//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    char side;

    printf("Enter your side (R/L): ");
    scanf("%c", &side);

    printf("Enter your rating (1-5): ");
    scanf("%d", &rating);

    switch (side)
    {
        case 'R':
            switch (rating)
            {
                case 1:
                    printf("Your rating: Romeo 1 - Not so bad, but could be better.\n");
                    break;
                case 2:
                    printf("Your rating: Romeo 2 - Pretty good, but could be improved.\n");
                    break;
                case 3:
                    printf("Your rating: Romeo 3 - Good, but could be even better.\n");
                    break;
                case 4:
                    printf("Your rating: Romeo 4 - Excellent, a true hero.\n");
                    break;
                case 5:
                    printf("Your rating: Romeo 5 - Perfect, the epitome of love.\n");
                    break;
            }
            break;
        case 'L':
            switch (rating)
            {
                case 1:
                    printf("Your rating: Mercutio 1 - Weak, but could be better.\n");
                    break;
                case 2:
                    printf("Your rating: Mercutio 2 - Pretty good, but could be improved.\n");
                    break;
                case 3:
                    printf("Your rating: Mercutio 3 - Good, but could be even better.\n");
                    break;
                case 4:
                    printf("Your rating: Mercutio 4 - Excellent, a true warrior.\n");
                    break;
                case 5:
                    printf("Your rating: Mercutio 5 - Perfect, the epitome of strength.\n");
                    break;
            }
            break;
    }

    return 0;
}