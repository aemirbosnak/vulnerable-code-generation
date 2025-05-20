//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
#define MOVIE_RATING_G   0
#define MOVIE_RATING_PG  1
#define MOVIE_RATING_PG13 2
#define MOVIE_RATING_R   3
#define MOVIE_RATING_NC17 4

// Define the movie rating system names
char *movie_rating_names[] = {
  "G",
  "PG",
  "PG-13",
  "R",
  "NC-17"
};

// Define the function to get the movie rating
int get_movie_rating(char *rating) {
  int i;

  for (i = 0; i < 5; i++) {
    if (strcmp(rating, movie_rating_names[i]) == 0) {
      return i;
    }
  }

  return -1;
}

// Define the function to print the movie rating
void print_movie_rating(int rating) {
  printf("The movie rating is %s.\n", movie_rating_names[rating]);
}

// Define the main function
int main(int argc, char *argv[]) {
  char *rating;
  int rating_index;

  // Get the movie rating from the user
  printf("Enter the movie rating: ");
  scanf("%s", rating);

  // Get the index of the movie rating
  rating_index = get_movie_rating(rating);

  // Print the movie rating
  print_movie_rating(rating_index);

  return 0;
}