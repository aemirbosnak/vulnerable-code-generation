//FormAI DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>

int main()
{
    int movieRating;
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie you just watched from 1 to 10: ");
    scanf("%d", &movieRating);
    
    if (movieRating < 1 || movieRating > 10)
    {
        printf("Error: Invalid rating! Please enter a rating between 1 and 10.\n");
    }
    else
    {
        printf("Thank you for your rating of %d.\n", movieRating);
        
        if (movieRating == 1)
        {
            printf("Yikes! That was a terrible movie.\n");
        }
        else if (movieRating == 2)
        {
            printf("That wasn't great, but at least it had some redeeming qualities.\n");
        }
        else if (movieRating == 3)
        {
            printf("Not terrible, but definitely room for improvement.\n");
        }
        else if (movieRating == 4)
        {
            printf("A decent movie - worth watching if you're into the genre.\n");
        }
        else if (movieRating == 5)
        {
            printf("An average movie - not bad, but not particularly memorable either.\n");
        }
        else if (movieRating == 6)
        {
            printf("A solid movie - definitely worth watching.\n");
        }
        else if (movieRating == 7)
        {
            printf("A great movie - highly recommended!\n");
        }
        else if (movieRating == 8)
        {
            printf("An excellent movie - a must-watch!\n");
        }
        else if (movieRating == 9)
        {
            printf("A masterpiece! This movie will stay with you for years.\n");
        }
        else if (movieRating == 10)
        {
            printf("An absolute classic - one of the best movies of all time!\n");
        }
    }

    return 0;
}