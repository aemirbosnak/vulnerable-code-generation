//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int i;
  int num1, num2;
  int answer;
  int user_answer;
  int correct_answers = 0;
  
  srand(time(NULL)); // Seed the random number generator
  
  // Generate 5 random math problems
  for(i = 0; i < 5; i++){
    num1 = rand() % 10 + 1;
    num2 = rand() % 10 + 1;
    
    // Randomly choose an operation
    int op = rand() % 4;
    
    if(op == 0){ // Addition problem
      printf("What is %d + %d? ", num1, num2);
      answer = num1 + num2;
    }
    else if(op == 1){ // Subtraction problem
      printf("What is %d - %d? ", num1, num2);
      answer = num1 - num2;
    }
    else if(op == 2){ // Multiplication problem
      printf("What is %d * %d? ", num1, num2);
      answer = num1 * num2;
    }
    else{ // Division problem
      printf("What is %d / %d? (round to nearest integer) ", num1, num2);
      answer = num1 / num2;
    }
    
    scanf("%d", &user_answer);
    
    // Check if the user's answer is correct
    if(user_answer == answer){
      printf("Correct!\n");
      correct_answers++;
    }
    else{
      printf("Incorrect. The correct answer is %d.\n", answer);
    }
    
  }
  
  printf("You got %d out of 5 correct.\n", correct_answers);
  
  return 0;
}