//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char title[50];
  int year;
  char genre[20];
  float rating;
} Movie;

int compareMovies(const void *a, const void *b) {
  Movie *movie1 = (Movie *)a;
  Movie *movie2 = (Movie *)b;

  return strcmp(movie1->title, movie2->title);
}

int main() {
  // Initialize the database of movies
  Movie movies[] = {
    {"The Matrix", 1999, "Sci-Fi", 8.7},
    {"The Shawshank Redemption", 1994, "Drama", 9.2},
    {"The Godfather", 1972, "Crime", 9.2},
    {"The Dark Knight", 2008, "Action", 9.0},
    {"Pulp Fiction", 1994, "Crime", 8.9},
    {"Fight Club", 1999, "Drama", 8.8},
    {"Forrest Gump", 1994, "Drama", 8.8},
    {"Inception", 2010, "Sci-Fi", 8.8},
    {"Interstellar", 2014, "Sci-Fi", 8.6},
    {"The Lord of the Rings: The Return of the King", 2003, "Fantasy", 9.1}
  };

  // Sort the movies by title
  qsort(movies, sizeof(movies) / sizeof(Movie), sizeof(Movie), compareMovies);

  // Get the user's input
  char input[50];
  printf("Enter a movie title or 'exit' to quit: ");
  scanf("%s", input);

  // Search for the movie in the database
  int found = 0;
  for (int i = 0; i < sizeof(movies) / sizeof(Movie); i++) {
    if (strcmp(movies[i].title, input) == 0) {
      found = 1;

      // Print the movie's information
      printf("\nTitle: %s\n", movies[i].title);
      printf("Year: %d\n", movies[i].year);
      printf("Genre: %s\n", movies[i].genre);
      printf("Rating: %.1f\n", movies[i].rating);

      break;
    }
  }

  // If the movie was not found, print an error message
  if (!found) {
    printf("Movie not found.\n");
  }

  // Exit the program
  if (strcmp(input, "exit") == 0) {
    return 0;
  } else {
    main();
  }

  return 0;
}