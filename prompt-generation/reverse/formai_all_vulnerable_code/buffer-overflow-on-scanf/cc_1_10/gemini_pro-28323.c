//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare the movie struct
  typedef struct Movie {
    char *title;
    int rating;
  } Movie;

  // Create an array of movies
  Movie movies[] = {
    {"The Shawshank Redemption", 9.3},
    {"The Godfather", 9.2},
    {"The Dark Knight", 9.0},
    {"12 Angry Men", 9.0},
    {"Schindler's List", 9.0},
    {"The Lord of the Rings: The Return of the King", 8.9},
    {"Pulp Fiction", 8.9},
    {"The Good, the Bad and the Ugly", 8.8},
    {"The Matrix", 8.7},
    {"Star Wars: Episode V - The Empire Strikes Back", 8.7}
  };

  // Get the number of movies
  int numMovies = sizeof(movies) / sizeof(Movie);

  // Print the movies and their ratings
  printf("Here are the top %d movies according to IMDb:\n", numMovies);
  for (int i = 0; i < numMovies; i++) {
    printf("%d. %s (%f)\n", i + 1, movies[i].title, movies[i].rating);
  }

  // Get the user's input
  printf("\nWhich movie would you like to rate (1-%d)? ", numMovies);
  int choice;
  scanf("%d", &choice);

  // Check if the user's input is valid
  if (choice < 1 || choice > numMovies) {
    printf("Invalid input. Please enter a number between 1 and %d.\n", numMovies);
    return 1;
  }

  // Get the user's rating
  printf("How would you rate this movie (1-10)? ");
  int rating;
  scanf("%d", &rating);

  // Check if the user's rating is valid
  if (rating < 1 || rating > 10) {
    printf("Invalid input. Please enter a number between 1 and 10.\n");
    return 1;
  }

  // Update the movie's rating
  movies[choice - 1].rating = (movies[choice - 1].rating + rating) / 2;

  // Print the updated rating
  printf("The new rating for %s is %f.\n", movies[choice - 1].title, movies[choice - 1].rating);

  return 0;
}