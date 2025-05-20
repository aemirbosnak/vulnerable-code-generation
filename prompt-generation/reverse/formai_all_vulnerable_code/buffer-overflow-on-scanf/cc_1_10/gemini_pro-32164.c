//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating categories
#define G       "G"
#define PG      "PG"
#define PG13    "PG-13"
#define R       "R"
#define NC17    "NC-17"

// Define the movie rating descriptions
#define G_DESC  "General audiences. All ages admitted."
#define PG_DESC "Parental guidance suggested. Some material may not be suitable for children."
#define PG13_DESC "Parents strongly cautioned. Some material may be inappropriate for children under 13."
#define R_DESC  "Restricted. Under 17 requires accompanying parent or adult guardian."
#define NC17_DESC "No one 17 and under admitted."

// Define the movie rating function
char *get_rating(int age) {
  if (age < 0) {
    return "Invalid age";
  } else if (age < 6) {
    return G;
  } else if (age < 13) {
    return PG;
  } else if (age < 17) {
    return PG13;
  } else if (age < 18) {
    return R;
  } else {
    return NC17;
  }
}

// Define the main function
int main() {
  // Get the user's age
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);

  // Get the movie rating
  char *rating = get_rating(age);

  // Print the movie rating
  printf("The movie rating is: %s\n", rating);

  // Print the movie rating description
  if (strcmp(rating, G) == 0) {
    printf("%s\n", G_DESC);
  } else if (strcmp(rating, PG) == 0) {
    printf("%s\n", PG_DESC);
  } else if (strcmp(rating, PG13) == 0) {
    printf("%s\n", PG13_DESC);
  } else if (strcmp(rating, R) == 0) {
    printf("%s\n", R_DESC);
  } else if (strcmp(rating, NC17) == 0) {
    printf("%s\n", NC17_DESC);
  } else {
    printf("Invalid rating\n");
  }

  return 0;
}