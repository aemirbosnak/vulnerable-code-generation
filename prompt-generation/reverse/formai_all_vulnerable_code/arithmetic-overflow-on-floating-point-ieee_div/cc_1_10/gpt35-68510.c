//FormAI DATASET v1.0 Category: Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* function declarations */
void displayMenu();
float addition(float num1, float num2);
float subtraction(float num1, float num2);
float multiplication(float num1, float num2);
float division(float num1, float num2);
bool checkDivisionByZero(float num2);

int main() {
  bool isRunning = true;
  int choice;
  float num1, num2, result;

  while (isRunning) {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter two numbers separated by space: ");
        scanf("%f %f", &num1, &num2);
        result = addition(num1, num2);
        printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, result);
        break;
      case 2:
        printf("Enter two numbers separated by space: ");
        scanf("%f %f", &num1, &num2);
        result = subtraction(num1, num2);
        printf("%.2f minus %.2f is %.2f\n", num1, num2, result);
        break;
      case 3:
        printf("Enter two numbers separated by space: ");
        scanf("%f %f", &num1, &num2);
        result = multiplication(num1, num2);
        printf("%.2f times %.2f is %.2f\n", num1, num2, result);
        break;
      case 4:
        printf("Enter two numbers separated by space: ");
        scanf("%f %f", &num1, &num2);
        if (checkDivisionByZero(num2)) {
          result = division(num1, num2);
          printf("%.2f divided by %.2f is %.2f\n", num1, num2, result);
        }
        else {
          printf("Error: Division by zero.\n");
        }
        break;
      case 5:
        isRunning = false;
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }

  return 0;
}

/* function definitions */

void displayMenu() {
  printf("-----------Calculator-----------\n");
  printf("1) Addition\n");
  printf("2) Subtraction\n");
  printf("3) Multiplication\n");
  printf("4) Division\n");
  printf("5) Exit\n");
}

float addition(float num1, float num2) {
  return num1 + num2;
}

float subtraction(float num1, float num2) {
  return num1 - num2;
}

float multiplication(float num1, float num2) {
  return num1 * num2;
}

float division(float num1, float num2) {
  return num1 / num2;
}

bool checkDivisionByZero(float num2) {
  if (num2 == 0) {
    return false;
  }
  return true;
}