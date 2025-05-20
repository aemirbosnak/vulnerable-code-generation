//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the rating system
#define G  0
#define PG 1
#define PG13  2
#define R  3
#define NC17  4

// Define the movie titles
char *movies[] = {
  "Romeo and Juliet",
  "Titanic",
  "The Godfather",
  "The Dark Knight",
  "Schindler's List"
};

// Define the movie ratings
int ratings[] = {
  PG,
  PG13,
  R,
  PG13,
  R
};

// Get the user's age
int get_age() {
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);
  return age;
}

// Print the movie ratings
void print_ratings(int age) {
  for (int i = 0; i < 5; i++) {
    if (ratings[i] <= age) {
      printf("%s is rated %s.\n", movies[i], ratings[i] == G ? "G" : ratings[i] == PG ? "PG" : ratings[i] == PG13 ? "PG-13" : ratings[i] == R ? "R" : "NC-17");
    } else {
      printf("%s is not appropriate for your age.\n", movies[i]);
    }
  }
}

int main() {
  // Get the user's age
  int age = get_age();

  // Print the movie ratings
  print_ratings(age);

  return 0;
}