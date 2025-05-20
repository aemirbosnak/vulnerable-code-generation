//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int choice, num1, num2, answer, user_answer;

  // Seed the random number generator
  srand(time(NULL));

  printf("Welcome to the Math Exercise Program!\n\n");
  printf("=====================\n");
  printf("= Choose an Exercise =\n");
  printf("=====================\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("=====================\n\n");

  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Generate two random numbers
  num1 = rand() % 100;
  num2 = rand() % 100;

  switch(choice)
  {
    case 1:
      printf("%d + %d = ?\n", num1, num2);
      answer = num1 + num2;
      break;
    case 2:
      printf("%d - %d = ?\n", num1, num2);
      answer = num1 - num2;
      break;
    case 3:
      printf("%d * %d = ?\n", num1, num2);
      answer = num1 * num2;
      break;
    case 4:
      // Make sure num2 is not equal to zero
      do {
        num2 = rand() % 100;
      } while(num2 == 0);
      printf("%d / %d = ?\n", num1, num2);
      answer = num1 / num2;
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      return 0;
  }

  printf("Enter your answer: ");
  scanf("%d", &user_answer);

  if(user_answer == answer)
  {
    printf("Congratulations! Your answer is correct.\n");
  }
  else
  {
    printf("Sorry, your answer is incorrect. The correct answer is %d.\n", answer);
  }

  return 0;
}