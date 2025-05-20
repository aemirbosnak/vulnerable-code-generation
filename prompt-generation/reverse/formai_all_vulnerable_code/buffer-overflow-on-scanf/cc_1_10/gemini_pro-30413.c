//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { PG, PG13, R, NC17 };

int main()
{
    int age;
    char movie[20];

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter the movie title: ");
    scanf("%s", movie);

    if (!strcmp(movie, "The Godfather"))
    {
        if (age >= 17)
        {
            printf("You may watch this movie.\n");
        }
        else
        {
            printf("You may not watch this movie.\n");
        }
    }
    else if (!strcmp(movie, "The Shawshank Redemption"))
    {
        if (age >= 13)
        {
            printf("You may watch this movie.\n");
        }
        else
        {
            printf("You may not watch this movie.\n");
        }
    }
    else if (!strcmp(movie, "The Dark Knight"))
    {
        if (age >= 13)
        {
            printf("You may watch this movie.\n");
        }
        else
        {
            printf("You may not watch this movie.\n");
        }
    }
    else if (!strcmp(movie, "Pulp Fiction"))
    {
        if (age >= 17)
        {
            printf("You may watch this movie.\n");
        }
        else
        {
            printf("You may not watch this movie.\n");
        }
    }
    else
    {
        printf("This movie is not in our database.\n");
    }

    return 0;
}