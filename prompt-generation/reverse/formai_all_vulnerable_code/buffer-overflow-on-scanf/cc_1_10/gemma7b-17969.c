//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct Movie {
  char title[50];
  int year;
  float rating;
} Movie;

int main() {
  Movie movies[] = {
    {"The Shawshank Redemption", 1994, 9.3},
    {"The Godfather", 1972, 9.2},
    {"The Dark Knight Rises", 2008, 8.8},
    {"The Matrix Reloaded", 2003, 8.6},
    {"The Lord of the Rings: The Fellowship of the Ring", 2001, 8.2}
  };

  int numMovies = sizeof(movies) / sizeof(Movie);

  // Print movie information
  for (int i = 0; i < numMovies; i++) {
    printf("Title: %s\n", movies[i].title);
    printf("Year: %d\n", movies[i].year);
    printf("Rating: %.1f\n", movies[i].rating);
    printf("\n");
  }

  // Get user input for movie title
  char title[50];
  printf("Enter the title of the movie you want to rate: ");
  scanf("%s", title);

  // Find movie by title
  Movie *movie = NULL;
  for (int i = 0; i < numMovies; i++) {
    if (strcmp(title, movies[i].title) == 0) {
      movie = &movies[i];
      break;
    }
  }

  // If movie was found, rate it
  if (movie) {
    float rating;
    printf("Enter your rating for the movie (1-10): ");
    scanf("%f", &rating);

    movie->rating = rating;

    printf("Your rating has been saved.\n");
  } else {
    printf("Movie not found.\n");
  }

  return 0;
}