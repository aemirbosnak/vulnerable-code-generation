//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  char student_id[11];
  char email[50];
} student_t;

typedef struct {
  int question_id;
  char question[256];
  char option1[256];
  char option2[256];
  char option3[256];
  char option4[256];
  char correct_option;
} question_t;

typedef struct {
  student_t student;
  question_t question;
  int answer;
} examination_t;

int main() {
  // Create an examination system.
  examination_t examination;

  // Get student information.
  printf("Enter your name: ");
  scanf("%s", examination.student.name);

  printf("Enter your student ID: ");
  scanf("%s", examination.student.student_id);

  printf("Enter your email address: ");
  scanf("%s", examination.student.email);

  // Get question information.
  printf("Enter the question ID: ");
  scanf("%d", &examination.question.question_id);

  printf("Enter the question: ");
  scanf(" %[^\n]s ", examination.question.question);

  printf("Enter option 1: ");
  scanf(" %[^\n]s ", examination.question.option1);

  printf("Enter option 2: ");
  scanf(" %[^\n]s ", examination.question.option2);

  printf("Enter option 3: ");
  scanf(" %[^\n]s ", examination.question.option3);

  printf("Enter option 4: ");
  scanf(" %[^\n]s ", examination.question.option4);

  printf("Enter the correct option: ");
  scanf(" %c", &examination.question.correct_option);

  // Get student answer.
  printf("Enter your answer: ");
  scanf("%d", &examination.answer);

  // Check if the student answered correctly.
  int correct = (examination.answer == examination.question.correct_option);

  // Print the result.
  printf("Your answer is %s.\n", correct ? "correct" : "incorrect");

  return 0;
}