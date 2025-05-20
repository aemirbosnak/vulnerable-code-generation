//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} MovieRating;

// Get the movie rating from the user
MovieRating getMovieRating() {
    int rating;
    printf("Enter the movie rating (G, PG, PG13, R, or NC17): ");
    scanf("%d", &rating);
    return rating;
}

// Print the movie rating
void printMovieRating(MovieRating rating) {
    switch (rating) {
        case G:
            printf("G - General Audiences\n");
            break;
        case PG:
            printf("PG - Parental Guidance Suggested\n");
            break;
        case PG13:
            printf("PG13 - Parents Strongly Cautioned\n");
            break;
        case R:
            printf("R - Restricted\n");
            break;
        case NC17:
            printf("NC17 - No One 17 and Under Admitted\n");
            break;
    }
}

// Main function
int main() {
    // Get the movie rating from the user
    MovieRating rating = getMovieRating();

    // Print the movie rating
    printMovieRating(rating);

    return 0;
}