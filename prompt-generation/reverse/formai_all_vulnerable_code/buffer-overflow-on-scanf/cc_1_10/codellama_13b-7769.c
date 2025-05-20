//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: lively
// Movie Rating System Example Program
#include <stdio.h>
#include <stdlib.h>

// Function to check if the input is a valid rating
int isValidRating(int rating) {
  return rating >= 1 && rating <= 5;
}

// Function to print the rating
void printRating(int rating) {
  switch (rating) {
    case 1:
      printf("Rating: 1 - Horrible\n");
      break;
    case 2:
      printf("Rating: 2 - Bad\n");
      break;
    case 3:
      printf("Rating: 3 - Okay\n");
      break;
    case 4:
      printf("Rating: 4 - Good\n");
      break;
    case 5:
      printf("Rating: 5 - Excellent\n");
      break;
    default:
      printf("Invalid rating\n");
  }
}

// Function to get the user input
int getUserInput() {
  int rating;
  printf("Enter the movie rating (1-5): ");
  scanf("%d", &rating);
  return rating;
}

// Main function
int main() {
  int rating;
  rating = getUserInput();
  if (isValidRating(rating)) {
    printRating(rating);
  } else {
    printf("Invalid rating\n");
  }
  return 0;
}