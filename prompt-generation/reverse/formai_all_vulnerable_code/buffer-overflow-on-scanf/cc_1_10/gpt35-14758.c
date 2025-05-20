//FormAI DATASET v1.0 Category: Movie Rating System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int numReviews = 0; // Number of movie reviews
int ratings[5] = {0, 0, 0, 0, 0}; // Number of reviews for each rating (out of 5)

// Function to get user's movie rating
int getRating() {
  int rating;
  printf("Please rate the movie out of 5: ");
  scanf("%d", &rating);

  if (rating < 1 || rating > 5) { // Invalid rating entered
    printf("Invalid rating. Please enter a number between 1 and 5.\n");
    rating = getRating(); // Try again
  }

  return rating;
}

// Function to display movie rating statistics
void displayStats() {
  printf("Total number of reviews: %d\n", numReviews);
  for (int i = 0; i < 5; i++) {
    printf("%d star reviews: %d\n", i+1, ratings[i]);
  }
}

int main() {
  char review[100]; // Placeholder for user's movie review
  int rating;

  printf("Welcome to the C Movie Rating System!\n\n");

  while (1) { // Loop until user quits
    printf("Please enter your movie review (or type 'quit' to exit):\n");
    scanf("%99[^\n]", review);
    getchar(); // Clear input buffer

    if (strcmp(review, "quit") == 0) { // User wants to quit
      printf("\nThank you for using the C Movie Rating System!\n\n");
      break;
    }
    else { // User wants to submit a review
      rating = getRating();
      printf("You gave the movie a %d out of 5 rating.\n", rating);
      ratings[rating-1]++;
      numReviews++;

      printf("Thank you for your review!\n\n");
    }
  }

  displayStats(); // Display rating statistics

  return 0;
}