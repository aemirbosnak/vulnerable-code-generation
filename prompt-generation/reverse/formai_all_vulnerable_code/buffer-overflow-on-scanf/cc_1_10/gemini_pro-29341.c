//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Movie rating system
  // 1 - Bad
  // 2 - Ok
  // 3 - Good
  // 4 - Very good
  // 5 - Excellent

  // Get the user's input
  int rating;
  printf("Enter a rating (1-5): ");
  scanf("%d", &rating);

  // Validate the input
  if (rating < 1 || rating > 5) {
    printf("Invalid rating. Please enter a valid rating (1-5): ");
    scanf("%d", &rating);
  }

  // Print the rating
  printf("You rated the movie: ");

  switch (rating) {
    case 1:
      printf("Bad");
      break;
    case 2:
      printf("Ok");
      break;
    case 3:
      printf("Good");
      break;
    case 4:
      printf("Very good");
      break;
    case 5:
      printf("Excellent");
      break;
  }

  printf("\n");

  // Get the user's comments
  char comments[256];
  printf("Enter your comments (up to 255 characters): ");
  scanf("%s", comments);

  // Print the comments
  printf("Your comments: %s\n", comments);

  return 0;
}