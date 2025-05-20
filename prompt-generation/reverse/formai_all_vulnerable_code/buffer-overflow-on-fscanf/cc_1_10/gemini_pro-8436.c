//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MOVIES 100
#define MAX_CHARACTERS 50

// Structure to store movie data
typedef struct {
    char title[MAX_CHARACTERS];
    int year;
    float rating;
} Movie;

// Array to store the movie data
Movie movies[MAX_MOVIES];

// Function to read the movie data from a file
void readMoviesFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int numMovies;
    fscanf(file, "%d", &numMovies);

    for (int i = 0; i < numMovies; i++) {
        fscanf(file, "%s %d %f", movies[i].title, &movies[i].year, &movies[i].rating);
    }

    fclose(file);
}

// Function to sort the movies by rating
void sortMoviesByRating(Movie *movies, int numMovies) {
    for (int i = 0; i < numMovies - 1; i++) {
        for (int j = i + 1; j < numMovies; j++) {
            if (movies[i].rating < movies[j].rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

// Function to print the movies
void printMovies(Movie *movies, int numMovies) {
    printf("Movies sorted by rating:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s (%d) - %.1f\n", movies[i].title, movies[i].year, movies[i].rating);
    }
}

// Main function
int main() {
    readMoviesFromFile("movies.txt");

    int numMovies = sizeof(movies) / sizeof(movies[0]);

    sortMoviesByRating(movies, numMovies);

    printMovies(movies, numMovies);

    return 0;
}