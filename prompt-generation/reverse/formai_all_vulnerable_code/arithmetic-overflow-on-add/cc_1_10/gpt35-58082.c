//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>

// function to calculate and return the rating
float calculateRating(int story, int direction, int acting, int music)
{
    float avgRating;
    avgRating = (story + direction + acting + music) / 4.0;
    return avgRating;
}

int main()
{
    int story, direction, acting, music, rating;
    float averageRating;

    printf("Enter the ratings out of 10 for each category:\n");

    // input from user
    printf("Story: ");
    scanf("%d", &story);
    printf("Direction: ");
    scanf("%d", &direction);
    printf("Acting: ");
    scanf("%d", &acting);
    printf("Music: ");
    scanf("%d", &music);

    // calculate and display the rating
    averageRating = calculateRating(story, direction, acting, music);
    printf("The average rating for this movie is %.2f\n", averageRating);

    // assign rating based on average rating
    if (averageRating >= 9.0)
    {
        rating = 5; // Excellent
    }
    else if (averageRating >= 7.0 && averageRating < 9.0)
    {
        rating = 4; // Very Good
    }
    else if (averageRating >= 5.0 && averageRating < 7.0)
    {
        rating = 3; // Good
    }
    else if (averageRating >= 3.0 && averageRating < 5.0)
    {
        rating = 2; // Average
    }
    else
    {
        rating = 1; // Below Average
    }

    // display the final rating
    printf("The final rating for this movie is %d out of 5.\n", rating);

    return 0;
}