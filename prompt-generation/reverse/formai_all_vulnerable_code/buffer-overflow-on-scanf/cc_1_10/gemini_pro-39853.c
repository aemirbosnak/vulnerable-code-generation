//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Create a custom data type for movie ratings.
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Create a function to print a movie rating.
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

// Create a function to get a movie rating from the user.
Rating getRating() {
    int rating;

    printf("Enter a movie rating (1-5): ");
    scanf("%d", &rating);

    switch (rating) {
        case 1:
            return G;
            break;
        case 2:
            return PG;
            break;
        case 3:
            return PG13;
            break;
        case 4:
            return R;
            break;
        case 5:
            return NC17;
            break;
        default:
            printf("Invalid rating. Please enter a number between 1 and 5.");
            return getRating();
    }
}

// Create a main function to test the movie rating system.
int main() {
    Rating rating;

    // Get a movie rating from the user.
    rating = getRating();

    // Print the movie rating.
    printf("The movie rating is: ");
    printRating(rating);

    return 0;
}