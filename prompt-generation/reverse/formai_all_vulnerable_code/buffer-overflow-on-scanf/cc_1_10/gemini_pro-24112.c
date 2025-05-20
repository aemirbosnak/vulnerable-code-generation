//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the minimum and maximum ratings
#define MIN_RATING 1
#define MAX_RATING 5

// Declare the rating system configuration structure
typedef struct {
  // The minimum and maximum ratings allowed
  int min_rating;
  int max_rating;

  // The number of stars to display for each rating
  int num_stars_per_rating;

  // The character to use for displaying the stars
  char star_character;
} rating_system_config;

// Get the rating system configuration from the user
rating_system_config get_rating_system_config() {
  rating_system_config config;

  // Get the minimum rating
  printf("Enter the minimum rating: ");
  scanf("%d", &config.min_rating);

  // Get the maximum rating
  printf("Enter the maximum rating: ");
  scanf("%d", &config.max_rating);

  // Get the number of stars to display for each rating
  printf("Enter the number of stars to display for each rating: ");
  scanf("%d", &config.num_stars_per_rating);

  // Get the character to use for displaying the stars
  printf("Enter the character to use for displaying the stars: ");
  scanf(" %c", &config.star_character);

  return config;
}

// Display the rating using the specified configuration
void display_rating(float rating, rating_system_config config) {
  // Check if the rating is valid
  if (rating < config.min_rating || rating > config.max_rating) {
    fprintf(stderr, "Invalid rating: %f\n", rating);
    return;
  }

  // Calculate the number of stars to display
  int num_stars = (int) (rating * config.num_stars_per_rating);

  // Display the stars
  for (int i = 0; i < num_stars; i++) {
    printf("%c", config.star_character);
  }

  // Display the remaining stars
  for (int i = num_stars; i < config.max_rating * config.num_stars_per_rating; i++) {
    printf(" ");
  }
}

// Get the user's rating for a movie
float get_rating_for_movie(char *movie_name) {
  float rating;

  // Get the rating from the user
  printf("Enter your rating for %s (1-%d): ", movie_name, MAX_RATING);
  scanf("%f", &rating);

  return rating;
}

// Main function
int main() {
  // Get the rating system configuration from the user
  rating_system_config config = get_rating_system_config();

  // Get the user's rating for a movie
  float rating = get_rating_for_movie("The Shawshank Redemption");

  // Display the rating
  display_rating(rating, config);

  return 0;
}