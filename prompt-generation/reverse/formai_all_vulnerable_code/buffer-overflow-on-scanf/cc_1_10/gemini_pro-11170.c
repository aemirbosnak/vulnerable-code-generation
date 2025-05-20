//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the average rating of a movie
float calculateAverageRating(int *ratings, int numRatings) {
  float totalRating = 0.0;

  for (int i = 0; i < numRatings; i++) {
    totalRating += ratings[i];
  }

  return (totalRating / numRatings);
}

// Function to print the movie ratings in a visually appealing way
void printMovieRatings(int *ratings, int numRatings) {
  printf("\nMovie Ratings:\n");

  for (int i = 0; i < numRatings; i++) {
    printf("%d stars\n", ratings[i]);
  }
}

// Function to get the user's input for the movie ratings
void getUserInput(int *ratings, int numRatings) {
  printf("\nPlease enter the ratings for the movie:\n");

  for (int i = 0; i < numRatings; i++) {
    printf("Rating %d: ", i + 1);
    scanf("%d", &ratings[i]);
  }
}

// Main function to drive the program
int main() {
  // Define the number of ratings for the movie
  int numRatings;

  printf("Welcome to the Movie Rating System!\n");
  printf("How many ratings would you like to enter? ");
  scanf("%d", &numRatings);

  // Allocate memory for the movie ratings
  int *ratings = (int *)malloc(numRatings * sizeof(int));

  // Get the user's input for the movie ratings
  getUserInput(ratings, numRatings);

  // Calculate the average rating of the movie
  float averageRating = calculateAverageRating(ratings, numRatings);

  // Print the movie ratings in a visually appealing way
  printMovieRatings(ratings, numRatings);

  // Print the average rating of the movie
  printf("\nAverage Rating: %.2f stars\n\n", averageRating);

  // Free the memory allocated for the movie ratings
  free(ratings);

  return 0;
}