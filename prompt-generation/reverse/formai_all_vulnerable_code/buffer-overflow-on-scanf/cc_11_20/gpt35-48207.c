//FormAI DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //rng seed
  int a, b, answer, guess, correct = 0, incorrect = 0, choice;
  printf("Welcome to the Math Quiz!\n\n");
  do {
    printf("Select a difficulty level:\n1 - Easy\n2 - Medium\n3 - Hard\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: //easy level
        printf("\nYou have selected Easy!\n\n");
        for (int i = 0; i < 10; i++) {
          a = rand() % 10;
          b = rand() % 10;
          answer = a + b;
          printf("Question #%d: %d + %d = ", i+1, a, b);
          scanf("%d", &guess);
          if (guess == answer) {
            printf("Correct!\n");
            correct++;
          }
          else {
            printf("Incorrect! The correct answer was %d.\n", answer);
            incorrect++;
          }
        }
        break;
      case 2: //medium level
        printf("\nYou have selected Medium!\n\n");
        for (int i = 0; i < 10; i++) {
          a = rand() % 50 + 10;
          b = rand() % 50 + 10;
          answer = a - b;
          printf("Question #%d: %d - %d = ", i+1, a, b);
          scanf("%d", &guess);
          if (guess == answer) {
            printf("Correct!\n");
            correct++;
          }
          else {
            printf("Incorrect! The correct answer was %d.\n", answer);
            incorrect++;
          }
        }
        break;
      case 3: //hard level
        printf("\nYou have selected Hard!\n\n");
        for (int i = 0; i < 10; i++) {
          a = rand() % 100 + 50;
          b = rand() % 5 + 2;
          answer = a / b;
          printf("Question #%d: %d / %d = ", i+1, a, b);
          scanf("%d", &guess);
          if (guess == answer) {
            printf("Correct!\n");
            correct++;
          }
          else {
            printf("Incorrect! The correct answer was %d.\n", answer);
            incorrect++;
          }
        }
        break;
      default:
        printf("Invalid option selected! Please try again.\n");
        break;
    }
  } while (choice < 1 || choice > 3);
  //quiz summary
  printf("\n\nQuiz Summary:\nCorrect answers: %d\nIncorrect answers: %d\n", correct, incorrect);
  return 0;
}