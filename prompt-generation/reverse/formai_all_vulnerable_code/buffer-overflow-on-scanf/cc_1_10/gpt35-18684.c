//FormAI DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct questions {
  char question[1000];
  char optionA[100];
  char optionB[100];
  char optionC[100];
  char optionD[100];
  char correctAnswer[100];
};

void askQuestion(struct questions qns) {
  char userAns;
  printf("\n%s\n\n", qns.question);
  printf("A: %s\n", qns.optionA);
  printf("B: %s\n", qns.optionB);
  printf("C: %s\n", qns.optionC);
  printf("D: %s\n\n", qns.optionD);
  printf("Enter your answer (A/B/C/D): ");
  scanf(" %c", &userAns);
  if (userAns == *qns.correctAnswer) {
    printf("\nCorrect!\n");
  } else {
    printf("\nIncorrect. The correct answer is %s.\n", qns.correctAnswer);
  }
}

int main() {
  int numQuestions;
  printf("Welcome to the Online Examination System!\n\n");
  printf("Enter the number of questions: ");
  scanf("%d", &numQuestions);
  struct questions qnsList[numQuestions];
  
  for (int i = 0; i < numQuestions; i++) {
    printf("\nEnter Question %d:\n", i+1);
    printf("Question: ");
    scanf(" %[^\n]%*c", qnsList[i].question);
    printf("Option A: ");
    scanf(" %[^\n]%*c", qnsList[i].optionA);
    printf("Option B: ");
    scanf(" %[^\n]%*c", qnsList[i].optionB);
    printf("Option C: ");
    scanf(" %[^\n]%*c", qnsList[i].optionC);
    printf("Option D: ");
    scanf(" %[^\n]%*c", qnsList[i].optionD);
    printf("Correct Answer (A/B/C/D): ");
    scanf(" %s", qnsList[i].correctAnswer);
  }

  printf("\n\nYou will now be asked %d questions!\n\n", numQuestions);
  for (int i = 0; i < numQuestions; i++) {
    askQuestion(qnsList[i]);
  }

  printf("\n\nThank you for taking the test!\n");
  return 0;
}