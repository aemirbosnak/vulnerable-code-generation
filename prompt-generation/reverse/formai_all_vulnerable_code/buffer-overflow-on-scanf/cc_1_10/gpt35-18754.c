//FormAI DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct for movie ratings
struct MovieRating {
    char title[50];
    int year;
    char mpaa_rating[5];
    double rating;
};

// Function to get user input for a movie rating
void getUserRating(struct MovieRating *rating) {
    printf("\nEnter movie title: ");
    scanf("%s", rating->title);
    printf("Enter movie year: ");
    scanf("%d", &rating->year);
    printf("Enter MPAA rating (G, PG, PG-13, R, NC-17): ");
    scanf("%s", rating->mpaa_rating);
    printf("Enter movie rating (1.0 - 10.0): ");
    scanf("%lf", &rating->rating);
}

// Function to display a movie rating
void displayRating(struct MovieRating rating) {
    printf("\n%s (%d)\nMPAA rating: %s\nMovie rating: %.1lf/10\n", rating.title, 
        rating.year, rating.mpaa_rating, rating.rating);
}

// Function to determine if a movie is eligible for awards
bool isEligible(struct MovieRating rating) {
    if (rating.rating >= 8.0 && rating.year >= 2000) {
        return true;
    } else {
        return false;
    }
}

// Main function to test the program
int main() {
    int num_ratings;
    printf("Welcome to the Movie Rating System.\nHow many movies do you want to rate?: ");
    scanf("%d", &num_ratings);

    // Allocate memory for an array of movie ratings
    struct MovieRating *ratings = malloc(num_ratings * sizeof(struct MovieRating));

    // Loop to get ratings from user and add them to array
    int i;
    for (i = 0; i < num_ratings; i++) {
        printf("\nRating %d:", i + 1);
        getUserRating(&ratings[i]);
    }

    // Loop to display ratings and eligibility for awards
    printf("\n\nMovie Ratings:\n");
    for (i = 0; i < num_ratings; i++) {
        displayRating(ratings[i]);
        if (isEligible(ratings[i])) {
            printf("This movie is eligible for awards.\n\n");
        } else {
            printf("This movie is not eligible for awards.\n\n");
        }
    }

    // Free allocated memory
    free(ratings);

    return 0;
}