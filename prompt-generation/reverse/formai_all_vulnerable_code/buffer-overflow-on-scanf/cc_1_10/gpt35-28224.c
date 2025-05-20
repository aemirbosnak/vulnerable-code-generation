//FormAI DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

/*
 * Movie Rating System
 * 
 * This program allows users to rate a particular movie on a scale from 1 to 10.
 * Users can also view the average rating for the movie, as well as the number of
 * ratings that have been submitted.
 */

int main() {
    // Declare variables
    int num_ratings = 0;
    double total_rating = 0.0;
    double avg_rating;
    int new_rating;

    // Welcome message
    printf("Welcome to the Movie Rating System!\n\n");

    // Prompt user for initial rating
    printf("Please rate the movie from 1 to 10: ");
    scanf("%d", &new_rating);

    // Validate input
    if (new_rating < 1 || new_rating > 10) {
        printf("Invalid rating. Please enter a rating from 1 to 10.\n\n");
    } else {
        num_ratings++;
        total_rating += new_rating;
    }

    // Loop for additional ratings
    while (1) {
        // Display current ratings information
        avg_rating = total_rating / num_ratings;
        printf("\nCurrent ratings:\n");
        printf("Number of ratings: %d\n", num_ratings);
        printf("Average rating: %.2lf\n\n", avg_rating);

        // Prompt user for new rating
        printf("Enter a new rating (or enter 0 to exit): ");
        scanf("%d", &new_rating);

        // Exit loop if user enters 0
        if (new_rating == 0) {
            printf("Thank you for using the Movie Rating System!\n");
            break;
        }

        // Validate input
        if (new_rating < 1 || new_rating > 10) {
            printf("Invalid rating. Please enter a rating from 1 to 10.\n\n");
            continue;
        }

        // Update ratings information
        num_ratings++;
        total_rating += new_rating;
    }

    return 0;
}