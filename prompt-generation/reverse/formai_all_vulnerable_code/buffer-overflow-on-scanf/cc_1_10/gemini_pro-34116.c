//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the movie rating system
#define NUM_RATINGS 5
#define MIN_RATING 1
#define MAX_RATING 5

// Define the movie rating categories
#define EXCELLENT 5
#define GOOD 4
#define FAIR 3
#define POOR 2
#define BAD 1

// Define the movie rating weights
#define EXCELLENT_WEIGHT 5
#define GOOD_WEIGHT 4
#define FAIR_WEIGHT 3
#define POOR_WEIGHT 2
#define BAD_WEIGHT 1

// Calculate the average movie rating
double calculate_average_rating(int ratings[], int num_ratings) {
  double sum = 0.0;
  for (int i = 0; i < num_ratings; i++) {
    sum += ratings[i];
  }
  return sum / num_ratings;
}

// Calculate the weighted average movie rating
double calculate_weighted_average_rating(int ratings[], int num_ratings) {
  double sum = 0.0;
  for (int i = 0; i < num_ratings; i++) {
    sum += ratings[i] * (i + 1);
  }
  return sum / num_ratings;
}

// Calculate the standard deviation of the movie ratings
double calculate_standard_deviation(int ratings[], int num_ratings) {
  double mean = calculate_average_rating(ratings, num_ratings);
  double sum_of_squared_differences = 0.0;
  for (int i = 0; i < num_ratings; i++) {
    sum_of_squared_differences += pow((ratings[i] - mean), 2);
  }
  return sqrt(sum_of_squared_differences / num_ratings);
}

// Calculate the movie rating category
int calculate_movie_rating_category(double average_rating) {
  if (average_rating >= EXCELLENT) {
    return EXCELLENT;
  } else if (average_rating >= GOOD) {
    return GOOD;
  } else if (average_rating >= FAIR) {
    return FAIR;
  } else if (average_rating >= POOR) {
    return POOR;
  } else {
    return BAD;
  }
}

// Print the movie rating system
void print_movie_rating_system() {
  printf("Movie Rating System:\n");
  printf("---------------------\n");
  printf("Rating | Weight\n");
  printf("-------|--------\n");
  printf("5      | 5\n");
  printf("4      | 4\n");
  printf("3      | 3\n");
  printf("2      | 2\n");
  printf("1      | 1\n");
}

// Get the movie ratings from the user
void get_movie_ratings(int ratings[], int num_ratings) {
  printf("Please enter the movie ratings (1-5):\n");
  for (int i = 0; i < num_ratings; i++) {
    scanf("%d", &ratings[i]);
  }
}

// Print the movie rating results
void print_movie_rating_results(double average_rating, double weighted_average_rating, double standard_deviation, int movie_rating_category) {
  printf("Movie Rating Results:\n");
  printf("---------------------\n");
  printf("Average Rating: %.2f\n", average_rating);
  printf("Weighted Average Rating: %.2f\n", weighted_average_rating);
  printf("Standard Deviation: %.2f\n", standard_deviation);
  printf("Movie Rating Category: %d\n", movie_rating_category);
}

// Main function
int main() {
  // Print the movie rating system
  print_movie_rating_system();

  // Get the movie ratings from the user
  int ratings[NUM_RATINGS];
  get_movie_ratings(ratings, NUM_RATINGS);

  // Calculate the average movie rating
  double average_rating = calculate_average_rating(ratings, NUM_RATINGS);

  // Calculate the weighted average movie rating
  double weighted_average_rating = calculate_weighted_average_rating(ratings, NUM_RATINGS);

  // Calculate the standard deviation of the movie ratings
  double standard_deviation = calculate_standard_deviation(ratings, NUM_RATINGS);

  // Calculate the movie rating category
  int movie_rating_category = calculate_movie_rating_category(average_rating);

  // Print the movie rating results
  print_movie_rating_results(average_rating, weighted_average_rating, standard_deviation, movie_rating_category);

  return 0;
}