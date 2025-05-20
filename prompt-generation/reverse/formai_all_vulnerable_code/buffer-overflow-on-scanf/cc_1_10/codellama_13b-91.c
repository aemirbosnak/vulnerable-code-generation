//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_USERS 10

struct question {
  char question[100];
  char options[MAX_OPTIONS][100];
  int answer;
};

struct user {
  char name[100];
  int score;
};

void generate_questions(struct question questions[], int num_questions) {
  int i;
  for (i = 0; i < num_questions; i++) {
    questions[i].answer = rand() % MAX_OPTIONS;
    printf("Question %d: %s\n", i, questions[i].question);
    int j;
    for (j = 0; j < MAX_OPTIONS; j++) {
      printf("%d: %s\n", j, questions[i].options[j]);
    }
  }
}

void start_exam(struct question questions[], int num_questions, struct user users[], int num_users) {
  int i;
  for (i = 0; i < num_questions; i++) {
    printf("Question %d: %s\n", i, questions[i].question);
    int j;
    for (j = 0; j < MAX_OPTIONS; j++) {
      printf("%d: %s\n", j, questions[i].options[j]);
    }
    printf("Enter your answer: ");
    int answer;
    scanf("%d", &answer);
    if (answer == questions[i].answer) {
      printf("Correct answer!\n");
    } else {
      printf("Incorrect answer. The correct answer is %d.\n", questions[i].answer);
    }
  }
}

int main() {
  struct question questions[MAX_QUESTIONS];
  struct user users[MAX_USERS];
  int num_questions = 0;
  int num_users = 0;

  printf("Welcome to the C Online Examination System!\n");
  printf("Please enter the number of questions: ");
  scanf("%d", &num_questions);
  printf("Please enter the number of users: ");
  scanf("%d", &num_users);

  generate_questions(questions, num_questions);
  start_exam(questions, num_questions, users, num_users);

  return 0;
}