//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
enum rating {
    G,  // General audiences
    PG, // Parental guidance suggested
    PG13,// Parents strongly cautioned
    R,  // Restricted
    NC17// No one 17 and under admitted
};

// Function to get the rating of a movie
enum rating get_rating(void) {
    char rating;

    printf("Enter the rating of the movie (G, PG, PG13, R, NC17): ");
    scanf(" %c", &rating);

    switch (rating) {
        case 'G':
            return G;
        case 'P':
            return PG;
        case 'T':
            return PG13;
        case 'R':
            return R;
        case 'N':
            return NC17;
        default:
            printf("Invalid rating. Please enter a valid rating.\n");
            return get_rating();
    }
}

// Function to print the rating of a movie
void print_rating(enum rating rating) {
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
    }
}

// Main function
int main(void) {
    enum rating rating;

    // Get the rating of the movie
    rating = get_rating();

    // Print the rating of the movie
    print_rating(rating);

    return 0;
}