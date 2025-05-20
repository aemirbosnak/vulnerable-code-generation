//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main(){
  int choice, age, bpm, steps, calories, total_calories = 0, total_steps = 0, total_time = 0;
  float weight, height, bmi, total_bmi = 0;

  do{
    printf("Welcome to the Fitness Tracker!\n");
    printf("1. Calculate BMI\n");
    printf("2. Track Heart Rate\n");
    printf("3. Track Steps\n");
    printf("4. View Total Progress\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter your weight in kilograms: ");
        scanf("%f", &weight);
        printf("Enter your height in meters: ");
        scanf("%f", &height);
        bmi = weight / (height * height);
        printf("Your BMI is %.2f\n\n", bmi);
        total_bmi += bmi;
        break;

      case 2:
        printf("Enter your age: ");
        scanf("%d", &age);
        printf("Enter your resting BPM: ");
        scanf("%d", &bpm);
        printf("Enter the duration of your workout in minutes: ");
        scanf("%d", &total_time);
        calories = (age * 0.2017) - (weight * 0.09036) + (bpm * 0.6309) - 55.0969;
        printf("You burned %d calories during your workout.\n\n", calories);
        total_calories += calories;
        break;

      case 3:
        printf("Enter the number of steps you took: ");
        scanf("%d", &steps);
        printf("You took %d steps.\n\n", steps);
        total_steps += steps;
        break;

      case 4:
        printf("Your total progress:\n");
        printf("Total BMI: %.2f\n", total_bmi);
        printf("Total calories burned: %d\n", total_calories);
        printf("Total steps taken: %d\n\n", total_steps);
        break;

      case 5:
        printf("Thank you for using the Fitness Tracker!\n");
        break;

      default:
        printf("Invalid choice.\n\n");
    }
  } while(choice != 5);

  return 0;
}