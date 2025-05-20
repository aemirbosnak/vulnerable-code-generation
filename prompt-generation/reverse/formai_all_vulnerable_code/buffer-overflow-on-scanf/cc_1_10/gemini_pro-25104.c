//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  time_t t;
  srand((unsigned) time(&t));

  int num_questions = 10;
  int questions[num_questions];
  char answers[num_questions][10];
  char user_answers[num_questions][10];
  int correct_answers = 0;
  int wrong_answers = 0;

  // Generate random questions
  for (int i = 0; i < num_questions; i++) {
    questions[i] = rand() % 100;
  }

  // Generate random answers
  for (int i = 0; i < num_questions; i++) {
    for (int j = 0; j < 10; j++) {
      answers[i][j] = 'a' + rand() % 26;
    }
  }

  // Get user answers
  for (int i = 0; i < num_questions; i++) {
    printf("Question %d: %d\n", i + 1, questions[i]);
    for (int j = 0; j < 10; j++) {
      printf("%c) %s\n", 'a' + j, answers[i][j]);
    }
    printf("Your answer: ");
    scanf("%s", user_answers[i]);
  }

  // Check answers
  for (int i = 0; i < num_questions; i++) {
    if (strcmp(user_answers[i], answers[i]) == 0) {
      correct_answers++;
    } else {
      wrong_answers++;
    }
  }

  // Print results
  printf("Correct answers: %d\n", correct_answers);
  printf("Wrong answers: %d\n", wrong_answers);

  return 0;
}