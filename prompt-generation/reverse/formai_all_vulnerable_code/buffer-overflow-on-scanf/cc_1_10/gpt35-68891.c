//FormAI DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for a movie
typedef struct {
    char* title;
    char* director;
    int year;
    float rating;
} Movie;

// function to print movie details
void printMovie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Year: %d\n", movie.year);
    printf("Rating: %.1f\n", movie.rating);
}

// function to get user input for movie details
Movie getMovieInput() {
    Movie movie;

    char* title = malloc(sizeof(char) * 256);
    char* director = malloc(sizeof(char) * 256);
    int year;
    float rating;

    printf("Enter movie title: ");
    scanf(" %[^\n]s", title);
    printf("Enter movie director: ");
    scanf(" %[^\n]s", director);
    printf("Enter movie year: ");
    scanf("%d", &year);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &rating);

    movie.title = title;
    movie.director = director;
    movie.year = year;
    movie.rating = rating / 10;

    return movie;
}

// function to find the average rating of an array of movies
float getAverageRating(Movie* movies, int numMovies) {
    float sum = 0;
    for (int i = 0; i < numMovies; i++) {
        sum += movies[i].rating;
    }
    return sum / numMovies;
}

// main function
int main() {
    int numMovies;
    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    // allocate memory for movie array
    Movie* movies = malloc(sizeof(Movie) * numMovies);

    // get input for each movie and store in array
    for (int i = 0; i < numMovies; i++) {
        printf("\n");
        movies[i] = getMovieInput();
    }

    // print movie details
    printf("\nMovie Details:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("\nMovie %d:\n", i+1);
        printMovie(movies[i]);
    }

    // find and print average rating of all movies
    float avgRating = getAverageRating(movies, numMovies);
    printf("\nAverage rating of all movies: %.1f/10\n", avgRating * 10);

    // free memory allocated for movie array
    for (int i = 0; i < numMovies; i++) {
        free(movies[i].title);
        free(movies[i].director);
    }
    free(movies);

    return 0;
}