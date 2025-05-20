//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: genius
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

// Define the movie struct
typedef struct {
    char *title;
    MovieRating rating;
} Movie;

// Create a new movie
Movie *new_movie(char *title, MovieRating rating) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = title;
    movie->rating = rating;
    return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: ");
    switch (movie->rating) {
        case G:
            printf("G (General Audience)\n");
            break;
        case PG:
            printf("PG (Parental Guidance Suggested)\n");
            break;
        case PG13:
            printf("PG-13 (Parents Strongly Cautioned)\n");
            break;
        case R:
            printf("R (Restricted)\n");
            break;
        case NC17:
            printf("NC-17 (Adults Only)\n");
            break;
    }
}

// Get the user's input for the movie title and rating
Movie *get_user_input() {
    char *title = malloc(100);
    printf("Enter the movie title: ");
    scanf("%s", title);

    int rating;
    printf("Enter the movie rating (0 for G, 1 for PG, 2 for PG-13, 3 for R, 4 for NC-17): ");
    scanf("%d", &rating);

    return new_movie(title, rating);
}

// Main function
int main() {
    // Get the user's input for the movie
    Movie *movie = get_user_input();

    // Print the movie information
    print_movie(movie);

    // Free the memory allocated for the movie
    free(movie->title);
    free(movie);

    return 0;
}