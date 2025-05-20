//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the rating system
#define RATING_SYSTEM 5

// Function to display the rating system
void displayRatingSystem() {
    printf("The movie rating system is out of %d stars.\n", RATING_SYSTEM);
}

// Function to get user input for the movie rating
int getUserRating() {
    int rating = 0;

    printf("Please enter your rating for the movie (out of %d stars): ", RATING_SYSTEM);
    scanf("%d", &rating);

    if (rating < 0 || rating > RATING_SYSTEM) {
        printf("Invalid rating. Please enter a rating between 0 and %d.\n", RATING_SYSTEM);
        return getUserRating();
    }

    return rating;
}

// Function to calculate the average rating
double calculateAverageRating(int ratings[], int numRatings) {
    int sum = 0;

    for (int i = 0; i < numRatings; i++) {
        sum += ratings[i];
    }

    return (double) sum / numRatings;
}

int main() {
    int numRatings = 0;

    // Get the number of ratings from the user
    printf("How many ratings would you like to enter for the movie? ");
    scanf("%d", &numRatings);

    // Initialize the ratings array
    int ratings[numRatings];

    // Get the ratings from the user
    for (int i = 0; i < numRatings; i++) {
        ratings[i] = getUserRating();
    }

    // Calculate the average rating
    double averageRating = calculateAverageRating(ratings, numRatings);

    // Display the average rating
    printf("The average rating for the movie is %.2f stars.\n", averageRating);

    return 0;
}