//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} MovieRating;

// Get the movie rating from the user
MovieRating getMovieRating(char *rating) {
    if (strcmp(rating, "G") == 0) {
        return G;
    } else if (strcmp(rating, "PG") == 0) {
        return PG;
    } else if (strcmp(rating, "PG13") == 0) {
        return PG13;
    } else if (strcmp(rating, "R") == 0) {
        return R;
    } else if (strcmp(rating, "NC17") == 0) {
        return NC17;
    } else {
        // Invalid rating
        return -1;
    }
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
            printf("PG-13 - Parents Strongly Cautioned\n");
            break;
        case R:
            printf("R - Restricted\n");
            break;
        case NC17:
            printf("NC-17 - No One 17 and Under Admitted\n");
            break;
        default:
            printf("Invalid rating\n");
    }
}

// Main function
int main() {
    // Get the movie title from the user
    char title[100];
    printf("Enter the movie title: ");
    gets(title);

    // Get the movie rating from the user
    char rating[10];
    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    gets(rating);

    // Convert the movie rating to an enum
    MovieRating movieRating = getMovieRating(rating);

    // Print the movie rating
    printf("The movie rating for %s is: ", title);
    printMovieRating(movieRating);

    return 0;
}