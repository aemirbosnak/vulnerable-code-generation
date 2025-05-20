//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  int option;

  printf("Welcome to the expert-level C Math exercise program!\n\n");

  do {
    printf("Please select an option from the following:\n");
    printf("1. Multiply two random integers.\n");
    printf("2. Find the square root of a random float.\n");
    printf("3. Calculate the sine of a random angle.\n");
    printf("4. Quit.\n");

    scanf("%d", &option);

    switch (option) {
      case 1: {
        srand(time(0));
        int num1 = rand() % 100;
        int num2 = rand() % 100;

        printf("Multiplying %d and %d...\n", num1, num2);
        int result = num1 * num2;
        printf("Result: %d\n\n", result);
        break;
      }
      case 2: {
        srand(time(0));
        float num = (float)(rand()) / (float)(RAND_MAX);
        printf("Finding the square root of %f...\n", num);
        float result = sqrt(num);
        printf("Result: %f\n\n", result);
        break;
      }
      case 3: {
        srand(time(0));
        int angle = rand() % 360;
        printf("Calculating the sine of %d degrees...\n", angle);
        float result = sin(angle);
        printf("Result: %f\n\n", result);
        break;
      }
      case 4:
        printf("Quitting...\n");
        break;

      default:
        printf("Invalid option. Please try again.\n\n");
        break;
    }

  } while(option != 4);

  printf("Thank you for using the expert-level C Math exercise program!\n");
  return 0;
}