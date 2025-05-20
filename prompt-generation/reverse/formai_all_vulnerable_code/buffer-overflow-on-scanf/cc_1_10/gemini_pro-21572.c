//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Movie rating system constants
#define RATING_G 0
#define RATING_PG 1
#define RATING_PG13 2
#define RATING_R 3
#define RATING_NC17 4

// Movie rating system descriptions
char *ratingDescriptions[] = {
  "G - General Audiences",
  "PG - Parental Guidance Suggested",
  "PG13 - Parents Strongly Cautioned",
  "R - Restricted",
  "NC17 - No One 17 and Under Admitted"
};

// Movie rating system function
int getMovieRating(char *rating) {
  int i;

  for (i = 0; i < 5; i++) {
    if (strcmp(rating, ratingDescriptions[i]) == 0) {
      return i;
    }
  }

  // Invalid rating
  return -1;
}

int main() {
  // Get the user's input
  char rating[10];
  printf("Enter the movie rating (G, PG, PG13, R, or NC17): ");
  scanf("%s", rating);

  // Get the movie rating value
  int ratingValue = getMovieRating(rating);

  // Check if the rating is valid
  if (ratingValue == -1) {
    printf("Invalid rating\n");
    return 1;
  }

  // Print the movie rating description
  printf("The movie rating is %s\n", ratingDescriptions[ratingValue]);

  return 0;
}