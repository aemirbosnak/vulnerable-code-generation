//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_NAME_LENGTH 50
#define MAX_RATING 10

typedef struct {
  char name[MAX_NAME_LENGTH];
  int rating;
} Movie;

int main() {
  Movie movies[MAX_MOVIES];
  int num_movies = 0;
  char input[MAX_NAME_LENGTH];
  char *token;
  char *saveptr;
  int i, rating;

  while (1) {
    printf("Enter movie name (empty line to stop): ");
    fgets(input, sizeof(input), stdin);
    if (strcmp(input, "\n") == 0) {
      break;
    }
    token = strtok_r(input, " ", &saveptr);
    if (token == NULL) {
      printf("Invalid input\n");
      continue;
    }
    strcpy(movies[num_movies].name, token);
    token = strtok_r(NULL, " ", &saveptr);
    if (token == NULL) {
      printf("Invalid input\n");
      continue;
    }
    rating = atoi(token);
    if (rating < 1 || rating > 10) {
      printf("Invalid rating\n");
      continue;
    }
    movies[num_movies].rating = rating;
    num_movies++;
  }

  printf("Movies:\n");
  for (i = 0; i < num_movies; i++) {
    printf("%s: %d\n", movies[i].name, movies[i].rating);
  }

  return 0;
}