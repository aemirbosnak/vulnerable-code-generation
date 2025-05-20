//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
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

// Get the user's input for the movie rating
MovieRating getMovieRating() {
    char rating;
    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    scanf(" %c", &rating);

    // Convert the user's input to a MovieRating enum value
    switch (rating) {
        case 'G':
            return G;
        case 'P':
            return PG;
        case 'p':
            return PG13;
        case 'R':
            return R;
        case 'N':
            return NC17;
        default:
            printf("Invalid movie rating. Please try again.\n");
            return getMovieRating();
    }
}

// Print the movie rating in a user-friendly format
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
    }
}

// Get the user's input for the movie title
char *getMovieTitle() {
    char *title;
    int length;

    printf("Enter the movie title: ");
    scanf(" %[^\n]%*c", title);

    return title;
}

// Print the movie title in a user-friendly format
void printMovieTitle(char *title) {
    printf("Title: %s\n", title);
}

// Main function
int main() {
    // Get the user's input for the movie rating
    MovieRating rating = getMovieRating();

    // Get the user's input for the movie title
    char *title = getMovieTitle();

    // Print the movie rating and title in a user-friendly format
    printMovieRating(rating);
    printMovieTitle(title);

    return 0;
}