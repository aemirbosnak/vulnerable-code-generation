//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu(void) {
  system("cls");
  printf("Welcome to the C Fitness Tracker!\n");
  printf("Please select an option:\n");
  printf("1. Track Heart Rate\n");
  printf("2. Monitor Blood Pressure\n");
  printf("3. Log Weight\n");
  printf("4. View Statistics\n");
  printf("Enter your selection: ");
}

int main(void) {
  display_menu();

  int selection = 0;
  scanf("%d", &selection);

  switch (selection) {
    case 1:
      printf("Enter your current heart rate: ");
      int heart_rate = 0;
      scanf("%d", &heart_rate);
      printf("Your heart rate is: %d beats per minute.\n", heart_rate);
      break;
    case 2:
      printf("Enter your blood pressure: ");
      int blood_pressure = 0;
      scanf("%d", &blood_pressure);
      printf("Your blood pressure is: %d/%d.\n", blood_pressure);
      break;
    case 3:
      printf("Enter your weight: ");
      int weight = 0;
      scanf("%d", &weight);
      printf("Your weight is: %d pounds.\n", weight);
      break;
    case 4:
      printf("Your statistics:\n");
      // Implement code to display statistics
      break;
    default:
      printf("Invalid selection.\n");
  }

  return 0;
}