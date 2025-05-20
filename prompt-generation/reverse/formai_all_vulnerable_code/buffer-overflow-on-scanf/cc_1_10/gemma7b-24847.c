//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    char genre;

    printf("Enter the rating (1-5): ");
    scanf("%d", &rating);

    printf("Enter the genre (Comedy, Drama, Action): ");
    scanf(" %c", &genre);

    switch (genre)
    {
        case 'C':
            printf("The movie is a Comedy.\n");
            break;
        case 'D':
            printf("The movie is a Drama.\n");
            break;
        case 'A':
            printf("The movie is an Action film.\n");
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
            printf("The movie is average.\n");
            break;
        case 4:
            printf("The movie is good.\n");
            break;
        case 5:
            printf("The movie is excellent.\n");
            break;
        default:
            printf("Invalid rating.\n");
    }

    return 0;
}