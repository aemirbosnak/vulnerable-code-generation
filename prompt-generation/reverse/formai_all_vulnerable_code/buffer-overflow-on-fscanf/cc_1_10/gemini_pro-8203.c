//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 80
#define MAX_RATING 10

typedef struct {
  char title[MAX_TITLE];
  int rating;
} Movie;

Movie findMovieByTitle(Movie *movies, int numMovies, char *title) {
  for (int i = 0; i < numMovies; i++) {
    if (strcmp(movies[i].title, title) == 0) {
      return movies[i];
    }
  }
  Movie notFound = { "", 0 };
  return notFound;
}

int compareMovies(const void *a, const void *b) {
  Movie *movieA = (Movie *)a;
  Movie *movieB = (Movie *)b;
  return strcmp(movieA->title, movieB->title);
}

void printMovieRating(Movie movie) {
  printf("%s: %d\n", movie.title, movie.rating);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <movie title>\n", argv[0]);
    return 1;
  }

  // Load the movie database
  FILE *fp = fopen("movies.txt", "r");
  if (fp == NULL) {
    printf("Error opening movie database\n");
    return 1;
  }
  int numMovies = 0;
  fscanf(fp, "%d\n", &numMovies);
  Movie *movies = malloc(sizeof(Movie) * numMovies);
  for (int i = 0; i < numMovies; i++) {
    fscanf(fp, "%s %d\n", movies[i].title, &movies[i].rating);
  }
  fclose(fp);

  // Sort the movies by title
  qsort(movies, numMovies, sizeof(Movie), compareMovies);

  // Find the movie the user is looking for
  Movie movie = findMovieByTitle(movies, numMovies, argv[1]);
  if (strcmp(movie.title, "") == 0) {
    printf("Movie not found\n");
    return 1;
  }

  // Print the movie's rating
  printMovieRating(movie);

  return 0;
}