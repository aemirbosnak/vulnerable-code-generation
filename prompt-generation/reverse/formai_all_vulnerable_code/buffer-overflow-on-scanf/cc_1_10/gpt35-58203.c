//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fitnessData {
  int calorieIntake;
  int stepsTaken;
  float weight;
  int hoursOfSleep;
} FitnessData;

void addData(FitnessData *data) {
  printf("Please add your calorie intake: ");
  scanf("%d", &data->calorieIntake);

  printf("Please add your steps taken: ");
  scanf("%d", &data->stepsTaken);

  printf("Please add your weight: ");
  scanf("%f", &data->weight);

  printf("Please add your hours of sleep: ");
  scanf("%d", &data->hoursOfSleep);
}

void displayData(FitnessData data) {
  printf("Calorie intake: %d\n", data.calorieIntake);
  printf("Steps taken: %d\n", data.stepsTaken);
  printf("Weight: %.2f\n", data.weight);
  printf("Hours of sleep: %d\n", data.hoursOfSleep);
}

void saveDataToFile(FitnessData data) {
  FILE *fptr;
  fptr = fopen("fitness_data.txt", "a");
  if (fptr == NULL) {
    printf("Error opening file.");
    exit(1);
  }
  fprintf(fptr, "%d %d %.2f %d\n", data.calorieIntake, data.stepsTaken, data.weight, data.hoursOfSleep);
  fclose(fptr);
}

int main() {
  FitnessData data;
  int choice;

  do {
    printf("\nWelcome to the Fitness Tracker!\n");
    printf("------------------------------\n");
    printf("1. Add data\n");
    printf("2. Display data\n");
    printf("3. Save data to a file\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addData(&data);
        break;

      case 2:
        displayData(data);
        break;

      case 3:
        saveDataToFile(data);
        break;

      case 4:
        printf("\nThank you for using the Fitness Tracker!");
        break;

      default:
        printf("\nInvalid choice. Please select a valid option!\n");
        break;
    }
  } while (choice != 4);

  return 0;
}