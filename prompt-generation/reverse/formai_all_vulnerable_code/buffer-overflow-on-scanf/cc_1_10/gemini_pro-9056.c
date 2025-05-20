//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Get the rating from the user
Rating getRating(void) {
    int rating;
    printf("Enter the movie rating (1-5): ");
    scanf("%d", &rating);
    while (rating < 1 || rating > 5) {
        printf("Invalid rating. Please enter a number between 1 and 5: ");
        scanf("%d", &rating);
    }
    return rating;
}

// Print the rating
void printRating(Rating rating) {
    switch (rating) {
        case G:
            printf("G - General Audiences");
            break;
        case PG:
            printf("PG - Parental Guidance Suggested");
            break;
        case PG13:
            printf("PG-13 - Parents Strongly Cautioned");
            break;
        case R:
            printf("R - Restricted");
            break;
        case NC17:
            printf("NC-17 - No One 17 and Under Admitted");
            break;
    }
}

int main(void) {
    // Get the rating from the user
    Rating rating = getRating();

    // Print the rating
    printf("The movie rating is: ");
    printRating(rating);

    return 0;
}