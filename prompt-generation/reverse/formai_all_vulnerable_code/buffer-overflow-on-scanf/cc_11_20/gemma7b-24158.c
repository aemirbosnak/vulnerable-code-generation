//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating = 0;
    char genre;

    printf("Enter the genre of the movie: ");
    scanf("%c", &genre);

    printf("Enter the rating of the movie (1-10): ");
    scanf("%d", &rating);

    switch (genre)
    {
        case 'c':
            printf("The movie is a comedy.\n");
            break;
        case 't':
            printf("The movie is a tragedy.\n");
            break;
        case 'a':
            printf("The movie is an action film.\n");
            break;
        default:
            printf("Invalid genre.\n");
    }

    switch (rating)
    {
        case 1:
            printf("The movie is terrible.\n");
            break;
        case 2:
            printf("The movie is bad.\n");
            break;
        case 3:
            printf("The movie is mediocre.\n");
            break;
        case 4:
            printf("The movie is good.\n");
            break;
        case 5:
            printf("The movie is great.\n");
            break;
        case 6:
            printf("The movie is excellent.\n");
            break;
        case 7:
            printf("The movie is superb.\n");
            break;
        case 8:
            printf("The movie is extraordinary.\n");
            break;
        case 9:
            printf("The movie is exceptional.\n");
            break;
        case 10:
            printf("The movie is a masterpiece.\n");
            break;
        default:
            printf("Invalid rating.\n");
    }

    return 0;
}