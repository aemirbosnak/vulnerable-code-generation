//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of movies and genres
#define MAX_MOVIES 100
#define MAX_GENRES 10

// Define the structure for a movie
typedef struct {
    char title[100];
    char director[100];
    char cast[200];
    int year;
    char genre[50];
    float rating;
} Movie;

// Function to read a movie from a file
bool readMovie(FILE *fp, Movie *movie) {
    if (fscanf(fp, "%s %s %s %d %s %f", movie->title, movie->director, movie->cast, &movie->year, movie->genre, &movie->rating)!= 6) {
        printf("Error: Invalid movie data\n");
        return false;
    }
    return true;
}

// Function to write a movie to a file
void writeMovie(FILE *fp, Movie movie) {
    fprintf(fp, "%s %s %s %d %s %.2f\n", movie.title, movie.director, movie.cast, movie.year, movie.genre, movie.rating);
}

// Function to sort movies by rating
void sortMovies(Movie movies[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (movies[j].rating > movies[i].rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

// Function to print a movie
void printMovie(Movie movie) {
    printf("%s (%d)\nDirector: %s\nCast: %s\nGenre: %s\nRating: %.2f\n\n", movie.title, movie.year, movie.director, movie.cast, movie.genre, movie.rating);
}

// Function to print the top rated movies
void printTopRated(Movie movies[], int n, int num) {
    printf("Top %d rated movies:\n", num);
    for (int i = 0; i < num && i < n; i++) {
        printMovie(movies[i]);
    }
}

int main() {
    // Initialize the movies array
    Movie movies[MAX_MOVIES];
    int n = 0;

    // Read movies from a file
    FILE *fp = fopen("movies.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open movies file\n");
        return 1;
    }
    while (fscanf(fp, "%s", movies[n].title)!= EOF) {
        n++;
        if (n >= MAX_MOVIES) {
            printf("Error: Too many movies\n");
            fclose(fp);
            return 1;
        }
        if (!readMovie(fp, &movies[n])) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

    // Sort the movies by rating
    sortMovies(movies, n);

    // Print the top rated movies
    int num;
    printf("How many top rated movies do you want to see? ");
    scanf("%d", &num);
    printTopRated(movies, n, num);

    return 0;
}