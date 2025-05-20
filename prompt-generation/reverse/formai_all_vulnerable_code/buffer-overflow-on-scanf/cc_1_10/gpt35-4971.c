//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  // Welcome message
  printf("Welcome to the Math Exercise Program!\n");

  // Declare variables
  int num1, num2, result, answer, i, score=0;

  // Create a random seed
  srand(time(NULL));

  // Loop through 10 questions
  for(i=1; i<=10; i++)
  {
    // Generate two random numbers between 1 and 10
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;

    // Display the question
    printf("\nQuestion #%d: What is %d + %d?\n", i, num1, num2);

    // Calculate the correct answer
    result = num1 + num2;

    // Read the user's answer
    scanf("%d", &answer);

    // Check if the answer is correct
    if(answer == result)
    {
      // Display correct message
      printf("Correct!\n");
      score++;
    }
    else
    {
      // Display incorrect message
      printf("Incorrect. The correct answer is %d.\n", result);
    }
  }

  // Display the final score
  printf("\nCongratulations! You scored %d out of 10.\n", score);

  return 0;
}