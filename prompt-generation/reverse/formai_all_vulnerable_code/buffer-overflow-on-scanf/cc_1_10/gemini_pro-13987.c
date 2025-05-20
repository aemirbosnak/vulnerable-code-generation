//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the rating scale
#define RATING_SCALE 10

// Define the movie rating system
enum MovieRating {
    G,
    PG,
    PG13,
    R,
    NC17
};

// Define the movie rating system as a string array
const char *movieRatingStrings[] = {
    "G",
    "PG",
    "PG-13",
    "R",
    "NC-17"
};

// Define the function to get the movie rating
enum MovieRating getMovieRating(int rating) {
    // If the rating is less than 0 or greater than the rating scale, return an invalid rating
    if (rating < 0 || rating > RATING_SCALE) {
        return -1;
    }

    // Recursively call the function to get the movie rating for the next rating
    return getMovieRating(rating - 1);
}

// Define the function to print the movie rating
void printMovieRating(enum MovieRating rating) {
    // If the rating is invalid, print an error message
    if (rating == -1) {
        printf("Invalid rating\n");
        return;
    }

    // Print the movie rating
    printf("Movie rating: %s\n", movieRatingStrings[rating]);
}

// Define the main function
int main() {
    // Get the user input for the movie rating
    int rating;
    printf("Enter the movie rating (0-10): ");
    scanf("%d", &rating);

    // Get the movie rating
    enum MovieRating movieRating = getMovieRating(rating);

    // Print the movie rating
    printMovieRating(movieRating);

    return 0;
}