//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initialize variables
  int movies[5];
  float rating[5];
  int i, j;
  int highest_rating = 0;
  int lowest_rating = 5;
  int highest_index = 0;
  int lowest_index = 0;

  // Prompt user to input ratings for 5 movies
  printf("Please rate the following movies on a scale of 0-5:\n");
  for (i = 0; i < 5; i++) {
    printf("Movie %d: ", i+1);
    scanf("%d", &movies[i]);

    // Error check to ensure valid rating is input
    while (movies[i] < 0 || movies[i] > 5) {
      printf("Invalid rating. Please enter a number between 0 and 5: ");
      scanf("%d", &movies[i]);
    }
  }

  // Prompt user to input title and ratings for an additional movie
  printf("\nPlease provide the title and rating for an additional movie:\n");
  char title[20];
  printf("Movie Title: ");
  scanf("%s", title);
  printf("Movie Rating (0-5): ");
  float new_rating;
  scanf("%f", &new_rating);

  // Error check to ensure valid rating is input
  while (new_rating < 0 || new_rating > 5) {
    printf("Invalid rating. Please enter a number between 0 and 5: ");
    scanf("%f", &new_rating);
  }

  // Add the new movie title and rating to the arrays
  movies[5] = title;
  rating[5] = new_rating;

  // Calculate highest and lowest rated movies
  for (j = 0; j < 6; j++) {
    if (rating[j] > highest_rating) {
      highest_rating = rating[j];
      highest_index = j;
    }
    if (rating[j] < lowest_rating) {
      lowest_rating = rating[j];
      lowest_index = j;
    }
  }

  // Output the results
  printf("\nThe highest rated movie is %s with a rating of %.1f.\n", movies[highest_index], rating[highest_index]);
  printf("The lowest rated movie is %s with a rating of %.1f.\n", movies[lowest_index], rating[lowest_index]);

  return 0;
}