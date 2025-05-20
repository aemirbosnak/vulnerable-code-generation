//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: artistic
#include <stdio.h>

int main() {
  // Define the movie rating system
  enum rating {
    G,
    PG,
    PG13,
    R,
    NC17
  };

  // Get the user's input for the movie rating
  printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
  char ratingInput[4];
  scanf("%s", ratingInput);

  // Convert the user's input to an enum value
  enum rating rating;
  if (strcmp(ratingInput, "G") == 0) {
    rating = G;
  } else if (strcmp(ratingInput, "PG") == 0) {
    rating = PG;
  } else if (strcmp(ratingInput, "PG13") == 0) {
    rating = PG13;
  } else if (strcmp(ratingInput, "R") == 0) {
    rating = R;
  } else if (strcmp(ratingInput, "NC17") == 0) {
    rating = NC17;
  } else {
    printf("Invalid rating entered. Please enter a valid rating.");
    return 1;
  }

  // Print the movie rating
  printf("The movie rating is: ");
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
  }

  return 0;
}