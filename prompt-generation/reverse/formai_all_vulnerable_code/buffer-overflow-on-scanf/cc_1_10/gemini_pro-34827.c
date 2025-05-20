//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>

// Declare the movie rating enum
enum movie_rating {
    G,
    PG,
    PG13,
    R,
    NC17
};

// Declare the function to get the movie rating
enum movie_rating get_movie_rating(void);

// Declare the function to print the movie rating
void print_movie_rating(enum movie_rating rating);

// Main function
int main(void) {
    // Get the movie rating
    enum movie_rating rating = get_movie_rating();

    // Print the movie rating
    print_movie_rating(rating);

    return 0;
}

// Function to get the movie rating
enum movie_rating get_movie_rating(void) {
    // Declare the variable to store the movie rating
    enum movie_rating rating;

    // Prompt the user to enter the movie rating
    printf("Enter the movie rating (G, PG, PG13, R, or NC17): ");

    // Get the movie rating from the user
    scanf("%s", &rating);

    // Return the movie rating
    return rating;
}

// Function to print the movie rating
void print_movie_rating(enum movie_rating rating) {
    // Print the movie rating
    switch (rating) {
        case G:
            printf("The movie is rated G.\n");
            break;
        case PG:
            printf("The movie is rated PG.\n");
            break;
        case PG13:
            printf("The movie is rated PG13.\n");
            break;
        case R:
            printf("The movie is rated R.\n");
            break;
        case NC17:
            printf("The movie is rated NC17.\n");
            break;
        default:
            printf("Invalid movie rating.\n");
            break;
    }
}