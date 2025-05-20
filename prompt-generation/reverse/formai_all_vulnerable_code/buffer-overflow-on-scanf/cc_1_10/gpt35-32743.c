//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  int num1, num2, ans, user_ans, count=0;
  
  srand(time(0)); // srand function is used to generate different random numbers every time

  printf("\t\t\tMATH EXERCISE PROGRAM\n");
  printf("\t\t\t---------------------");

  for(int i=1; i<=10; i++)
  {
    num1 = rand()%100 + 1; // upper limit is 100, lower limit is 1
    num2 = rand()%100 + 1; // upper limit is 100, lower limit is 1

    // Randomly select a mathematical operation
    int op = rand()%4 + 1; // upper limit is 4, lower limit is 1

    switch(op)
    {
      case 1: // Addition
        ans = num1 + num2;
        printf("\n%d) %d + %d = ? ", i, num1, num2);
        break;

      case 2: // Subtraction
        ans = num1 - num2;
        printf("\n%d) %d - %d = ? ", i, num1, num2);
        break;

      case 3: // Multiplication
        ans = num1 * num2;
        printf("\n%d) %d * %d = ? ", i, num1, num2);
        break;

      case 4: // Division
        ans = num1 / num2;
        printf("\n%d) %d / %d = ? (Round off to the nearest integer) ", i, num1, num2);
        break;

      default:
        printf("\nInvalid option");
        break;
    }

    scanf("%d", &user_ans); // user input

    if(user_ans == ans)
    {
      count++;
      printf("Correct answer!\n");
    }
    else
    {
      printf("Incorrect answer!\n");
    }
  }

  printf("\n\t\t\tRESULTS");
  printf("\n\t\t\t-------");
  printf("\n\t\t\tTotal questions = 10");
  printf("\n\t\t\tCorrect answers = %d", count);
  printf("\n\t\t\tIncorrect answers = %d", 10-count);

  if(count>=7)
  {
    printf("\n\nCongratulations! You have successfully completed the math exercise program.\n");
  }
  else
  {
    printf("\n\nKeep practicing! You need to put in more efforts to improve your math skills.\n");
  }

  return 0;
}