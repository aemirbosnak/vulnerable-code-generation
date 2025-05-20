//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
#define G 0
#define PG 1
#define PG13 2
#define R 3
#define NC17 4

// Define the movie titles
char *movies[] = {
  "The Shawshank Redemption",
  "The Godfather",
  "The Dark Knight",
  "12 Angry Men",
  "Schindler's List",
  "The Lord of the Rings: The Return of the King",
  "Pulp Fiction",
  "Fight Club",
  "The Matrix",
  "Saving Private Ryan"
};

// Define the movie ratings
int ratings[] = {
  PG13,
  R,
  PG13,
  PG,
  R,
  PG13,
  R,
  R,
  R,
  R
};

// Print the movie rating system
void print_rating_system() {
  printf("Movie Rating System:\n");
  printf("G: General Audiences\n");
  printf("PG: Parental Guidance Suggested\n");
  printf("PG-13: Parents Strongly Cautioned\n");
  printf("R: Restricted\n");
  printf("NC-17: No One 17 and Under Admitted\n\n");
}

// Print the movie titles and ratings
void print_movies() {
  for (int i = 0; i < 10; i++) {
    printf("%s: %s\n", movies[i], ratings[i] == G ? "G" : ratings[i] == PG ? "PG" : ratings[i] == PG13 ? "PG-13" : ratings[i] == R ? "R" : "NC-17");
  }
}

// Get the user's age
int get_age() {
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);
  return age;
}

// Get the user's movie choice
int get_movie_choice() {
  int choice;
  printf("Enter your movie choice (1-10): ");
  scanf("%d", &choice);
  return choice;
}

// Check if the movie is appropriate for the user's age
int is_appropriate(int age, int rating) {
  if (age >= 17) {
    return 1;
  } else if (age >= 13 && rating != R && rating != NC17) {
    return 1;
  } else if (age >= 5 && rating != R && rating != NC17) {
    return 1;
  } else {
    return 0;
  }
}

// Main function
int main() {
  // Print the movie rating system
  print_rating_system();

  // Print the movie titles and ratings
  print_movies();

  // Get the user's age
  int age = get_age();

  // Get the user's movie choice
  int choice = get_movie_choice();

  // Check if the movie is appropriate for the user's age
  int appropriate = is_appropriate(age, ratings[choice - 1]);

  // Print the result
  if (appropriate) {
    printf("The movie is appropriate for your age.\n");
  } else {
    printf("The movie is not appropriate for your age.\n");
  }

  return 0;
}