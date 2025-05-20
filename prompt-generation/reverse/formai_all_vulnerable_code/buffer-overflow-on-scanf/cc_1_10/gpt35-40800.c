//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>

// Function prototypes
void displayMenu();
float calculateBMI(float weight, float height);

int main() {
  // Variables initialization
  int option;
  float weight, height, bmi;

  // Display menu and read option
  displayMenu();
  printf("Select an option: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
      // Read weight and height and calculate BMI
      printf("Enter your weight in kilograms: ");
      scanf("%f", &weight);
      printf("Enter your height in meters: ");
      scanf("%f", &height);
      bmi = calculateBMI(weight, height);

      // Display BMI
      printf("Your BMI is: %f\n", bmi);

      // Interpret BMI
      if(bmi < 18.5) {
        printf("You are underweight.\n");
      } else if(bmi >= 18.5 && bmi < 25) {
        printf("You are normal weight.\n");
      } else if(bmi >= 25 && bmi < 30) {
        printf("You are overweight.\n");
      } else {
        printf("You are obese.\n");
      }
      break;
    case 2:
      printf("Under development.\n");
      break;
    case 3:
      printf("Under development.\n");
      break;
    default:
      printf("Invalid option selected.\n");
      break;
  }

  return 0;
}

// Displays the menu options
void displayMenu() {
  printf("## C FITNESS TRACKER ##\n");
  printf("1. Calculate BMI\n");
  printf("2. Track calories\n");
  printf("3. Track steps\n");
}

// Calculates the BMI
float calculateBMI(float weight, float height) {
  return weight / (height * height);
}