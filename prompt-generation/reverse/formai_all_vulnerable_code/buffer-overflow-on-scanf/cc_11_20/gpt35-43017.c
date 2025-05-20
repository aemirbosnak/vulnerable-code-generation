//FormAI DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){

  // initialize variables
  int input, num1, num2, userAnswer, correctAnswer, answer, difficulty;
  float percentage;
  
  // seed the random number generator with current time
  srand(time(NULL));

  // print welcome message and instructions
  printf("*** WELCOME TO MATH EXERCISE PROGRAM ***\n");
  printf("The program will generate a random math operation with numbers to test your skills\n\n");
  
  // get the level of difficulty from the user
  printf("Enter Difficulty Level: \n");
  printf("1) Easy\n");
  printf("2) Medium\n");
  printf("3) Hard\n");
  scanf("%d", &difficulty);
  
  // set the maximum value for the random numbers based on difficulty level
  if (difficulty == 1){
    num1 = rand() % 10;
    num2 = rand() % 10;
  } else if (difficulty == 2){
    num1 = rand() % 50;
    num2 = rand() % 50;
  } else {
    num1 = rand() % 100;
    num2 = rand() % 100;
  }
  
  // generate random math operation
  input = rand() % 4;
  
  // perform the math operation and set the correct answer
  if(input == 0){
      answer = num1 + num2;
      printf("%d + %d = ", num1, num2);
  } else if(input == 1){
      answer = num1 * num2;
      printf("%d * %d = ", num1, num2);
  } else if(input == 2){
      answer = num1 / num2;
      printf("%d / %d = ", num1, num2);
  } else {
      answer = num1 - num2;
      printf("%d - %d = ", num1, num2);
  }

  // prompt user for the answer
  scanf("%d", &userAnswer);
  
  // check if the answer is correct
  if (userAnswer == answer){
    printf("Correct!\n");
    correctAnswer = 1;
  } else {
    printf("Incorrect!\n");
    correctAnswer = 0;
  }
  
  // calculate and print score percentage
  percentage = (float)correctAnswer / 1 * 100;
  printf("Your current score is: %.2f%%\n", percentage);
  
  // prompt user to continue with another exercise
  printf("Would you like to continue with another exercise? (Enter 1 for Yes, 0 for No): ");
  
  // get user input for continuing with exercise
  int keepGoing;
  scanf("%d", &keepGoing);

  while (keepGoing == 1){
      
      // set the maximum value for the random numbers based on difficulty level
      if (difficulty == 1){
        num1 = rand() % 10;
        num2 = rand() % 10;
      } else if (difficulty == 2){
        num1 = rand() % 50;
        num2 = rand() % 50;
      } else {
        num1 = rand() % 100;
        num2 = rand() % 100;
      }
      
      // generate random math operation
      input = rand() % 4;
      
      // perform the math operation and set the correct answer
      if(input == 0){
          answer = num1 + num2;
          printf("%d + %d = ", num1, num2);
      } else if(input == 1){
          answer = num1 * num2;
          printf("%d * %d = ", num1, num2);
      } else if(input == 2){
          answer = num1 / num2;
          printf("%d / %d = ", num1, num2);
      } else {
          answer = num1 - num2;
          printf("%d - %d = ", num1, num2);
      }
      
      // prompt user for the answer
      scanf("%d", &userAnswer);
      
      // check if the answer is correct
      if (userAnswer == answer){
        printf("Correct!\n");
        correctAnswer++;
      } else {
        printf("Incorrect!\n");
      }
      
      // calculate and print score percentage
      percentage = (float)correctAnswer / (float)(correctAnswer + 1) * 100;
      printf("Your score is: %.2f%%\n", percentage);
      
      
      // prompt user to continue with another exercise
      printf("Would you like to continue with another exercise? (Enter 1 for Yes, 0 for No): ");
      
      // get user input for continuing with exercise
      scanf("%d", &keepGoing);
  }
  
  // print final score percentage and goodbye message
  percentage = (float)correctAnswer / (float)(correctAnswer + 1) * 100;
  printf("Your Final Score is: %.2f%%\n", percentage);
  printf("Thank you for using this Math Exercise Program!\n");
  
  return 0;
}