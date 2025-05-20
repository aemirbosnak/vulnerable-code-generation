//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <math.h>

int main() {

  int mode;
  double input1, input2, result;

  printf("Welcome to the futuristic scientific calculator!\n\n");

  printf("Please select mode of operation: \n 1. Basic calculations \n 2. Trigonometry \n 3. Logarithms \n");
  scanf("%d", &mode);

  switch(mode) {
    case 1:
      printf("\nYou have selected Basic calculations. \n\n");
      printf("Please enter the first number: ");
      scanf("%lf", &input1);
      printf("Please enter the second number: ");
      scanf("%lf", &input2);

      printf("\nPlease select operation: \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division \n");
      int operation;
      scanf("%d", &operation);

      switch(operation) {
        case 1:
          result = input1 + input2;
          printf("\nThe result of %.2lf + %.2lf is: %.2lf\n", input1, input2, result);
          break;
        case 2:
          result = input1 - input2;
          printf("\nThe result of %.2lf - %.2lf is: %.2lf\n", input1, input2, result);
          break;
        case 3:
          result = input1 * input2;
          printf("\nThe result of %.2lf * %.2lf is: %.2lf\n", input1, input2, result);
          break;
        case 4:
          result = input1 / input2;
          printf("\nThe result of %.2lf / %.2lf is: %.2lf\n", input1, input2, result);
          break;
        default:
          printf("Invalid operation selected.\n");
          break;
      }
      break;

    case 2:
      printf("\nYou have selected Trigonometry.\n\n");
      printf("Please enter angle in degrees: ");
      double angle;
      scanf("%lf", &angle);

      printf("\nPlease select operation: \n 1. Sine \n 2. Cosine \n 3. Tangent \n");
      scanf("%d", &operation);

      switch(operation) {
        case 1:
          result = sin(angle * M_PI / 180);
          printf("\nThe sine of %.2lf degrees is: %.2lf\n", angle, result);
          break;
        case 2:
          result = cos(angle * M_PI / 180);
          printf("\nThe cosine of %.2lf degrees is: %.2lf\n", angle, result);
          break;
        case 3:
          result = tan(angle * M_PI / 180);
          printf("\nThe tangent of %.2lf degrees is: %.2lf\n", angle, result);
          break;
        default:
          printf("Invalid operation selected.\n");
          break;
      }
      break;

    case 3:
      printf("\nYou have selected Logarithms.\n\n");
      printf("Please enter the number: ");
      scanf("%lf", &input1);

      printf("\nPlease select operation: \n 1. Natural Logarithm \n 2. Logarithm base 10 \n");
      scanf("%d", &operation);

      switch(operation) {
        case 1:
          result = log(input1);
          printf("\nThe natural logarithm of %.2lf is: %.2lf\n", input1, result);
          break;
        case 2:
          result = log10(input1);
          printf("\nThe logarithm of %.2lf base 10 is: %.2lf\n", input1, result);
          break;
        default:
          printf("Invalid operation selected.\n");
          break;
      }
      break;

    default :
      printf("Invalid mode selected.\n");
  }

  printf("\nThank you for using our futuristic scientific calculator!\n");

  return 0;
}