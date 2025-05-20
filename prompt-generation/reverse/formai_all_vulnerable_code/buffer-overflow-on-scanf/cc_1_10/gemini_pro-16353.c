//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>

// Define the minimum and maximum ratings
#define MIN_RATING 0
#define MAX_RATING 10

// Define the number of movies to rate
#define NUM_MOVIES 5

// Define the array of movie ratings
int movieRatings[NUM_MOVIES];

// Get the user's rating for a movie
int getMovieRating(int movieNumber) {
  int rating;

  // Prompt the user to enter a rating
  printf("Enter your rating for movie %d (0-10): ", movieNumber);
  scanf("%d", &rating);

  // Validate the rating
  while (rating < MIN_RATING || rating > MAX_RATING) {
    printf("Invalid rating. Please enter a rating between %d and %d: ", MIN_RATING, MAX_RATING);
    scanf("%d", &rating);
  }

  // Return the rating
  return rating;
}

// Calculate the average rating of the movies
double calculateAverageRating() {
  double averageRating = 0.0;

  // Loop through the array of movie ratings and add them up
  for (int i = 0; i < NUM_MOVIES; i++) {
    averageRating += movieRatings[i];
  }

  // Divide the sum of the ratings by the number of movies to get the average
  averageRating /= NUM_MOVIES;

  // Return the average rating
  return averageRating;
}

// Print the movie ratings and the average rating
void printMovieRatings() {
  // Print the movie ratings
  printf("Movie ratings:\n");
  for (int i = 0; i < NUM_MOVIES; i++) {
    printf("Movie %d: %d\n", i + 1, movieRatings[i]);
  }

  // Print the average rating
  printf("Average rating: %.2f\n", calculateAverageRating());
}

// Main function
int main() {
  // Get the user's ratings for each movie
  for (int i = 0; i < NUM_MOVIES; i++) {
    movieRatings[i] = getMovieRating(i + 1);
  }

  // Print the movie ratings and the average rating
  printMovieRatings();

  return 0;
}