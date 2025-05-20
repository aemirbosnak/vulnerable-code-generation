//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int roll_no;
  char name[50];
  char email[50];
  char mobile_no[20];
} student;

typedef struct {
  int question_no;
  char question[200];
  char options[4][50];
  char correct_answer;
} question;

typedef struct {
  int roll_no;
  int question_no;
  char answer;
} response;

int main() {
  student students[100];
  question questions[100];
  response responses[1000];

  int num_students, num_questions;

  // Read student data
  printf("Enter the number of students: ");
  scanf("%d", &num_students);

  for (int i = 0; i < num_students; i++) {
    printf("Enter student %d details:\n", i + 1);
    printf("Roll number: ");
    scanf("%d", &students[i].roll_no);
    printf("Name: ");
    scanf("%s", students[i].name);
    printf("Email: ");
    scanf("%s", students[i].email);
    printf("Mobile number: ");
    scanf("%s", students[i].mobile_no);
    printf("\n");
  }

  // Read question data
  printf("Enter the number of questions: ");
  scanf("%d", &num_questions);

  for (int i = 0; i < num_questions; i++) {
    printf("Enter question %d details:\n", i + 1);
    printf("Question: ");
    scanf("%s", questions[i].question);
    printf("Options:\n");
    for (int j = 0; j < 4; j++) {
      printf("Option %d: ", j + 1);
      scanf("%s", questions[i].options[j]);
    }
    printf("Correct answer: ");
    scanf(" %c", &questions[i].correct_answer);
    printf("\n");
  }

  // Conduct the examination
  for (int i = 0; i < num_students; i++) {
    int response_count = 0;

    printf("Student %d (%s) is taking the examination.\n", students[i].roll_no, students[i].name);

    for (int j = 0; j < num_questions; j++) {
      printf("Question %d: %s\n", j + 1, questions[j].question);

      for (int k = 0; k < 4; k++) {
        printf("Option %d: %s\n", k + 1, questions[j].options[k]);
      }

      printf("Enter your answer (A/B/C/D): ");
      char answer;
      scanf(" %c", &answer);

      responses[response_count].roll_no = students[i].roll_no;
      responses[response_count].question_no = questions[j].question_no;
      responses[response_count++].answer = answer;
    }
  }

  // Evaluate responses
  int scores[100] = {0};

  for (int i = 0; i < 1000; i++) {
    int roll_no = responses[i].roll_no;
    int question_no = responses[i].question_no;
    char answer = responses[i].answer;

    if (answer == questions[question_no - 1].correct_answer) {
      scores[roll_no - 1]++;
    }
  }

  // Display results
  printf("Results:\n");

  for (int i = 0; i < num_students; i++) {
    printf("Student %d (%s): %d%%\n", students[i].roll_no, students[i].name, (scores[i] * 100) / num_questions);
  }

  return 0;
}