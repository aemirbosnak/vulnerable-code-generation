//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define movie rating categories
#define G       0
#define PG      1
#define PG13    2
#define R       3
#define NC17    4

// Define movie rating descriptions
char *ratingDescriptions[] = {
    "General Audiences",
    "Parental Guidance Suggested",
    "Parents Strongly Cautioned",
    "Restricted",
    "No One 17 and Under Admitted"
};

// Get the movie rating from the user
int getMovieRating(void) {
    int rating;

    printf("Enter the movie rating (G, PG, PG13, R, or NC17): ");
    scanf("%d", &rating);

    // Validate the movie rating
    while (rating < G || rating > NC17) {
        printf("Invalid movie rating. Please enter a valid rating (G, PG, PG13, R, or NC17): ");
        scanf("%d", &rating);
    }

    return rating;
}

// Print the movie rating and description
void printMovieRating(int rating) {
    printf("Movie Rating: %s\n", ratingDescriptions[rating]);
}

int main(void) {
    int rating;

    // Get the movie rating from the user
    rating = getMovieRating();

    // Print the movie rating and description
    printMovieRating(rating);

    return 0;
}