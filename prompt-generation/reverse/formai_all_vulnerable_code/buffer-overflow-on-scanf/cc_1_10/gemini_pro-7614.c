//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Ada Lovelace
#include <stdio.h>

// Define the movie rating system
enum movie_rating {
  G,
  PG,
  PG_13,
  R,
  NC_17
};

// Define the function to get the movie rating
enum movie_rating get_movie_rating(char *rating) {
  if (strcmp(rating, "G") == 0) {
    return G;
  } else if (strcmp(rating, "PG") == 0) {
    return PG;
  } else if (strcmp(rating, "PG-13") == 0) {
    return PG_13;
  } else if (strcmp(rating, "R") == 0) {
    return R;
  } else if (strcmp(rating, "NC-17") == 0) {
    return NC_17;
  } else {
    return -1;
  }
}

// Define the function to print the movie rating
void print_movie_rating(enum movie_rating rating) {
  switch (rating) {
    case G:
      printf("G - General Audiences\n");
      break;
    case PG:
      printf("PG - Parental Guidance Suggested\n");
      break;
    case PG_13:
      printf("PG-13 - Parents Strongly Cautioned\n");
      break;
    case R:
      printf("R - Restricted\n");
      break;
    case NC_17:
      printf("NC-17 - No One 17 and Under Admitted\n");
      break;
    default:
      printf("Invalid rating\n");
      break;
  }
}

int main() {
  // Get the movie rating from the user
  char rating[3];
  printf("Enter the movie rating (G, PG, PG-13, R, NC-17): ");
  scanf("%s", rating);

  // Get the movie rating as an enum value
  enum movie_rating rating_enum = get_movie_rating(rating);

  // Print the movie rating
  print_movie_rating(rating_enum);

  return 0;
}