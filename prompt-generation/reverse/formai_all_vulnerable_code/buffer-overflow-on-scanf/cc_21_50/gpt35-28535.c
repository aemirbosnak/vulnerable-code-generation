//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int choice, x, y, i, correct = 0, incorrect = 0, tries = 0, answer;
  srand(time(0));

  printf("Welcome to the Math Exercise program!\n");
  printf("-------------------------------------\n");

  do {
    printf("\nPlease choose the type of exercise you'd like to practice:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Random\n6. Exit Program\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1: // Addition
        printf("How many exercises would you like to practice? ");
        scanf("%d", &y);

        for(i = 0; i < y; i++) {
          x = rand() % 101;
          answer = rand() % 101;

          printf("\n%d + %d = ", x, answer);
          scanf("%d", &correct);

          if(correct == (x + answer)) {
            printf("Correct!\n");
            tries++;
          } else {
            printf("Incorrect. The correct answer is %d\n", (x + answer));
            incorrect++;
            tries++;
          }
        }

        printf("\nYou've completed %d addition exercises with %d correct and %d incorrect.\n", tries, (tries-incorrect), incorrect);
        break;

      case 2: // Subtraction
        printf("How many exercises would you like to practice? ");
        scanf("%d", &y);

        for(i = 0; i < y; i++) {
          x = rand() % 101;
          answer = rand() % 101;

          printf("\n%d - %d = ", x, answer);
          scanf("%d", &correct);

          if(correct == (x - answer)) {
            printf("Correct!\n");
            tries++;
          } else {
            printf("Incorrect. The correct answer is %d\n", (x - answer));
            incorrect++;
            tries++;
          }
        }

        printf("\nYou've completed %d subtraction exercises with %d correct and %d incorrect.\n", tries, (tries-incorrect), incorrect);
        break;

      case 3: // Multiplication
        printf("How many exercises would you like to practice? ");
        scanf("%d", &y);

        for(i = 0; i < y; i++) {
          x = rand() % 11;
          answer = rand() % 11;

          printf("\n%d * %d = ", x, answer);
          scanf("%d", &correct);

          if(correct == (x * answer)) {
            printf("Correct!\n");
            tries++;
          } else {
            printf("Incorrect. The correct answer is %d\n", (x * answer));
            incorrect++;
            tries++;
          }
        }

        printf("\nYou've completed %d multiplication exercises with %d correct and %d incorrect.\n", tries, (tries-incorrect), incorrect);
        break;

      case 4: // Division
        printf("How many exercises would you like to practice? ");
        scanf("%d", &y);

        for(i = 0; i < y; i++) {
          x = rand() % 101;
          while(answer == 0) {
            answer = rand() % 101;
          }

          printf("\n%d / %d = ", x, answer);
          scanf("%d", &correct);

          if(correct == (x / answer)) {
            printf("Correct!\n");
            tries++;
          } else {
            printf("Incorrect. The correct answer is %d\n", (x / answer));
            incorrect++;
            tries++;
          }

          answer = 0;
        }

        printf("\nYou've completed %d division exercises with %d correct and %d incorrect.\n", tries, (tries-incorrect), incorrect);
        break;

      case 5: // Random
        printf("How many exercises would you like to practice? ");
        scanf("%d", &y);

        for(i = 0; i < y; i++) {
          x = rand() % 101;
          answer = rand() % 101;
          int operation = rand() % 4;
          
          if(operation == 0) {
            printf("\n%d + %d = ", x, answer);
            scanf("%d", &correct);

            if(correct == (x + answer)) {
              printf("Correct!\n");
              tries++;
            } else {
              printf("Incorrect. The correct answer is %d\n", (x + answer));
              incorrect++;
              tries++;
            }
          } else if(operation == 1) {
            printf("\n%d - %d = ", x, answer);
            scanf("%d", &correct);

            if(correct == (x - answer)) {
              printf("Correct!\n");
              tries++;
            } else {
              printf("Incorrect. The correct answer is %d\n", (x - answer));
              incorrect++;
              tries++;
            }
          } else if(operation == 2) {
            printf("\n%d * %d = ", x, answer);
            scanf("%d", &correct);

            if(correct == (x * answer)) {
              printf("Correct!\n");
              tries++;
            } else {
              printf("Incorrect. The correct answer is %d\n", (x * answer));
              incorrect++;
              tries++;
            }
          } else if(operation == 3) {
            while(answer == 0) {
              answer = rand() % 101;
            }

            printf("\n%d / %d = ", x, answer);
            scanf("%d", &correct);

            if(correct == (x / answer)) {
              printf("Correct!\n");
              tries++;
            } else {
              printf("Incorrect. The correct answer is %d\n", (x / answer));
              incorrect++;
              tries++;
            }

            answer = 0;
          }
        }

        printf("\nYou've completed %d random exercises with %d correct and %d incorrect.\n", tries, (tries-incorrect), incorrect);
        break;

      case 6: // Exit Program
        printf("Thank you for using our Math Exercise program!\n");
        break;

      default:
        printf("Invalid choice. Please choose a number between 1-6.\n");
        break;
    }

  } while(choice != 6);

  return 0;
}