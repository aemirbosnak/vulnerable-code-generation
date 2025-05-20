//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {
  // Elementary, my dear Watson!
  char input[100];
  double num1, num2, result;
  int choice;

  printf("Welcome to Sherlock's Scientific Calculator.\n");
  printf("Enter your choice:\n");
  printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square Root\n6. Logarithm\n7. Sine\n8. Cosine\n9. Tangent\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Elementary, my dear Watson! Enter your numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      result = num1 + num2;
      printf("The sum is: %.2lf\n", result);
      break;
    case 2:
      printf("Elementary, my dear Watson! Enter your numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      result = num1 - num2;
      printf("The difference is: %.2lf\n", result);
      break;
    case 3:
      printf("Elementary, my dear Watson! Enter your numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      result = num1 * num2;
      printf("The product is: %.2lf\n", result);
      break;
    case 4:
      printf("Elementary, my dear Watson! Enter your numbers:\n");
      scanf("%lf %lf", &num1, &num2);
      result = num1 / num2;
      printf("The quotient is: %.2lf\n", result);
      break;
    case 5:
      printf("Elementary, my dear Watson! Enter your number:\n");
      scanf("%lf", &num1);
      result = sqrt(num1);
      printf("The square root is: %.2lf\n", result);
      break;
    case 6:
      printf("Elementary, my dear Watson! Enter your number:\n");
      scanf("%lf", &num1);
      result = log(num1);
      printf("The logarithm is: %.2lf\n", result);
      break;
    case 7:
      printf("Elementary, my dear Watson! Enter your angle in radians:\n");
      scanf("%lf", &num1);
      result = sin(num1);
      printf("The sine is: %.2lf\n", result);
      break;
    case 8:
      printf("Elementary, my dear Watson! Enter your angle in radians:\n");
      scanf("%lf", &num1);
      result = cos(num1);
      printf("The cosine is: %.2lf\n", result);
      break;
    case 9:
      printf("Elementary, my dear Watson! Enter your angle in radians:\n");
      scanf("%lf", &num1);
      result = tan(num1);
      printf("The tangent is: %.2lf\n", result);
      break;
    default:
      printf("Invalid choice. Try again, my dear Watson.\n");
      break;
  }
}