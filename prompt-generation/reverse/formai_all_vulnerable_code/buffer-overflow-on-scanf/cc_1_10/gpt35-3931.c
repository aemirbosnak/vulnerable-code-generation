//FormAI DATASET v1.0 Category: Math exercise ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){
  // Generate 2 random numbers between 1 and 50 for addition, subtraction and multiplication questions
  srand(time(NULL));
  int num1_add = rand()%50 + 1;
  int num2_add = rand()%50 + 1;

  int num1_sub = rand()%50 + 1;
  int num2_sub = rand()%50 + 1;

  int num1_mul = rand()%50 + 1;
  int num2_mul = rand()%50 + 1;

  // Display the addition question and take the user input
  printf("What is the sum of %d and %d?\n", num1_add, num2_add);
  int user_ans_add;
  scanf("%d", &user_ans_add);

  // Display the subtraction question and take the user input
  printf("What is the difference between %d and %d?\n", num1_sub, num2_sub);
  int user_ans_sub;
  scanf("%d", &user_ans_sub);

  // Display the multiplication question and take the user input
  printf("What is the product of %d and %d?\n", num1_mul, num2_mul);
  int user_ans_mul;
  scanf("%d", &user_ans_mul);

  // Calculate the correct answers for addition, subtraction and multiplication questions
  int correct_ans_add = num1_add + num2_add;
  int correct_ans_sub = num1_sub - num2_sub;
  int correct_ans_mul = num1_mul * num2_mul;

  // Check if the user's answers for addition, subtraction and multiplication questions are correct
  int score = 0;
  if(user_ans_add == correct_ans_add){
    printf("You got the addition question correct!\n");
    score += 1;
  } else {
    printf("You got the addition question wrong! The correct answer is %d\n", correct_ans_add);
  }

  if(user_ans_sub == correct_ans_sub){
    printf("You got the subtraction question correct!\n");
    score += 1;
  } else {
    printf("You got the subtraction question wrong! The correct answer is %d\n", correct_ans_sub);
  }

  if(user_ans_mul == correct_ans_mul){
    printf("You got the multiplication question correct!\n");
    score += 1;
  } else {
    printf("You got the multiplication question wrong! The correct answer is %d\n", correct_ans_mul);
  }

  // Calculate the final score and display it to the user
  float final_score = (float)score/3 * 100;
  printf("You got a score of %.2f%%\n", final_score);

  return 0;
}