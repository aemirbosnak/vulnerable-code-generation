//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_exam(int num_questions, char **questions, int **answers, int **marks) {
  // Allocate memory for the questions, answers, and marks
  *questions = malloc(num_questions * sizeof(char *));
  *answers = malloc(num_questions * sizeof(int));
  *marks = malloc(num_questions * sizeof(int));

  // Create the questions
  for (int i = 0; i < num_questions; i++) {
    questions[i] = malloc(256 * sizeof(char));
    scanf("Enter question %d: ", questions[i]);
  }

  // Get the answers
  for (int i = 0; i < num_questions; i++) {
    answers[i] = malloc(10 * sizeof(int));
    printf("Enter answer options for question %d: ", i + 1);
    for (int j = 0; j < 4; j++) {
      scanf("%d ", answers[i][j]);
    }
  }

  // Calculate the marks
  for (int i = 0; i < num_questions; i++) {
    marks[i] = 0;
    for (int j = 0; j < 4; j++) {
      if (answers[i][j] == 1) {
        marks[i] = 10;
      }
    }
  }
}

int main() {
  int num_questions = 5;
  char **questions = NULL;
  int **answers = NULL;
  int **marks = NULL;

  generate_exam(num_questions, questions, answers, marks);

  // Print the marks
  for (int i = 0; i < num_questions; i++) {
    printf("Mark for question %d: %d\n", i + 1, marks[i]);
  }

  return 0;
}