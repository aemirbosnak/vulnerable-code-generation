//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store movie information
typedef struct Movie {
    char title[50];
    int year;
    float rating;
} Movie;

// Define a function to compare movies
int compareMovies(Movie a, Movie b) {
    return strcmp(a.title, b.title);
}

// Define a function to rate a movie
void rateMovie(Movie *movie) {
    printf("Enter your rating for %s (1-5): ", movie->title);
    scanf("%f", &movie->rating);
}

// Main function
int main() {
    // Create an array of movies
    Movie movies[] = {
        {"The Shawshank Redemption", 1994, 4.8},
        {"The Godfather", 1972, 4.9},
        {"The Lord of the Rings: The Fellowship of the Ring", 2001, 4.7},
        {"The Dark Knight", 2008, 4.5},
        {"The Matrix Reloaded", 2003, 4.2}
    };

    // Sort the movies in descending order by title
    qsort(movies, 5, sizeof(Movie), compareMovies);

    // Print the sorted movies
    for (int i = 0; i < 5; i++) {
        printf("%s (%d) - Rating: %.1f\n", movies[i].title, movies[i].year, movies[i].rating);
    }

    // Rate a movie
    rateMovie(&movies[2]);

    // Print the updated movie information
    printf("Updated movie information:\n");
    printf("%s (%d) - Rating: %.1f\n", movies[2].title, movies[2].year, movies[2].rating);

    return 0;
}