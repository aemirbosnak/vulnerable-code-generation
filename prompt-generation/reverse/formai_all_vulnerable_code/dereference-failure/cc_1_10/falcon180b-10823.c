//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct to store movie data
typedef struct {
    char title[100];
    char director[50];
    char actors[200];
    int year;
    char genre[50];
    int rating;
} Movie;

// Function to read movie data from file
void readMovieData(FILE* fp, Movie* movies, int* numMovies) {
    char line[1000];
    char* token;
    int i = 0;

    // Read each line of the file
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into tokens
        token = strtok(line, ",");
        strcpy(movies[i].title, token);
        token = strtok(NULL, ",");
        strcpy(movies[i].director, token);
        token = strtok(NULL, ",");
        strcpy(movies[i].actors, token);
        token = strtok(NULL, ",");
        movies[i].year = atoi(token);
        token = strtok(NULL, ",");
        strcpy(movies[i].genre, token);
        token = strtok(NULL, ",");
        movies[i].rating = atoi(token);

        // Increment the number of movies read
        i++;
    }

    // Set the number of movies read
    *numMovies = i;
}

// Function to sort movies by rating
void sortMoviesByRating(Movie* movies, int numMovies) {
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

// Function to print movie data
void printMovieData(Movie* movies, int numMovies) {
    for (int i = 0; i < numMovies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Year: %d\n", movies[i].year);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %d\n\n", movies[i].rating);
    }
}

int main() {
    // Open the movie data file
    FILE* fp = fopen("movies.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read movie data from file
    Movie movies[100];
    int numMovies = 0;
    readMovieData(fp, movies, &numMovies);

    // Sort movies by rating
    sortMoviesByRating(movies, numMovies);

    // Print movie data
    printf("Movie Ratings:\n");
    printMovieData(movies, numMovies);

    // Close the movie data file
    fclose(fp);

    return 0;
}