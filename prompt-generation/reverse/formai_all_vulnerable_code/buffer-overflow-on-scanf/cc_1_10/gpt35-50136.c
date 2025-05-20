//FormAI DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define a movie struct to hold movie information
typedef struct movie {
  char title[50];
  char genre[20];
  int year;
  float rating;
} Movie;

// Function to prompt user for movie details
void promptForMovie(Movie *m) {
  printf("Enter the movie title: ");
  scanf("%s", m->title);
  
  printf("Enter the movie genre: ");
  scanf("%s", m->genre);
  
  printf("Enter the movie year: ");
  scanf("%d", &(m->year));
  
  printf("Enter the movie rating (out of 10): ");
  scanf("%f", &(m->rating));
}

// Function to print out all movies in the given array
void printMovies(Movie *movies, int numMovies) {
  printf("\n\nMovie List:\n");
  for (int i = 0; i < numMovies; i++) {
    printf("Title: %s\n", movies[i].title);
    printf("Genre: %s\n", movies[i].genre);
    printf("Year: %d\n", movies[i].year);
    printf("Rating: %.1f/10\n\n", movies[i].rating);
  }
}

// Function to sort the movies in the array by their rating
void sortMoviesByRating(Movie *movies, int numMovies) {
  Movie temp;
  for (int i = 0; i < numMovies; i++) {
    for (int j = i + 1; j < numMovies; j++) {
      if (movies[i].rating < movies[j].rating) {
        temp = movies[i];
        movies[i] = movies[j];
        movies[j] = temp;
      }
    }
  }
}

int main() {
  // Prompt for the number of movies to rate
  int numMovies;
  printf("Enter the number of movies to rate: ");
  scanf("%d", &numMovies);
  
  // Dynamically allocate an array of movies
  Movie *movies = malloc(sizeof(Movie) * numMovies);
  
  // Prompt for the details of each movie
  for (int i = 0; i < numMovies; i++) {
    printf("\n\nMovie %d:\n", i + 1);
    promptForMovie(&(movies[i]));
  }
  
  // Sort the movies by rating
  sortMoviesByRating(movies, numMovies);
  
  // Print out the movies in order of rating
  printMovies(movies, numMovies);
  
  // Free the dynamically allocated array
  free(movies);
  
  return 0;
}