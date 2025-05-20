//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
  system("cls");
  printf("------------------------------------------------------------------------\n");
  printf("              WELCOME TO THE C ONLINE EXAMINATION SYSTEM\n");
  printf("------------------------------------------------------------------------\n");
  printf("Please enter your name: ");
  char name[20];
  scanf("%s", name);
  printf("Hello, %s, welcome to the C online examination system!\n", name);

  // Generate a random question
  char question[200] = "Write a C program to find the factorial of a number.";
  printf("Question: %s\n", question);

  // Set the time limit
  int timeLimit = 30;
  time_t startTime = time(NULL);
  time_t endTime = startTime + timeLimit;

  // Start the timer
  printf("Start timer...\n");
  while (time(NULL) < endTime)
  {
    sleep(1);
  }

  // Stop the timer
  printf("Time up!\n");

  // Check if the student has answered the question
  char answer[200];
  printf("Please enter your answer: ");
  scanf("%s", answer);

  // Evaluate the answer
  int score = 0;
  if (strcmp(answer, "The factorial of a number is the product of all the positive integers less than or equal to that number.") == 0)
  {
    score = 10;
  }
  else
  {
    score = 0;
  }

  // Print the results
  printf("Your score is: %d\n", score);
  printf("Thank you for participating in the C online examination system, %s.\n", name);

  return 0;
}