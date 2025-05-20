//FormAI DATASET v1.0 Category: Online Examination System ; Style: random
#include <stdio.h>

int main() {
  printf("**** Welcome to the Online Examination System ****\n");
  
  int correct_answer_count = 0;
  int total_question_count = 5;
  
  printf("***********\n");
  printf("***** 1 *****\n");
  printf("***********\n");
  printf("What is the capital of France?\n");
  printf("A. Paris\n");
  printf("B. Berlin\n");
  printf("C. London\n");
  printf("D. Rome\n");
  
  char answer1;
  scanf(" %c", &answer1);
  
  if (answer1 == 'A' || answer1 == 'a') {
    printf("Correct answer!\n");
    correct_answer_count++;
  } else {
    printf("Incorrect answer!\n");
  }
  
  printf("***********\n");
  printf("***** 2 *****\n");
  printf("***********\n");
  printf("What is the largest planet in our solar system?\n");
  printf("A. Jupiter\n");
  printf("B. Earth\n");
  printf("C. Saturn\n");
  printf("D. Neptune\n");
  
  char answer2;
  scanf(" %c", &answer2);
  
  if (answer2 == 'A' || answer2 == 'a') {
    printf("Correct answer!\n");
    correct_answer_count++;
  } else {
    printf("Incorrect answer!\n");
  }
  
  printf("***********\n");
  printf("***** 3 *****\n");
  printf("***********\n");
  printf("What is the largest organ in the human body?\n");
  printf("A. Liver\n");
  printf("B. Heart\n");
  printf("C. Pancreas\n");
  printf("D. Skin\n");
  
  char answer3;
  scanf(" %c", &answer3);
  
  if (answer3 == 'D' || answer3 == 'd') {
    printf("Correct answer!\n");
    correct_answer_count++;
  } else {
    printf("Incorrect answer!\n");
  }
  
  printf("***********\n");
  printf("***** 4 *****\n");
  printf("***********\n");
  printf("What is the highest peak in North America?\n");
  printf("A. Mount Everest\n");
  printf("B. Kilimanjaro\n");
  printf("C. Mount McKinley/Denali\n");
  printf("D. Mount Rainier\n");
  
  char answer4;
  scanf(" %c", &answer4);
  
  if (answer4 == 'C' || answer4 == 'c') {
    printf("Correct answer!\n");
    correct_answer_count++;
  } else {
    printf("Incorrect answer!\n");
  }
  
  printf("***********\n");
  printf("***** 5 *****\n");
  printf("***********\n");
  printf("Who painted the Mona Lisa?\n");
  printf("A. Vincent van Gogh\n");
  printf("B. Claude Monet\n");
  printf("C. Leonardo da Vinci\n");
  printf("D. Michelangelo\n");
  
  char answer5;
  scanf(" %c", &answer5);
  
  if (answer5 == 'C' || answer5 == 'c') {
    printf("Correct answer!\n");
    correct_answer_count++;
  } else {
    printf("Incorrect answer!\n");
  }
  
  printf("***** Results *****\n");
  printf("Total questions: %d\n", total_question_count);
  printf("Correct answers: %d\n", correct_answer_count);
  printf("Incorrect answers: %d\n", total_question_count - correct_answer_count);
  
  float percentage = (float)correct_answer_count / total_question_count * 100;
  printf("Percentage: %0.2f%%\n", percentage);
  
  return 0;
}