//FormAI DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
  char question[100];
  char options[4][25];
  int correct_option;
} ExamQuestion;

int main(){
  int num_questions;
  printf("Welcome to the Futuristic Online Examination System\n\n");
  printf("Please enter the number of questions: ");
  scanf("%d", &num_questions);

  ExamQuestion questions[num_questions];

  for(int i = 0; i < num_questions; i++){
    printf("Enter question %d: ", i+1);
    scanf(" %[^\n]s", questions[i].question);

    for(int j = 0; j < 4; j++){
      printf("Enter option %d for question %d: ", j+1, i+1);
      scanf(" %[^\n]s", questions[i].options[j]);
    }

    printf("Enter the correct option for question %d (1-4): ", i+1);
    scanf(" %d", &questions[i].correct_option);
  }

  printf("\n\nStarting the exam...\n");

  int score = 0;

  for(int i = 0; i < num_questions; i++){
    printf("\n\nQuestion %d: %s\n", i+1, questions[i].question);
    for(int j = 0; j < 4; j++){
      printf("%d. %s\n", j+1, questions[i].options[j]);
    }

    int chosen_option;
    printf("Enter your answer (1-4): ");
    scanf("%d", &chosen_option);

    if( chosen_option == questions[i].correct_option){
      score++;
      printf("Correct!\n");
    }
    else{
      printf("Incorrect. The correct answer is option %d.\n", questions[i].correct_option);
    }
  }

  printf("\n\nExam completed!\n\n");
  printf("Your score is %d out of %d.\n", score, num_questions);

  return 0;
}