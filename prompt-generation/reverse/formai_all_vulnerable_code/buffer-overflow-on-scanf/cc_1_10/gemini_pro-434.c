//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating categories
#define G             "G"
#define PG            "PG"
#define PG_13        "PG-13"
#define R             "R"
#define NC_17         "NC-17"
#define UNRATED       "Unrated"

// Define the age limit for each rating category
#define G_AGE_LIMIT   0
#define PG_AGE_LIMIT  8
#define PG_13_AGE_LIMIT  13
#define R_AGE_LIMIT   17
#define NC_17_AGE_LIMIT  18

// Get the user's age
int get_age() {
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);
  return age;
}

// Get the movie's rating
char *get_rating(int age) {
  if (age < G_AGE_LIMIT) {
    return G;
  } else if (age < PG_AGE_LIMIT) {
    return PG;
  } else if (age < PG_13_AGE_LIMIT) {
    return PG_13;
  } else if (age < R_AGE_LIMIT) {
    return R;
  } else if (age < NC_17_AGE_LIMIT) {
    return NC_17;
  } else {
    return UNRATED;
  }
}

// Print the movie's rating
void print_rating(char *rating) {
  printf("The movie's rating is %s.\n", rating);
}

// Main function
int main() {
  // Get the user's age
  int age = get_age();

  // Get the movie's rating
  char *rating = get_rating(age);

  // Print the movie's rating
  print_rating(rating);

  return 0;
}