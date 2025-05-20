//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>

  #define MAX_QUESTIONS 100
  #define MAX_ANSWERS 4

  typedef struct {
    char question[256];
    char answers[MAX_ANSWERS][256];
    char correct_answer[256];
  } Question;

  int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions = 0;
    int i, j;
    char answer[256];
    int score = 0;

    // Read questions from file
    FILE *fp = fopen("questions.txt", "r");
    while (fscanf(fp, "%s\n", questions[num_questions].question) == 1) {
      for (i = 0; i < MAX_ANSWERS; i++) {
        fscanf(fp, "%s\n", questions[num_questions].answers[i]);
      }
      fscanf(fp, "%s\n", questions[num_questions].correct_answer);
      num_questions++;
    }
    fclose(fp);

    // Shuffle questions
    srand(time(NULL));
    for (i = 0; i < num_questions; i++) {
      int j = rand() % num_questions;
      Question temp = questions[i];
      questions[i] = questions[j];
      questions[j] = temp;
    }

    // Ask questions
    for (i = 0; i < num_questions; i++) {
      printf("%s\n", questions[i].question);
      for (j = 0; j < MAX_ANSWERS; j++) {
        printf("%s\n", questions[i].answers[j]);
      }
      fgets(answer, sizeof(answer), stdin);
      if (strcmp(answer, questions[i].correct_answer) == 0) {
        score++;
      }
    }

    // Print score
    printf("Your score is: %d/%d\n", score, num_questions);

    return 0;
  }