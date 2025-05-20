//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    char rating[4];
    printf("Enter the movie rating (G, PG, PG13, R, or NC17): ");
    scanf("%s", rating);

    // Convert the rating to uppercase
    for (int i = 0; i < strlen(rating); i++) {
        rating[i] = toupper(rating[i]);
    }

    // Return the rating
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
        printf("Invalid rating. Please enter a valid rating.\n");
        return getRating();
    }
}

// Print the movie rating
void printRating(Rating rating) {
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
            printf("R - Restricted - Under 17 requires accompanying parent or adult guardian\n");
            break;
        case NC17:
            printf("NC17 - No One 17 and Under Admitted\n");
            break;
    }
}

// Main function
int main(void) {
    // Get the movie rating
    Rating rating = getRating();

    // Print the movie rating
    printRating(rating);

    return 0;
}