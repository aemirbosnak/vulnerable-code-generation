//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating = 0;
    char genre = ' ';
    char condition = ' ';

    printf("Welcome to the Post-Apocalyptic Movie Rating System!\n");
    printf("Please select a genre:");
    scanf(" %c", &genre);

    printf("Please select the condition of the movie:");
    scanf(" %c", &condition);

    switch (genre)
    {
        case 'a':
            rating = 5;
            break;
        case 'c':
            rating = 3;
            break;
        case 'f':
            rating = 2;
            break;
        default:
            rating = 1;
    }

    switch (condition)
    {
        case 'g':
            rating++;
            break;
        case 'p':
            rating++;
            break;
        case 'b':
            rating--;
            break;
        default:
            rating = rating;
    }

    printf("Your movie rating is: %d\n", rating);

    return 0;
}