//FormAI DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

typedef struct {
  char question[100];
  char options[MAX_OPTIONS][50];
  int answer;
} Question;

int total_questions = 0;
Question exam[MAX_QUESTIONS];

void add_question() {
  if (total_questions == MAX_QUESTIONS) {
    printf("Maximum questions limit reached.\n");
    return;
  }

  printf("Enter the question:\n");
  scanf(" %[^\n]", exam[total_questions].question);

  printf("Enter the options:\n");
  for (int i = 0; i < MAX_OPTIONS; i++) {
    scanf(" %[^\n]", exam[total_questions].options[i]);
  }

  printf("Enter the correct option number (1-%d):\n", MAX_OPTIONS);
  scanf("%d", &exam[total_questions].answer);

  total_questions++;

  printf("Question added successfully.\n");
}

void start_exam() {
  int score = 0;

  for (int i = 0; i < total_questions; i++) {
    printf("Question %d: %s\n", i+1, exam[i].question);
    for (int j = 0; j < MAX_OPTIONS; j++) {
      printf("%c. %s\n", 'a'+j, exam[i].options[j]);
    }

    char user_answer;
    scanf(" %c", &user_answer);

    if (user_answer == 'a' + exam[i].answer - 1) {
      printf("Correct answer!\n");
      score++;
    } else {
      printf("Wrong answer!\n");
    }
  }

  printf("Your score is: %d/%d\n", score, total_questions);
}

int main() {
  while (1) {
    printf("MENU\n");
    printf("1. Add question\n");
    printf("2. Start exam\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3):\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_question();
        break;
      case 2:
        if (total_questions == 0) {
          printf("No questions added yet.\n");
        } else {
          start_exam();
        }
        break;
      case 3:
        printf("Thank you for using this program.\n");
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }
}