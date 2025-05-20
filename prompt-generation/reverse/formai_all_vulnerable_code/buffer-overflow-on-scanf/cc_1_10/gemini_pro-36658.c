//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G = 0,          // General audiences
    PG = 1,         // Parental guidance suggested
    PG13 = 2,       // Parents strongly cautioned
    R = 3,          // Restricted
    NC17 = 4        // No one 17 and under admitted
} Rating;

// Print the movie rating system
void printRatingSystem() {
    printf("Movie Rating System:\n");
    printf("G: General audiences\n");
    printf("PG: Parental guidance suggested\n");
    printf("PG13: Parents strongly cautioned\n");
    printf("R: Restricted\n");
    printf("NC17: No one 17 and under admitted\n");
}

// Get the movie rating from the user
Rating getRating() {
    int rating;

    printf("Enter the movie rating (0-4): ");
    scanf("%d", &rating);

    return rating;
}

// Print the movie rating
void printRating(Rating rating) {
    switch (rating) {
        case G:
            printf("G - General audiences\n");
            break;
        case PG:
            printf("PG - Parental guidance suggested\n");
            break;
        case PG13:
            printf("PG13 - Parents strongly cautioned\n");
            break;
        case R:
            printf("R - Restricted\n");
            break;
        case NC17:
            printf("NC17 - No one 17 and under admitted\n");
            break;
        default:
            printf("Invalid rating\n");
    }
}

// Main function
int main() {
    // Print the movie rating system
    printRatingSystem();

    // Get the movie rating from the user
    Rating rating = getRating();

    // Print the movie rating
    printRating(rating);

    return 0;
}