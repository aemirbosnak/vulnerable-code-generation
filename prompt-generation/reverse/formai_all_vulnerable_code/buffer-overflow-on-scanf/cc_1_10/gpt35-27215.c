//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>

// Define constants for movie ratings
#define EXCELLENT 5
#define VERY_GOOD 4
#define GOOD 3
#define AVERAGE 2
#define POOR 1

// Declare function prototypes
int get_rating();
void print_rating(int rating);

// Main function
int main() {
  
  // Variables to hold user inputs for movie ratings
  int plot, acting, cinematography, soundtrack;
  
  // Get user inputs for movie ratings
  printf("Please rate the following aspects of the movie out of 5:\n");
  printf("Plot: ");
  plot = get_rating();
  printf("Acting: ");
  acting = get_rating();
  printf("Cinematography: ");
  cinematography = get_rating();
  printf("Soundtrack: ");
  soundtrack = get_rating();
  
  // Calculate and print overall movie rating
  int overall_rating = (plot + acting + cinematography + soundtrack) / 4;
  printf("Overall movie rating: ");
  print_rating(overall_rating);
  
  return 0;
}

// Function to get and validate user inputs for movie ratings
int get_rating() {
  int rating;
  do {
    scanf("%d", &rating);
    if (rating < POOR || rating > EXCELLENT) {
      printf("Invalid rating. Please enter a number between 1 and 5: ");
    }
  } while (rating < POOR || rating > EXCELLENT);
  return rating;
}

// Function to convert and print movie rating as a string
void print_rating(int rating) {
  switch(rating) {
    case EXCELLENT:
      printf("Excellent\n");
      break;
    case VERY_GOOD:
      printf("Very Good\n");
      break;
    case GOOD:
      printf("Good\n");
      break;
    case AVERAGE:
      printf("Average\n");
      break;
    case POOR:
      printf("Poor\n");
      break;
  }
}