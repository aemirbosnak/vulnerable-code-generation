//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

struct question {
  char question[100];
  char options[MAX_OPTIONS][100];
  int correct_option;
};

int main() {
  struct question questions[MAX_QUESTIONS];
  int num_questions;
  int i, j;
  int score = 0;

  // Read the questions from a file
  FILE *fp = fopen("questions.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return -1;
  }

  num_questions = 0;
  while (fscanf(fp, "%[^=]=%[^=]=%d\n", questions[num_questions].question, questions[num_questions].options[0], &questions[num_questions].correct_option) != EOF) {
    for (i = 1; i < MAX_OPTIONS; i++) {
      fscanf(fp, "%[^=]\n", questions[num_questions].options[i]);
    }
    num_questions++;
  }

  fclose(fp);

  // Display the questions and get the user's answers
  for (i = 0; i < num_questions; i++) {
    printf("%s\n", questions[i].question);
    for (j = 0; j < MAX_OPTIONS; j++) {
      printf("%d. %s\n", j + 1, questions[i].options[j]);
    }

    int answer;
    scanf("%d", &answer);

    // Check if the answer is correct
    if (answer == questions[i].correct_option) {
      score++;
    }
  }

  // Display the score
  printf("Your score is %d/%d\n", score, num_questions);

  return 0;
}