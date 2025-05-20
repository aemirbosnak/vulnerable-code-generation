//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
#define G       0
#define PG      1
#define PG13    2
#define R       3
#define NC17    4

// Define the movie rating system names
char *ratingNames[] = {"G", "PG", "PG-13", "R", "NC-17"};

// Define the movie rating system descriptions
char *ratingDescriptions[] = {
    "General Audiences. All ages admitted.",
    "Parental Guidance Suggested. Some material may not be suitable for children.",
    "Parents Strongly Cautioned. Some material may be inappropriate for children under 13.",
    "Restricted. Under 17 requires accompanying parent or adult guardian.",
    "No One 17 and Under Admitted."
};

// Get the movie rating from the user
int getRating(void) {
    int rating;

    // Prompt the user to enter the movie rating
    printf("Enter the movie rating (G, PG, PG-13, R, NC-17): ");

    // Get the movie rating from the user
    scanf("%d", &rating);

    // Return the movie rating
    return rating;
}

// Print the movie rating information
void printRatingInfo(int rating) {
    // Print the movie rating name
    printf("Movie Rating: %s\n", ratingNames[rating]);

    // Print the movie rating description
    printf("Description: %s\n", ratingDescriptions[rating]);
}

// Main function
int main(void) {
    // Get the movie rating from the user
    int rating = getRating();

    // Print the movie rating information
    printRatingInfo(rating);

    // Return 0 to indicate successful execution
    return 0;
}