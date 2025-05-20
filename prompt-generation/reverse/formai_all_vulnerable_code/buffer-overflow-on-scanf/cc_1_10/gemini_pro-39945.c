//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} MovieRating;

// Declare the movie struct
typedef struct {
    char *title;
    MovieRating rating;
    int year;
} Movie;

// Create a new movie
Movie *createMovie(char *title, MovieRating rating, int year) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->rating = rating;
    movie->year = year;
    return movie;
}

// Print the movie information
void printMovie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: %d\n", movie->rating);
    printf("Year: %d\n\n", movie->year);
}

// Get the movie rating from the user
MovieRating getMovieRating() {
    int rating;
    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    scanf("%d", &rating);
    return rating;
}

// Get the movie title from the user
char *getMovieTitle() {
    char *title = malloc(100);
    printf("Enter the movie title: ");
    scanf("%s", title);
    return title;
}

// Get the movie year from the user
int getMovieYear() {
    int year;
    printf("Enter the movie year: ");
    scanf("%d", &year);
    return year;
}

// Main function
int main() {
    // Create a new movie
    Movie *movie = createMovie(getMovieTitle(), getMovieRating(), getMovieYear());

    // Print the movie information
    printf("Movie Information:\n");
    printMovie(movie);

    // Free the movie memory
    free(movie->title);
    free(movie);

    return 0;
}