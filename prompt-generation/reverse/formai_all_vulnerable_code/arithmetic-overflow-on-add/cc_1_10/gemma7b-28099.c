//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating, score, movie_type;
    char character_name[20];

    printf("Welcome to the Grand Hall of the Mighty Movie Rating System!");
    printf("\nPlease enter your character name:");
    scanf("%s", character_name);

    printf("Please select the movie type:");
    printf("\n1. Action\n2. Comedy\n3. Drama\n4. Fantasy\n5. Horror\n");
    scanf("%d", &movie_type);

    printf("Please enter your score (1-10):");
    scanf("%d", &score);

    rating = calculate_rating(score, movie_type);

    printf("Your character, %s, has rated the movie, %s, with a score of %d.", character_name, movie_type, score);
    printf("\nYour rating is: %d", rating);

    return 0;
}

int calculate_rating(int score, int movie_type)
{
    int rating;

    if (movie_type == 1)
    {
        rating = score + 2;
    }
    else if (movie_type == 2)
    {
        rating = score - 1;
    }
    else if (movie_type == 3)
    {
        rating = score + 1;
    }
    else if (movie_type == 4)
    {
        rating = score + 3;
    }
    else if (movie_type == 5)
    {
        rating = score - 2;
    }

    return rating;
}