//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: immersive
// Movie Rating System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold movie details
typedef struct {
  char title[50];
  int rating;
} movie;

// Function to add a new movie
void addMovie(movie movies[], int *numMovies) {
  // Ask for movie title
  printf("Enter movie title: ");
  scanf("%s", movies[*numMovies].title);

  // Ask for movie rating
  printf("Enter movie rating: ");
  scanf("%d", &movies[*numMovies].rating);

  // Increment number of movies
  *numMovies += 1;
}

// Function to search for a movie
movie *searchMovie(movie movies[], int numMovies, char title[]) {
  // Search for the movie in the array
  for (int i = 0; i < numMovies; i++) {
    if (strcmp(movies[i].title, title) == 0) {
      return &movies[i];
    }
  }

  // If movie not found, return NULL
  return NULL;
}

// Function to display all movies
void displayMovies(movie movies[], int numMovies) {
  // Display all movies
  for (int i = 0; i < numMovies; i++) {
    printf("%s - %d\n", movies[i].title, movies[i].rating);
  }
}

// Function to sort movies by rating
void sortMovies(movie movies[], int numMovies) {
  // Bubble sort algorithm
  for (int i = 0; i < numMovies; i++) {
    for (int j = 0; j < numMovies - 1; j++) {
      if (movies[j].rating > movies[j + 1].rating) {
        movie temp = movies[j];
        movies[j] = movies[j + 1];
        movies[j + 1] = temp;
      }
    }
  }
}

int main() {
  // Array to hold movies
  movie movies[100];
  int numMovies = 0;

  // Add a few movies
  addMovie(movies, &numMovies);
  addMovie(movies, &numMovies);
  addMovie(movies, &numMovies);

  // Search for a movie
  movie *foundMovie = searchMovie(movies, numMovies, "The Shawshank Redemption");
  if (foundMovie != NULL) {
    printf("Movie found: %s - %d\n", foundMovie->title, foundMovie->rating);
  } else {
    printf("Movie not found\n");
  }

  // Display all movies
  displayMovies(movies, numMovies);

  // Sort movies by rating
  sortMovies(movies, numMovies);

  // Display all movies again
  displayMovies(movies, numMovies);

  return 0;
}