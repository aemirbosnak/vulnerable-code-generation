//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>

// Define the movie rating system
#define G 0
#define PG 1
#define PG13 2
#define R 3
#define NC17 4

// Get the movie rating from the user
int getMovieRating() {
  int rating;
  printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
  scanf("%d", &rating);
  return rating;
}

// Print the movie rating
void printMovieRating(int rating) {
  switch (rating) {
    case G:
      printf("The movie is rated G.\n");
      break;
    case PG:
      printf("The movie is rated PG.\n");
      break;
    case PG13:
      printf("The movie is rated PG13.\n");
      break;
    case R:
      printf("The movie is rated R.\n");
      break;
    case NC17:
      printf("The movie is rated NC17.\n");
      break;
    default:
      printf("Invalid rating.\n");
  }
}

// Main function
int main() {
  // Get the movie rating from the user
  int rating = getMovieRating();

  // Print the movie rating
  printMovieRating(rating);

  return 0;
}