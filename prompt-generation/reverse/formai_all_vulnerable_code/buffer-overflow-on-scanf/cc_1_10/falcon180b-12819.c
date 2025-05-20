//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a star rating based on a numerical rating
void printRating(int rating) {
    printf("Rating: ");
    for (int i = 0; i < 5; i++) {
        if (i < rating) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Define the user ratings and corresponding star ratings
    int userRatings[5] = {5, 4, 3, 2, 1};
    int starRatings[5] = {5, 4, 3, 2, 1};

    // Generate a random movie rating between 1 and 5
    int movieRating = randInt(1, 5);

    // Print the movie rating and corresponding star rating
    printf("The movie received a rating of %d out of 5 stars.\n", movieRating);
    printRating(movieRating);

    // Ask the user to rate the movie
    int userRating;
    printf("Please rate the movie (1 to 5 stars): ");
    scanf("%d", &userRating);

    // Print the user's rating and corresponding star rating
    printf("You gave the movie a rating of %d out of 5 stars.\n", userRating);
    printRating(userRating);

    // Compare the user's rating to the movie's rating and print a message
    if (userRating > movieRating) {
        printf("You rated the movie higher than the average rating.\n");
    } else if (userRating < movieRating) {
        printf("You rated the movie lower than the average rating.\n");
    } else {
        printf("You rated the movie the same as the average rating.\n");
    }

    return 0;
}