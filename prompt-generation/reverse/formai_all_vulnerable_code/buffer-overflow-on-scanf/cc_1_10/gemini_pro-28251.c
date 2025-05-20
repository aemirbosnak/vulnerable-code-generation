//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG_13,
    R,
    NC_17
} rating;

// Get the movie rating from the user
rating get_rating(void) {
    int rating_input;

    printf("Enter the movie rating (1-5): ");
    scanf("%d", &rating_input);

    // Convert the user input to a rating
    switch (rating_input) {
        case 1:
            return G;
        case 2:
            return PG;
        case 3:
            return PG_13;
        case 4:
            return R;
        case 5:
            return NC_17;
        default:
            printf("Invalid rating input. Please enter a number between 1 and 5.\n");
            return get_rating();
    }
}

// Print the movie rating
void print_rating(rating rating) {
    switch (rating) {
        case G:
            printf("G - General Audiences\n");
            break;
        case PG:
            printf("PG - Parental Guidance Suggested\n");
            break;
        case PG_13:
            printf("PG-13 - Parents Strongly Cautioned\n");
            break;
        case R:
            printf("R - Restricted\n");
            break;
        case NC_17:
            printf("NC-17 - No One 17 and Under Admitted\n");
            break;
    }
}

// Main function
int main(void) {
    // Get the movie rating from the user
    rating rating = get_rating();

    // Print the movie rating
    print_rating(rating);

    return 0;
}