//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: surprised
/*
 * C Movie Rating System Example Program
 *
 * This program takes in a movie title and a rating from the user,
 * and then stores the movie title and rating in a file called
 * "movies.txt". The program also allows the user to view the
 * movie ratings that have been entered so far.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 256
#define MAX_RATING_LEN 16

struct movie {
  char title[MAX_TITLE_LEN];
  char rating[MAX_RATING_LEN];
};

void add_movie(struct movie movies[], int *num_movies) {
  char title[MAX_TITLE_LEN];
  char rating[MAX_RATING_LEN];

  printf("Enter the movie title: ");
  scanf("%s", title);

  printf("Enter the movie rating: ");
  scanf("%s", rating);

  strcpy(movies[*num_movies].title, title);
  strcpy(movies[*num_movies].rating, rating);

  (*num_movies)++;
}

void view_movies(struct movie movies[], int num_movies) {
  int i;

  printf("Movies:\n");
  for (i = 0; i < num_movies; i++) {
    printf("%s: %s\n", movies[i].title, movies[i].rating);
  }
}

int main() {
  struct movie movies[MAX_MOVIES];
  int num_movies = 0;
  char choice;

  while (1) {
    printf("Movie Rating System\n");
    printf("-------------------\n");
    printf("a) Add a movie\n");
    printf("v) View movies\n");
    printf("q) Quit\n");
    printf("Choice: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'a':
        add_movie(movies, &num_movies);
        break;
      case 'v':
        view_movies(movies, num_movies);
        break;
      case 'q':
        return 0;
      default:
        printf("Invalid choice\n");
        break;
    }
  }

  return 0;
}