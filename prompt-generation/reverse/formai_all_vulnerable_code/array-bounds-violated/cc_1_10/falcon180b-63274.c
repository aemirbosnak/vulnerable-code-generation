//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_RATING_LENGTH 10

// Function prototypes
int isValidRating(char* rating);
int getRating(char* rating);

int main() {
    char title[MAX_TITLE_LENGTH];
    char rating[MAX_RATING_LENGTH];
    int movieRating;
    int validRating;

    printf("Enter the title of the movie: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);

    // Remove newline character from title
    int titleLength = strlen(title);
    if (title[titleLength - 1] == '\n') {
        title[titleLength - 1] = '\0';
    }

    printf("Enter the rating of the movie: ");
    fgets(rating, MAX_RATING_LENGTH, stdin);

    // Remove newline character from rating
    int ratingLength = strlen(rating);
    if (rating[ratingLength - 1] == '\n') {
        rating[ratingLength - 1] = '\0';
    }

    validRating = isValidRating(rating);

    if (validRating == 1) {
        movieRating = getRating(rating);
        printf("The movie '%s' has a rating of %d out of 10.\n", title, movieRating);
    } else {
        printf("Invalid rating. Please enter a valid rating.\n");
    }

    return 0;
}

// Function to check if rating is valid
int isValidRating(char* rating) {
    int ratingLength = strlen(rating);

    // Check if rating is empty
    if (ratingLength == 0) {
        return 0;
    }

    // Check if rating contains only digits
    for (int i = 0; i < ratingLength; i++) {
        if (!isdigit(rating[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to get movie rating
int getRating(char* rating) {
    int ratingLength = strlen(rating);
    int movieRating = 0;

    // Convert rating string to integer
    for (int i = 0; i < ratingLength; i++) {
        movieRating = movieRating * 10 + rating[i] - '0';
    }

    return movieRating;
}