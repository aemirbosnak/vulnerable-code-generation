//FormAI DATASET v1.0 Category: Movie Rating System ; Style: inquisitive
#include <stdio.h>

// Declare global variables
int ratings[10] = {0}; // Initialize array to hold movie ratings
int numRatings = 0; // Initialize variable to hold the total number of ratings
float avgRating = 0; // Initialize variable to hold the average rating

// Declare function to calculate average rating
void calcAvgRating() {
  int sum = 0;
  for (int i = 0; i < numRatings; i++) {
    sum += ratings[i];
  }
  avgRating = (float)sum / numRatings;
}

int main() {
  int choice = 0;

  printf("*** Welcome to the Movie Rating System! ***\n\n");

  while (choice != 4) {
    printf("1. See current average movie rating\n");
    printf("2. Add a new movie rating\n");
    printf("3. See all movie ratings\n");
    printf("4. Quit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (numRatings == 0) {
          printf("No ratings yet.\n");
        } else {
          printf("The current average movie rating is %.2f.\n", avgRating);
        }
        break;

      case 2:
        if (numRatings == 10) {
          printf("Maximum number of ratings reached. Cannot add more.\n");
        } else {
          int newRating = 0;
          printf("Enter the new movie rating (1-10): ");
          scanf("%d", &newRating);
          if (newRating < 1 || newRating > 10) {
            printf("Invalid rating. Please enter a number between 1 and 10.\n");
          } else {
            ratings[numRatings++] = newRating;
            calcAvgRating();
            printf("Rating added. Thank you!\n");
          }
        }
        break;

      case 3:
        if (numRatings == 0) {
          printf("No ratings yet.\n");
        } else {
          printf("All movie ratings:\n");
          for (int i = 0; i < numRatings; i++) {
            printf("%d ", ratings[i]);
          }
          printf("\n");
        }
        break;

      case 4:
        printf("Thank you for using the Movie Rating System! Goodbye!\n");
        break;

      default:
        printf("Invalid choice. Please try again.\n");
    }

    printf("\n");
  }

  return 0;
}