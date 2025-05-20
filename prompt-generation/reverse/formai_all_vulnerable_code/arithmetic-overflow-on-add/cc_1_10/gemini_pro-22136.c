//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10

typedef struct {
  char title[50];
  int ratings[MAX_RATINGS];
  int num_ratings;
} movie;

int compare_movies(const void *a, const void *b) {
  const movie *movie1 = (const movie *)a;
  const movie *movie2 = (const movie *)b;

  return strcmp(movie1->title, movie2->title);
}

int main() {
  movie movies[MAX_MOVIES];
  int num_movies = 0;

  FILE *fp = fopen("movies.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  char line[100];
  while (fgets(line, sizeof(line), fp)) {
    if (num_movies == MAX_MOVIES) {
      printf("Error: too many movies.\n");
      return 1;
    }

    movie *movie = &movies[num_movies];
    sscanf(line, "%s", movie->title);

    int rating;
    for (int i = 0; i < MAX_RATINGS; i++) {
      if (fscanf(fp, "%d", &rating) != 1) {
        printf("Error reading rating.\n");
        return 1;
      }

      movie->ratings[i] = rating;
      movie->num_ratings++;
    }

    num_movies++;
  }

  fclose(fp);

  // Sort the movies by title.
  qsort(movies, num_movies, sizeof(movie), compare_movies);

  // Print the movies and their average ratings.
  for (int i = 0; i < num_movies; i++) {
    movie *movie = &movies[i];

    int sum = 0;
    for (int j = 0; j < movie->num_ratings; j++) {
      sum += movie->ratings[j];
    }

    float average = (float)sum / movie->num_ratings;

    printf("%s: %.2f\n", movie->title, average);
  }

  return 0;
}