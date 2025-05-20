//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
// Welcome to the Neon City Movie Rating System!

#include <stdio.h>
#include <stdlib.h>

// Cyberpunk-themed rating system categories
#define NEON_PUNK 1
#define TECHNOIR 2
#define CYBERTHRILLER 3
#define BIOPUNK 4

// Initialize the movie ratings
int neon_punk = 0;
int technoir = 0;
int cyberthriller = 0;
int biopunk = 0;

// Rate the movie based on user input
void rateMovie() {
  int rating;
  char input[10];

  printf("\nRate the movie on a scale of 1 to 5:\n");
  printf("[1] Neon Punk\n[2] Tech Noir\n[3] Cyber Thriller\n[4] Bio Punk\n");
  printf("Enter your rating: ");
  scanf("%s", input);

  rating = atoi(input);

  switch (rating) {
    case NEON_PUNK:
      neon_punk++;
      printf("Neon Punk rating increased!\n");
      break;
    case TECHNOIR:
      technoir++;
      printf("Tech Noir rating increased!\n");
      break;
    case CYBERTHRILLER:
      cyberthriller++;
      printf("Cyber Thriller rating increased!\n");
      break;
    case BIOPUNK:
      biopunk++;
      printf("Bio Punk rating increased!\n");
      break;
    default:
      printf("Invalid rating. Please enter a number between 1 and 4.\n");
      break;
  }
}

// Display the current ratings
void displayRatings() {
  printf("\nCurrent Movie Ratings:\n");
  printf("Neon Punk: %d\n", neon_punk);
  printf("Tech Noir: %d\n", technoir);
  printf("Cyber Thriller: %d\n", cyberthriller);
  printf("Bio Punk: %d\n", biopunk);
}

// Main function
int main() {
  // Cyberpunk-themed welcome message
  printf("\nWelcome to the Neon City Movie Rating System, where the streets are lit by neon and the ratings are as sharp as a katana!\n");

  // Rate the movie
  rateMovie();

  // Display the current ratings
  displayRatings();

  return 0;
}