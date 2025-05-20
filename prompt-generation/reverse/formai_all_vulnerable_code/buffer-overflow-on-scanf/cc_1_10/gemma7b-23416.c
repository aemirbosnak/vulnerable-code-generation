//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating, genre, age;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter the genre of the movie you saw: ");
    scanf("%d", &genre);

    rating = get_rating(genre, age);

    printf("Your rating for the movie is: %d", rating);

    return 0;
}

int get_rating(int genre, int age)
{
    int rating;

    if (genre == 1)
    {
        if (age >= 18)
        {
            rating = 5;
        }
        else
        {
            rating = 3;
        }
    }
    else if (genre == 2)
    {
        if (age >= 16)
        {
            rating = 4;
        }
        else
        {
            rating = 2;
        }
    }
    else if (genre == 3)
    {
        if (age >= 14)
        {
            rating = 3;
        }
        else
        {
            rating = 1;
        }
    }

    return rating;
}