//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int op, num1, num2, answer;
  int count = 0, correct = 0;
  
  printf("Welcome to the Random Arithmetic Quiz!\n\n");
  printf("You will be given a set of arithmetic questions to solve.\n");
  printf("Please choose the type of operation you want to practice.\n\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n\n");

  printf("Enter your choice: ");
  scanf("%d", &op);

  printf("\nEnter the number of questions you want to attempt: ");
  scanf("%d", &count);

  srand(time(0));

  for(int i = 0; i < count; i++) {
    num1 = rand() % 100;
    num2 = rand() % 100;
    switch(op) {
      case 1:
        printf("\n%d + %d = ", num1, num2);
        scanf("%d", &answer);
        if(answer == num1 + num2) {
          printf("Correct!");
          correct++;
        }
        else
          printf("Incorrect!");
        break;
      case 2:
        printf("\n%d - %d = ", num1, num2);
        scanf("%d", &answer);
        if(answer == num1 - num2) {
          printf("Correct!");
          correct++;
        }
        else
          printf("Incorrect!");
        break;
      case 3:
        printf("\n%d * %d = ", num1, num2);
        scanf("%d", &answer);
        if(answer == num1 * num2) {
          printf("Correct!");
          correct++;
        }
        else
          printf("Incorrect!");
        break;
      case 4:
        while(num2 == 0)
          num2 = rand() % 100;
        num1 = num1 * num2;
        printf("\n%d / %d = ", num1, num2);
        scanf("%d", &answer);
        if(answer == num1 / num2) {
          printf("Correct!");
          correct++;
        }
        else
          printf("Incorrect!");
        break;
    }
  }
  int score = (float) correct/count * 100;
  printf("\n\nYou scored %d out of %d. Your score is %d", correct, count, score);

  return 0;
}