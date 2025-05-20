//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the possible movie ratings
#define G 0
#define PG 1
#define PG13 2
#define R 3
#define NC17 4

// Define the movie rating system configuration
#define DEFAULT_RATING G
#define MAX_RATING NC17
#define NUM_RATINGS 5

// Define the movie rating system structure
struct MovieRatingSystem {
    int defaultRating;
    int maxRating;
    int numRatings;
    char *ratingNames[];
};

// Define the movie rating system instance
struct MovieRatingSystem ratingSystem = {
    .defaultRating = DEFAULT_RATING,
    .maxRating = MAX_RATING,
    .numRatings = NUM_RATINGS,
    .ratingNames = {"G", "PG", "PG-13", "R", "NC-17"}
};

// Function to get the movie rating from the user
int getMovieRating() {
    int rating;
    printf("Enter the movie rating (0-4): ");
    scanf("%d", &rating);
    return rating;
}

// Function to print the movie rating
void printMovieRating(int rating) {
    printf("The movie rating is %s.\n", ratingSystem.ratingNames[rating]);
}

// Main function
int main() {
    // Get the movie rating from the user
    int rating = getMovieRating();

    // Print the movie rating
    printMovieRating(rating);

    return 0;
}