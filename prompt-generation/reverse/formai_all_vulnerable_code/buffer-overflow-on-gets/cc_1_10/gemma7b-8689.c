//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_exam_paper(int num_questions, char **questions, int **answers, int **marks) {
  // Allocate memory for questions, answers, and marks
  questions = (char**)malloc(num_questions * sizeof(char*));
  answers = (int**)malloc(num_questions * sizeof(int*));
  marks = (int**)malloc(num_questions * sizeof(int*));

  // Create questions
  for (int i = 0; i < num_questions; i++) {
    questions[i] = (char*)malloc(256 * sizeof(char));
    printf("Enter question %d: ", i + 1);
    gets(questions[i]);
  }

  // Get answers
  for (int i = 0; i < num_questions; i++) {
    answers[i] = (int*)malloc(10 * sizeof(int));
    printf("Enter answer options for question %d: ", i + 1);
    for (int j = 0; j < 4; j++) {
      scanf("%d ", answers[i][j]);
    }
  }

  // Calculate marks
  for (int i = 0; i < num_questions; i++) {
    marks[i] = (int*)malloc(10 * sizeof(int));
    marks[i][0] = 10;
    marks[i][1] = 8;
    marks[i][2] = 6;
    marks[i][3] = 4;
  }
}

int main() {
  int num_questions = 5;
  char **questions = NULL;
  int **answers = NULL;
  int **marks = NULL;

  generate_exam_paper(num_questions, questions, answers, marks);

  // Print the exam paper
  for (int i = 0; i < num_questions; i++) {
    printf("Question %d: %s\n", i + 1, questions[i]);
    printf("Answer Options:\n");
    for (int j = 0; j < 4; j++) {
      printf("  %d. %s\n", answers[i][j], marks[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for (int i = 0; i < num_questions; i++) {
    free(questions[i]);
    free(answers[i]);
    free(marks[i]);
  }

  return 0;
}