//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to print stars for a given rating
void printStars(int rating) {
  for (int i = 0; i < rating; i++) {
    printf("🌟");
  }
}

// Function to get the movie rating from the user
int getMovieRating() {
  int rating;

  printf("Rate the movie (1-5): ");
  scanf("%d", &rating);

  while (rating < 1 || rating > 5) {
    printf("Invalid rating. Please enter a rating between 1 and 5: ");
    scanf("%d", &rating);
  }

  return rating;
}

int main() {
  // Get the movie rating from the user
  int rating = getMovieRating();

  // Print the movie rating with stars
  printf("Your rating: ");
  printStars(rating);
  printf("\n");

  // Print a message based on the movie rating
  switch (rating) {
    case 1:
      printf("Meh, not worth your time.");
      break;
    case 2:
      printf("It's okay, but not great.");
      break;
    case 3:
      printf("Pretty good, but not amazing.");
      break;
    case 4:
      printf("Excellent! Definitely worth watching.");
      break;
    case 5:
      printf("A masterpiece! You must see it!");
      break;
  }

  return 0;
}