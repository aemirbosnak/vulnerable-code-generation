//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *question;
  char **options;
  int n_options;
  int correct_option;
} Question;

typedef struct {
  char *name;
  int score;
} Student;

int main() {
  int n_questions, n_students;
  Question *questions;
  Student *students;

  // Read input
  scanf("%d %d", &n_questions, &n_students);
  questions = malloc(sizeof(Question) * n_questions);
  students = malloc(sizeof(Student) * n_students);
  for (int i = 0; i < n_questions; i++) {
    questions[i].question = malloc(100);
    scanf("%s", questions[i].question);
    questions[i].n_options = 4;
    questions[i].options = malloc(sizeof(char *) * 4);
    for (int j = 0; j < 4; j++) {
      questions[i].options[j] = malloc(100);
      scanf("%s", questions[i].options[j]);
    }
    scanf("%d", &questions[i].correct_option);
  }
  for (int i = 0; i < n_students; i++) {
    students[i].name = malloc(100);
    scanf("%s", students[i].name);
    students[i].score = 0;
  }

  // Conduct exam
  for (int i = 0; i < n_students; i++) {
    for (int j = 0; j < n_questions; j++) {
      int answer;
      scanf("%d", &answer);
      if (answer == questions[j].correct_option) {
        students[i].score++;
      }
    }
  }

  // Print results
  for (int i = 0; i < n_students; i++) {
    printf("%s %d\n", students[i].name, students[i].score);
  }

  // Cleanup
  for (int i = 0; i < n_questions; i++) {
    free(questions[i].question);
    for (int j = 0; j < 4; j++) {
      free(questions[i].options[j]);
    }
    free(questions[i].options);
  }
  free(questions);
  for (int i = 0; i < n_students; i++) {
    free(students[i].name);
  }
  free(students);

  return 0;
}