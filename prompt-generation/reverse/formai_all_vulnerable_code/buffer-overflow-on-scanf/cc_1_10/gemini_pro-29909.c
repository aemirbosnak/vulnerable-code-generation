//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
#define G 0
#define PG 1
#define PG13 2
#define R 3
#define NC17 4

// Define the function to get the movie rating
int getMovieRating(char *rating) {
  // Convert the rating to uppercase
  for (int i = 0; rating[i] != '\0'; i++) {
    rating[i] = toupper(rating[i]);
  }

  // Check if the rating is valid
  if (strcmp(rating, "G") == 0) {
    return G;
  } else if (strcmp(rating, "PG") == 0) {
    return PG;
  } else if (strcmp(rating, "PG13") == 0) {
    return PG13;
  } else if (strcmp(rating, "R") == 0) {
    return R;
  } else if (strcmp(rating, "NC17") == 0) {
    return NC17;
  } else {
    return -1;
  }
}

// Define the function to print the movie rating
void printMovieRating(int rating) {
  switch (rating) {
    case G:
      printf("G - General Audiences");
      break;
    case PG:
      printf("PG - Parental Guidance Suggested");
      break;
    case PG13:
      printf("PG-13 - Parents Strongly Cautioned");
      break;
    case R:
      printf("R - Restricted");
      break;
    case NC17:
      printf("NC-17 - No One 17 and Under Admitted");
      break;
    default:
      printf("Invalid rating");
      break;
  }
}

// Define the main function
int main() {
  // Get the movie rating
  char rating[10];
  printf("Enter the movie rating: ");
  scanf("%s", rating);

  // Convert the rating to an integer
  int ratingInt = getMovieRating(rating);

  // Print the movie rating
  printMovieRating(ratingInt);

  return 0;
}