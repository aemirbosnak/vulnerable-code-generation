//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: expert-level
// Movie Rating System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing movie details
typedef struct {
  char name[50];
  char director[50];
  int release_year;
  float rating;
} movie;

// Function for displaying movie details
void display_movie(movie* m) {
  printf("Movie Name: %s\n", m->name);
  printf("Director: %s\n", m->director);
  printf("Release Year: %d\n", m->release_year);
  printf("Rating: %f\n", m->rating);
}

// Function for adding a new movie to the system
void add_movie(movie* m) {
  printf("Enter movie name: ");
  scanf("%s", m->name);
  printf("Enter director name: ");
  scanf("%s", m->director);
  printf("Enter release year: ");
  scanf("%d", &m->release_year);
  printf("Enter rating: ");
  scanf("%f", &m->rating);
}

// Function for searching a movie by name
movie* search_movie(movie* movies[], int n, char* name) {
  for (int i = 0; i < n; i++) {
    if (strcmp(movies[i]->name, name) == 0) {
      return movies[i];
    }
  }
  return NULL;
}

// Function for sorting movies by rating
void sort_movies(movie* movies[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (movies[i]->rating < movies[j]->rating) {
        movie* temp = movies[i];
        movies[i] = movies[j];
        movies[j] = temp;
      }
    }
  }
}

// Function for displaying top 5 movies by rating
void display_top_movies(movie* movies[], int n) {
  sort_movies(movies, n);
  printf("Top 5 movies by rating:\n");
  for (int i = 0; i < 5; i++) {
    display_movie(movies[i]);
  }
}

int main() {
  movie movies[10];
  int n = 0;

  // Add movies to the system
  for (int i = 0; i < 10; i++) {
    add_movie(&movies[n++]);
  }

  // Display top 5 movies by rating
  display_top_movies(movies, n);

  // Search for a movie by name
  char name[50];
  printf("Enter movie name to search: ");
  scanf("%s", name);
  movie* m = search_movie(movies, n, name);
  if (m != NULL) {
    display_movie(m);
  } else {
    printf("Movie not found.\n");
  }

  return 0;
}