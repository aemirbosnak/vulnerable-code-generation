//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n-----------------------------------------------------\n");
    printf("----------- WELCOME TO C MOVIE RATING SYSTEM ----------");
    printf("\n-----------------------------------------------------\n\n");

    char movieName[50];
    int userRating;
    float totalRating, avgRating;
    int numRatings = 0;

    while(1) {
        printf("Enter the Movie Name: ");
        scanf("%s", movieName);

        printf("Enter Your Rating (Out of 10): ");
        scanf("%d", &userRating);

        if (userRating < 1 || userRating > 10) {
            printf("Invalid Rating! Please enter a rating between 1 to 10.\n\n");
            continue;
        }

        totalRating += userRating;
        numRatings++;

        avgRating = totalRating / numRatings;

        printf("\nThank you for rating '%s' movie.\n\n", movieName);

        printf("Movie Name: %s\n", movieName);
        printf("Average Rating: %.2f\n", avgRating);

        if(avgRating >= 9.0) {
            printf("This is an exceptional movie! A must watch!\n");
        } else if (avgRating >= 8.0 && avgRating < 9.0) {
            printf("This is a very good movie! You should watch it.\n");
        } else if (avgRating >= 7.0 && avgRating < 8.0) {
            printf("This is a good movie! You can watch it.\n");
        } else if (avgRating >= 6.0 && avgRating < 7.0) {
            printf("This is an average movie! You can watch it if you want to.\n");
        } else if (avgRating >= 5.0 && avgRating < 6.0) {
            printf("This is a below average movie! You might want to skip it.\n");
        } else {
            printf("This is a poor movie! We do not recommend it.\n");
        }

        printf("\nDo you want to rate another movie? (Enter Y for Yes / N for No): ");

        char userChoice;
        scanf(" %c", &userChoice);

        if (userChoice == 'N' || userChoice == 'n') {
            printf("\nThank you for using C Movie Rating System!\n");
            break;
        } else if (userChoice == 'Y' || userChoice == 'y') {
            printf("\n");
            continue;
        } else {
            printf("Invalid option! Terminating the program.\n");
            exit(0);
        }
    }

    return 0;
}