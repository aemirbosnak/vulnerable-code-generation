//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include<stdio.h>

int main()
{
    int rating, sum = 0, count = 0;
    float average;

    printf("Welcome to the C Movie Rating System!\n");

    do
    {
        printf("\nEnter the rating of the movie (1-10): ");
        scanf("%d", &rating);

        if (rating >= 1 && rating <= 10)
        {
            sum += rating;  // sum of ratings
            count++;  // count of ratings
            if (rating >= 7)
            {
                printf("Wow! That was a great movie!\n");
            }
            else if (rating >= 4)
            {
                printf("It was an average movie.\n");
            }
            else
            {
                printf("Oh no! That movie was terrible!\n");
            }
        }
        else
        {
            printf("Invalid rating! Please enter a number between 1 and 10.\n");
        }

    } while (rating != 0);

    if (count > 0)
    {
        average = (float)sum / count;
        printf("\nYou have rated %d movies.\n", count);
        printf("The average rating of the movies is %.2f\n", average);
    }
    else
    {
        printf("\nYou have not rated any movies.\n");
    }

    printf("\nThank you for using C Movie Rating System!\n");

    return 0;
}