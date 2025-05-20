//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    char genre;

    printf("Enter the rating of the movie (1-10): ");
    scanf("%d", &rating);

    printf("Enter the genre of the movie (comedy, drama, action): ");
    scanf(" %c", &genre);

    switch (genre)
    {
        case 'c':
            printf("The rating for this comedy is: ");
            switch (rating)
            {
                case 1:
                    printf("1/10\n");
                    break;
                case 2:
                    printf("2/10\n");
                    break;
                case 3:
                    printf("3/10\n");
                    break;
                case 4:
                    printf("4/10\n");
                    break;
                case 5:
                    printf("5/10\n");
                    break;
                case 6:
                    printf("6/10\n");
                    break;
                case 7:
                    printf("7/10\n");
                    break;
                case 8:
                    printf("8/10\n");
                    break;
                case 9:
                    printf("9/10\n");
                    break;
                case 10:
                    printf("10/10\n");
                    break;
            }
            break;
        case 'd':
            printf("The rating for this drama is: ");
            switch (rating)
            {
                case 1:
                    printf("1/10\n");
                    break;
                case 2:
                    printf("2/10\n");
                    break;
                case 3:
                    printf("3/10\n");
                    break;
                case 4:
                    printf("4/10\n");
                    break;
                case 5:
                    printf("5/10\n");
                    break;
                case 6:
                    printf("6/10\n");
                    break;
                case 7:
                    printf("7/10\n");
                    break;
                case 8:
                    printf("8/10\n");
                    break;
                case 9:
                    printf("9/10\n");
                    break;
                case 10:
                    printf("10/10\n");
                    break;
            }
            break;
        case 'a':
            printf("The rating for this action movie is: ");
            switch (rating)
            {
                case 1:
                    printf("1/10\n");
                    break;
                case 2:
                    printf("2/10\n");
                    break;
                case 3:
                    printf("3/10\n");
                    break;
                case 4:
                    printf("4/10\n");
                    break;
                case 5:
                    printf("5/10\n");
                    break;
                case 6:
                    printf("6/10\n");
                    break;
                case 7:
                    printf("7/10\n");
                    break;
                case 8:
                    printf("8/10\n");
                    break;
                case 9:
                    printf("9/10\n");
                    break;
                case 10:
                    printf("10/10\n");
                    break;
            }
            break;
    }

    return 0;
}