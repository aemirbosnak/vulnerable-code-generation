//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
enum rating {
    G,
    PG,
    PG13,
    R,
    NC17
};

// Get the movie rating from the user
enum rating get_rating(void) {
    int rating;
    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    scanf("%d", &rating);
    return rating;
}

// Print the movie rating
void print_rating(enum rating rating) {
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
        default:
            printf("Invalid rating\n");
            break;
    }
}

// Main function
int main(void) {
    // Get the movie rating from the user
    enum rating rating = get_rating();

    // Print the movie rating
    print_rating(rating);

    return 0;
}