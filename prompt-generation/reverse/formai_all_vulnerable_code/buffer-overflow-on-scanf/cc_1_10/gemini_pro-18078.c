//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <string.h>

// Define the movie rating categories
#define G "G"
#define PG "PG"
#define PG13 "PG-13"
#define R "R"
#define NC17 "NC-17"

// Get the movie rating from the user
char *getRating(void) {
  char *rating = malloc(3);
  printf("Enter the movie rating (G, PG, PG-13, R, NC-17): ");
  scanf("%s", rating);
  return rating;
}

// Print the movie rating information
void printRating(char *rating) {
  printf("The movie rating is: %s\n", rating);

  // Check if the rating is valid
  if (strcmp(rating, G) == 0) {
    printf("This movie is rated G, which means it is suitable for all ages.\n");
  } else if (strcmp(rating, PG) == 0) {
    printf("This movie is rated PG, which means it may contain some mild violence, language, or suggestive themes.\n");
  } else if (strcmp(rating, PG13) == 0) {
    printf("This movie is rated PG-13, which means it may contain some strong violence, language, or sexual content.\n");
  } else if (strcmp(rating, R) == 0) {
    printf("This movie is rated R, which means it may contain some strong violence, language, or sexual content that is not suitable for children.\n");
  } else if (strcmp(rating, NC17) == 0) {
    printf("This movie is rated NC-17, which means it may contain some extreme violence, language, or sexual content that is not suitable for children.\n");
  } else {
    printf("Invalid rating.\n");
  }
}

// Main function
int main(void) {
  // Get the movie rating from the user
  char *rating = getRating();

  // Print the movie rating information
  printRating(rating);

  // Free the memory allocated for the rating
  free(rating);

  return 0;
}