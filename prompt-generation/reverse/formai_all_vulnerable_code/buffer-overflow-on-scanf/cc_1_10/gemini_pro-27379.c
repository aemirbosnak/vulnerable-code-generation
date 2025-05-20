//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Define the movie rating system
#define G 0
#define PG 1
#define PG13 2
#define R 3
#define NC17 4
#define X 5

// Define the function to get the movie rating
int getRating(char rating) {
  rating = toupper(rating);
  switch (rating) {
    case 'G':
      return G;
    case 'P':
      return PG;
    case '1':
      return PG13;
    case 'R':
      return R;
    case 'N':
      return NC17;
    case 'X':
      return X;
    default:
      return -1;
  }
}

// Define the function to print the movie rating
void printRating(int rating) {
  switch (rating) {
    case G:
      printf("G: General Audiences\n");
      break;
    case PG:
      printf("PG: Parental Guidance Suggested\n");
      break;
    case PG13:
      printf("PG-13: Parents Strongly Cautioned\n");
      break;
    case R:
      printf("R: Restricted\n");
      break;
    case NC17:
      printf("NC-17: No One 17 and Under Admitted\n");
      break;
    case X:
      printf("X: No One Under 18 Admitted\n");
      break;
    default:
      printf("Invalid rating\n");
      break;
  }
}

// Define the main function
int main() {
  // Get the movie rating
  char rating;
  printf("Enter the movie rating (G, PG, PG-13, R, NC-17, X): ");
  scanf(" %c", &rating);

  // Convert the rating to an integer
  int ratingInt = getRating(rating);

  // Print the movie rating
  printRating(ratingInt);

  return 0;
}