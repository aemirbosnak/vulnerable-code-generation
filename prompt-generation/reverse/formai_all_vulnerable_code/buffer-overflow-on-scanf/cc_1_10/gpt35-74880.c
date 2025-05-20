//FormAI DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Defining the struct for movie
typedef struct {
    char title[100];
    char genre[50];
    int releaseYear;
    int rating;
} Movie;

// Function to get user input for a movie
void getMovieDetails(Movie *movie) {
    printf("Enter the title of the movie: ");
    scanf("%s", movie->title);
    
    printf("Enter the genre of the movie: ");
    scanf("%s", movie->genre);
    
    printf("Enter the release year of the movie: ");
    scanf("%d", &movie->releaseYear);
    
    printf("Enter your rating for the movie (out of 10): ");
    scanf("%d", &movie->rating);
}

// Function to print the rating of a movie
void printMovieRating(Movie *movie) {
    printf("The rating for %s is %d out of 10\n", movie->title, movie->rating);
}

int main() {
    int numMovies;
    printf("How many movies would you like to rate? ");
    scanf("%d", &numMovies);
    
    // Creating an array of Movie structs
    Movie *movies = (Movie*)malloc(numMovies * sizeof(Movie));
    
    // Getting the details and ratings for each movie
    for(int i=0; i<numMovies; i++) {
        printf("\nMovie %d:\n", i+1);
        getMovieDetails(&movies[i]);
    }
    
    // Printing the rating of each movie
    printf("\nRatings:\n");
    for(int i=0; i<numMovies; i++) {
        printMovieRating(&movies[i]);
    }
    
    // Freeing the memory allocated for the Movie array
    free(movies);
    
    return 0;
}