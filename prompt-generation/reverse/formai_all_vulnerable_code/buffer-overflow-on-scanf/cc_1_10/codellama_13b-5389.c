//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: random
// Movie Rating System

#include <stdio.h>
#include <stdlib.h>

// Struct to store movie details
typedef struct {
  char title[50];
  int rating;
  int year;
} Movie;

// Function to display movie details
void displayMovie(Movie *movie) {
  printf("Movie Title: %s\n", movie->title);
  printf("Movie Rating: %d\n", movie->rating);
  printf("Movie Year: %d\n", movie->year);
}

// Function to add a new movie
void addMovie(Movie *movies, int *numMovies) {
  printf("Enter the movie title: ");
  scanf("%s", movies[*numMovies].title);
  printf("Enter the movie rating: ");
  scanf("%d", &movies[*numMovies].rating);
  printf("Enter the movie year: ");
  scanf("%d", &movies[*numMovies].year);
  *numMovies += 1;
}

// Function to display all movies
void displayMovies(Movie *movies, int numMovies) {
  for (int i = 0; i < numMovies; i++) {
    displayMovie(&movies[i]);
  }
}

// Function to search for a movie by title
Movie *searchMovieByTitle(Movie *movies, int numMovies, char *title) {
  for (int i = 0; i < numMovies; i++) {
    if (strcmp(movies[i].title, title) == 0) {
      return &movies[i];
    }
  }
  return NULL;
}

// Function to search for a movie by rating
Movie *searchMovieByRating(Movie *movies, int numMovies, int rating) {
  for (int i = 0; i < numMovies; i++) {
    if (movies[i].rating == rating) {
      return &movies[i];
    }
  }
  return NULL;
}

// Function to search for a movie by year
Movie *searchMovieByYear(Movie *movies, int numMovies, int year) {
  for (int i = 0; i < numMovies; i++) {
    if (movies[i].year == year) {
      return &movies[i];
    }
  }
  return NULL;
}

// Main function
int main() {
  // Initialize movies array and number of movies
  Movie movies[100];
  int numMovies = 0;

  // Add movies to the array
  addMovie(&movies, &numMovies);
  addMovie(&movies, &numMovies);
  addMovie(&movies, &numMovies);

  // Display all movies
  displayMovies(movies, numMovies);

  // Search for a movie by title
  Movie *movie = searchMovieByTitle(movies, numMovies, "The Shawshank Redemption");
  if (movie != NULL) {
    displayMovie(movie);
  } else {
    printf("Movie not found\n");
  }

  // Search for a movie by rating
  movie = searchMovieByRating(movies, numMovies, 9);
  if (movie != NULL) {
    displayMovie(movie);
  } else {
    printf("Movie not found\n");
  }

  // Search for a movie by year
  movie = searchMovieByYear(movies, numMovies, 1994);
  if (movie != NULL) {
    displayMovie(movie);
  } else {
    printf("Movie not found\n");
  }

  return 0;
}