//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXAMS 10
#define MAX_QUESTIONS 20

typedef struct Exam {
  char title[50];
  int numQuestions;
  struct Question {
    char question[256];
    int answer;
  } questions[MAX_QUESTIONS];
} Exam;

int main() {
  Exam exams[MAX_EXAMS];
  int numExams = 0;

  while (1) {
    printf("Enter exam title: ");
    scanf("%s", exams[numExams].title);

    printf("Enter number of questions: ");
    scanf("%d", &exams[numExams].numQuestions);

    for (int i = 0; i < exams[numExams].numQuestions; i++) {
      printf("Enter question: ");
      scanf("%s", exams[numExams].questions[i].question);

      printf("Enter answer: ");
      scanf("%d", &exams[numExams].questions[i].answer);
    }

    numExams++;

    if (numExams >= MAX_EXAMS) {
      break;
    }

    printf("Enter another exam? (Y/N): ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'N') {
      break;
    }
  }

  for (int i = 0; i < numExams; i++) {
    printf("Exam: %s\n", exams[i].title);
    printf("Number of questions: %d\n", exams[i].numQuestions);
    for (int j = 0; j < exams[i].numQuestions; j++) {
      printf("Question: %s\n", exams[i].questions[j].question);
      printf("Answer: %d\n", exams[i].questions[j].answer);
    }
  }

  return 0;
}