//FormAI DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>

// Initializing the movie ratings array
int movieRatings[10] = {0};

// Function to add movie ratings
void addRating(int rating) {
  if (rating < 0 || rating > 10) {
    printf("Invalid rating entered!\n");
  } else {
    movieRatings[rating]++;
  }
}

// Function to print movie ratings
void printRatings() {
  printf("Movie Ratings:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d: ", i);
    for (int j = 0; j < movieRatings[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
}

// Function to get average rating
float getAverageRating() {
  int totalRatings = 0;
  int numOfRatings = 0;
  for (int i = 0; i < 10; i++) {
    totalRatings += movieRatings[i] * i;
    numOfRatings += movieRatings[i];
  }
  if (numOfRatings == 0) {
    return 0;
  }
  return (float) totalRatings / numOfRatings;
}

int main() {
  int choice, rating;
  do {
    printf("1. Add rating\n");
    printf("2. Print ratings\n");
    printf("3. Get average rating\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter rating: ");
        scanf("%d", &rating);
        addRating(rating);
        break;
      case 2:
        printRatings();
        break;
      case 3:
        printf("Average rating: %.2f\n", getAverageRating());
        break;
      case 4:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid choice entered!\n");
        break;
    }
  } while (choice != 4);
  return 0;
}