//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    char genre;
    float budget;

    printf("Welcome to the C Movie Rating System!\n");

    // Get the movie's rating, genre, and budget
    printf("Enter the movie's rating (1-5): ");
    scanf("%d", &rating);

    printf("Enter the movie's genre (A-Z): ");
    scanf(" %c", &genre);

    printf("Enter the movie's budget (in millions): ");
    scanf("%f", &budget);

    // Calculate the movie's rating score
    int score = rating + 2 * genre - budget / 5;

    // Print the movie's rating score
    printf("The movie's rating score is: %d\n", score);

    // Determine the movie's rating letter
    char letter = 'F';
    if (score >= 4)
    {
        letter = 'A';
    }
    else if (score >= 3)
    {
        letter = 'B';
    }
    else if (score >= 2)
    {
        letter = 'C';
    }
    else if (score >= 1)
    {
        letter = 'D';
    }

    // Print the movie's rating letter
    printf("The movie's rating letter is: %c\n", letter);

    return 0;
}