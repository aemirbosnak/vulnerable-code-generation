//FormAI DATASET v1.0 Category: Movie Rating System ; Style: introspective
// Welcome to the Unique C Movie Rating System
// Let's start by defining the rating scale

#include <stdio.h>

int main()
{
    int rating;

    printf("Welcome to the Unique Movie Rating System\n");
    printf("Please rate your movie experience on a scale of 1-10: ");
    scanf("%d", &rating);

    if (rating < 1 || rating > 10) // Check for invalid rating
    {
        printf("Invalid rating.\nPlease rate your movie experience on a scale of 1-10: ");
        scanf("%d", &rating);
    }

    // Let's check what the user thought of the movie

    if (rating >= 1 && rating <= 3)
    {
        printf("You did not enjoy the movie.\n");
    }
    else if (rating >= 4 && rating <= 6)
    {
        printf("You thought the movie was okay.\n");
    }
    else if (rating >= 7 && rating <= 9)
    {
        printf("You really enjoyed the movie!\n");
    }
    else
    {
        printf("You absolutely loved the movie!\n");
    }

    // Let's give some recommendations based on the user's rating

    switch (rating)
    {
        case 1:
        case 2:
            printf("We recommend that you give the movie another chance and try watching it again with an open mind.\n");
            break;
        case 3:
            printf("We recommend that you try watching a different genre of movies to see if you enjoy those more.\n");
            break;
        case 4:
        case 5:
            printf("We recommend that you give movies with similar themes or plots a try as well.\n");
            break;
        case 6:
            printf("We recommend that you try movies with different directors or actors to see if you enjoy their style more.\n");
            break;
        case 7:
        case 8:
            printf("We recommend that you watch more movies with similar themes as this one as well as movies from the same director or production company.\n");
            break;
        case 9:
        case 10:
            printf("We recommend that you watch more movies from the same genre as this one, as well as taking a look at the director’s other oeuvres and/or the production company’s work.\n");
            break;
    }

    // Let's ask the user if they would like to rate another movie

    char answer;

    printf("Would you like to rate another movie? (Y/N): ");
    scanf(" %c", &answer);

    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') // Check for invalid input
    {
        printf("Invalid input. Please enter Y or N: ");
        scanf(" %c", &answer);
    }

    if (answer == 'Y' || answer == 'y')
    {
        main(); // Call main function again
    }
    else
    {
        printf("Thank you for using the Unique Movie Rating System.");
        return 0;
    }
}