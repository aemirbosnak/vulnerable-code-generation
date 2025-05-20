//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: careful
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
} Rating;

// Get the movie rating from the user
Rating getRating(void) {
    char input[10];
    Rating rating;

    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    scanf("%s", input);

    // Convert the input to a rating
    if (strcmp(input, "G") == 0) {
        rating = G;
    } else if (strcmp(input, "PG") == 0) {
        rating = PG;
    } else if (strcmp(input, "PG13") == 0) {
        rating = PG13;
    } else if (strcmp(input, "R") == 0) {
        rating = R;
    } else if (strcmp(input, "NC17") == 0) {
        rating = NC17;
    } else {
        printf("Invalid rating. Please enter a valid rating.");
        rating = getRating();
    }

    return rating;
}

// Print the movie rating
void printRating(Rating rating) {
    switch (rating) {
        case G:
            printf("G - General Audiences");
            break;
        case PG:
            printf("PG - Parental Guidance Suggested");
            break;
        case PG13:
            printf("PG13 - Parents Strongly Cautioned");
            break;
        case R:
            printf("R - Restricted");
            break;
        case NC17:
            printf("NC17 - No One 17 and Under Admitted");
            break;
    }
}

// Main function
int main(void) {
    // Get the movie rating from the user
    Rating rating = getRating();

    // Print the movie rating
    printRating(rating);

    return 0;
}