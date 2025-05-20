//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <string.h>

struct user {
  char name[50];
  int age;
  float height;
  float weight;
  int daily_steps;
  int calories_burned; 
};

int main() {
  struct user person;
  char option;

  printf("Welcome to the C Fitness Tracker!\n");
  printf("Please enter your name: ");
  scanf("%s", person.name);
  printf("Please enter your age: ");
  scanf("%d", &person.age);
  printf("Please enter your height in meters: ");
  scanf("%f", &person.height);
  printf("Please enter your weight in kilograms: ");
  scanf("%f", &person.weight);
  
  printf("\nHi %s, your profile has been created.\n", person.name);

  while (1) {
    printf("\nPlease select an option from the menu below:\n");
    printf("1. Record Daily Steps\n");
    printf("2. Record Daily Calories\n");
    printf("3. View Daily Progress\n");
    printf("4. Exit Tracker\n");

    scanf(" %c", &option);

    switch(option) {
      case '1':
        printf("\nPlease enter the number of steps you took today: ");
        scanf("%d", &person.daily_steps);
        printf("Great work! You have recorded %d steps for the day.", person.daily_steps);
        break;

      case '2':
        printf("\nPlease enter the number of calories you burned today: ");
        scanf("%d", &person.calories_burned);
        printf("Well done! You have recorded %d calories burned for the day.", person.calories_burned);
        break;

      case '3':
        printf("\nDAILY PROGRESS\n");
        printf("Steps Taken: %d\n", person.daily_steps);
        printf("Calories Burned: %d\n", person.calories_burned);

        if (person.daily_steps >= 10000) {
          printf("You have achieved your goal of 10,000 steps!\n");
        } else {
          printf("%d steps remaining to reach your goal of 10,000.\n", 10000 - person.daily_steps);
        }

        float bmi = person.weight / (person.height * person.height);
        printf("BMI: %.2f\n", bmi);

        if (bmi < 18.5) {
          printf("Your BMI is considered underweight.\n");
        } else if (bmi >= 18.5 && bmi <= 24.9) {
          printf("Your BMI is considered healthy.\n");
        } else if (bmi >= 25 && bmi <= 29.9) {
          printf("Your BMI is considered overweight.\n");
        } else {
          printf("Your BMI is considered obese.\n");
        }

        break;

      case '4':
        printf("\nThank you for using the C Fitness Tracker!\n");
        return 0;

      default:
        printf("\nInvalid option. Please try again.\n");
        break;
    }
  }

  return 0;
}