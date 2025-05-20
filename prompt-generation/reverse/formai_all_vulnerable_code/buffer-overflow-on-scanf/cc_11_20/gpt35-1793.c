//FormAI DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int movieRating, numOfRating, totalRating = 0, i;

  printf("Enter the number of ratings: ");
  scanf("%d", &numOfRating);

  if(numOfRating <= 0) {
    printf("Error: Invalid input\n");
    return 1; // Exit with error code
  }

  printf("\nEnter the movie ratings (out of 10):\n");

  for(i=0; i<numOfRating; i++) {
    printf("Rating %d: ", i+1);
    scanf("%d", &movieRating);

    if(movieRating < 0 || movieRating > 10) {
      printf("Error: Invalid input\n");
      return 1; // Exit with error code
    }

    totalRating += movieRating;
  }

  float averageRating = (float)totalRating / (float)numOfRating;

  printf("\n\nThe average rating is %.2f\n", averageRating);

  printf("\n\nThe movie rating is: ");

  if(averageRating >= 9.5) {
    printf("Outstanding!");
  } else if(averageRating >= 8.5) {
    printf("Excellent");
  } else if(averageRating >= 7.5) {
    printf("Very Good");
  } else if(averageRating >= 6.5) {
    printf("Good");
  } else if(averageRating >= 5.5) {
    printf("Average");
  } else if(averageRating >= 4.5) {
    printf("Below Average");
  } else {
    printf("Poor");
  }

  printf("\n\n");

  return 0; // Exit with success code
}