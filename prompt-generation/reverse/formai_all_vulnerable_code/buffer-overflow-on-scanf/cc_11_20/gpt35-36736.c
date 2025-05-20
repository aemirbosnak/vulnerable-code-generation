//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  srand(time(NULL)); // set seed for random number generation
  
  int num1, num2, op, response, answer, result, tries = 0;
  double num3;
  char operator;

  printf("Welcome to the Math Exercise Program!\n");

  while (1) { // infinite loop for continuous program execution
    num1 = rand() % 101; // generate random numbers between 0-100
    num2 = rand() % 101;
    num3 = rand() / (double) RAND_MAX * 100; // generate random float between 0-100

    op = rand() % 3; // choose between addition, subtraction, and multiplication
    response = rand() % 2; // choose whether to display the result or ask for user input
    tries = 0; // reset tries counter for every new question

    switch (op) {
      case 0:
        answer = num1 + num2;
        operator = '+';
        break;
      case 1:
        answer = num1 - num2;
        operator = '-';
        break;
      case 2:
        answer = num1 * num2;
        operator = '*';
        break;
    }

    printf("\nQuestion %d: What is %d %c %d?\n", tries+1, num1, operator, num2);

    if (response) { // display the result
      printf("Press enter to see the answer.\n");
      getchar();
      printf("The answer is %d.\n", answer);
    } else { // ask for user input
      do {
        printf("Enter your answer: ");
        scanf("%d", &result);

        if (result != answer) {
          printf("Incorrect answer. Please try again.\n");
          tries++;
        }
      } while (result != answer && tries < 3); // allow up to 3 tries

      if (tries < 3) {
        printf("Correct answer. Well done!\n");
      } else {
        printf("Sorry, you have reached the maximum number of tries. The correct answer is %d.\n", answer);
      }
    }

    if (op == 0) { // perform square root operation if addition is chosen
      printf("Bonus Question: What is the square root of %.2lf?\n", num3);
      double sqrt_result = sqrt(num3);
      printf("Press enter to see the answer.\n");
      getchar();
      printf("The answer is %.2lf.\n", sqrt_result);
    }

    printf("Press enter to continue.\n");
    getchar();
  }

  return 0;
}