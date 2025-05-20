//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: light-weight
/*
* movie_rating.c
* A simple movie rating system in C
*/

#include <stdio.h>

#define MAX_RATING 10
#define MIN_RATING 0

// Struct for a movie
typedef struct {
  char* title;
  int rating;
} Movie;

// Function to get the movie title from the user
char* get_movie_title() {
  char title[100];
  printf("Enter the movie title: ");
  scanf("%s", title);
  return title;
}

// Function to get the movie rating from the user
int get_movie_rating() {
  int rating;
  printf("Enter the movie rating (0 to 10): ");
  scanf("%d", &rating);
  return rating;
}

// Function to print the movie title and rating
void print_movie(Movie* movie) {
  printf("Title: %s\nRating: %d\n", movie->title, movie->rating);
}

int main() {
  // Create a movie struct
  Movie* movie = (Movie*) malloc(sizeof(Movie));

  // Get the movie title and rating from the user
  movie->title = get_movie_title();
  movie->rating = get_movie_rating();

  // Print the movie title and rating
  print_movie(movie);

  // Free the memory allocated for the movie struct
  free(movie);

  return 0;
}