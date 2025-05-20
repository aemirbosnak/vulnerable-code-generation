//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int movie_rating;
    char movie_title[50];

    printf("Enter the movie title: ");
    scanf("%s", movie_title);

    printf("Enter the movie rating (1-10): ");
    scanf("%d", &movie_rating);

    switch (movie_rating)
    {
        case 1:
            printf("Rating: 1/10 - Awful!\n");
            break;
        case 2:
            printf("Rating: 2/10 - Poor.\n");
            break;
        case 3:
            printf("Rating: 3/10 - Meh.\n");
            break;
        case 4:
            printf("Rating: 4/10 - Above Average.\n");
            break;
        case 5:
            printf("Rating: 5/10 - Good.\n");
            break;
        case 6:
            printf("Rating: 6/10 - Very Good.\n");
            break;
        case 7:
            printf("Rating: 7/10 - Excellent.\n");
            break;
        case 8:
            printf("Rating: 8/10 - Outstanding.\n");
            break;
        case 9:
            printf("Rating: 9/10 - Near Perfect.\n");
            break;
        case 10:
            printf("Rating: 10/10 - Perfect.\n");
            break;
        default:
            printf("Invalid rating.\n");
            break;
    }

    printf("Movie title: %s\n", movie_title);
    printf("Movie rating: %d/10\n", movie_rating);
    printf("Overall rating: %s\n", movie_rating);

    return 0;
}