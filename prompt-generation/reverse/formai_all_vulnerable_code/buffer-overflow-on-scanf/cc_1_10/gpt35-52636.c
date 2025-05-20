//FormAI DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>

// Function to get the movie rating from the user
int get_rating()
{
    int rating;
    printf("Please rate the movie out of 10: ");
    scanf("%d", &rating);
    return rating;
}

// Function to display the movie rating
void display_rating(int rating)
{
    printf("The movie's rating is: %d/10\n", rating);
}

int main()
{
    int rating = get_rating();

    // Validate the rating
    if (rating < 0 || rating > 10)
    {
        printf("Invalid rating! Please rate the movie out of 10.\n");
        rating = get_rating();
    }

    // Display the movie rating
    display_rating(rating);

    // Provide a recommendation based on the rating
    if (rating == 10)
    {
        printf("This is a must-watch movie! It is perfect in every way.\n");
    }
    else if (rating >= 8 && rating < 10)
    {
        printf("This movie is definitely worth watching. It is well worth your time.\n");
    }
    else if (rating >= 6 && rating < 8)
    {
        printf("This movie is okay, but it could be better. Watch it if you have time.\n");
    }
    else if (rating >= 4 && rating < 6)
    {
        printf("This movie is not great. You should probably skip it.\n");
    }
    else
    {
        printf("This movie is terrible. Avoid it at all costs!\n");
    }

    return 0;
}