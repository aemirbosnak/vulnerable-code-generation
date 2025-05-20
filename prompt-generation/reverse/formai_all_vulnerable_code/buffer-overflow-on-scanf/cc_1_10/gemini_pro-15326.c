//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int steps;
  float distance;
  int calories;
} FitnessData;

int main() {
  // Initialize fitness data
  FitnessData data;
  data.steps = 10000;
  data.distance = 5.0;
  data.calories = 500;

  // Print fitness data
  printf("Steps: %d\n", data.steps);
  printf("Distance: %.1f km\n", data.distance);
  printf("Calories: %d\n", data.calories);

  // Allow user to update fitness data
  int choice;
  do {
    printf("\n1. Update steps\n");
    printf("2. Update distance\n");
    printf("3. Update calories\n");
    printf("4. Quit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter new steps: ");
        scanf("%d", &data.steps);
        break;
      case 2:
        printf("Enter new distance (in km): ");
        scanf("%f", &data.distance);
        break;
      case 3:
        printf("Enter new calories: ");
        scanf("%d", &data.calories);
        break;
      case 4:
        printf("Quitting fitness tracker...\n");
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  } while (choice != 4);

  return 0;
}