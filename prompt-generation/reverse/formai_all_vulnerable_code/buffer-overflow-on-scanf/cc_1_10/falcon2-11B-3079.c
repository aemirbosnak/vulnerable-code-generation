//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold movie information
typedef struct {
    char title[100];
    int year;
    char director[50];
    char genre[50];
    float rating;
} Movie;

// Function to read in movie information from user input
void read_movie(Movie* movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);
    
    printf("Enter movie year: ");
    scanf("%d", &movie->year);
    
    printf("Enter movie director: ");
    scanf("%s", movie->director);
    
    printf("Enter movie genre: ");
    scanf("%s", movie->genre);
    
    printf("Enter movie rating: ");
    scanf("%f", &movie->rating);
}

// Function to print out movie information
void print_movie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Year: %d\n", movie.year);
    printf("Director: %s\n", movie.director);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %.2f\n", movie.rating);
}

// Function to search for a movie by title
int search_movie(Movie* movies, int num_movies, char* title) {
    int i;
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            return i;
        }
    }
    return -1; // Movie not found
}

// Main function to test the movie rating system
int main() {
    Movie movies[10];
    int num_movies = 0;
    
    // Read in movie information
    printf("Enter number of movies: ");
    scanf("%d", &num_movies);
    for (int i = 0; i < num_movies; i++) {
        Movie movie;
        read_movie(&movie);
        movies[i] = movie;
    }
    
    // Search for a movie by title
    char title[100];
    printf("Enter movie title to search for: ");
    scanf("%s", title);
    int index = search_movie(movies, num_movies, title);
    
    if (index!= -1) {
        print_movie(movies[index]);
    } else {
        printf("Movie not found\n");
    }
    
    return 0;
}