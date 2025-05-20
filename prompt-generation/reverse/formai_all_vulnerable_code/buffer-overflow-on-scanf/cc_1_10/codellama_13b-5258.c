//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: active
// Examination System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a question
struct question {
  char question[100];
  char option1[100];
  char option2[100];
  char option3[100];
  char option4[100];
  char answer[100];
};

// Define the structure for a student
struct student {
  char name[100];
  int age;
  int roll_no;
  int score;
};

// Function to get the input from the user
void get_input(struct question *q, struct student *s) {
  printf("Enter the question: ");
  scanf("%s", q->question);
  printf("Enter the options: ");
  scanf("%s %s %s %s", q->option1, q->option2, q->option3, q->option4);
  printf("Enter the answer: ");
  scanf("%s", q->answer);
  printf("Enter the student's name: ");
  scanf("%s", s->name);
  printf("Enter the student's age: ");
  scanf("%d", &s->age);
  printf("Enter the student's roll no: ");
  scanf("%d", &s->roll_no);
}

// Function to display the question
void display_question(struct question *q) {
  printf("Question: %s\n", q->question);
  printf("Options: %s, %s, %s, %s\n", q->option1, q->option2, q->option3, q->option4);
}

// Function to get the answer from the user
void get_answer(struct question *q, struct student *s) {
  char answer[100];
  printf("Enter the answer: ");
  scanf("%s", answer);
  if (strcmp(answer, q->answer) == 0) {
    s->score++;
  }
}

// Function to display the score
void display_score(struct student *s) {
  printf("Score: %d\n", s->score);
}

// Main function
int main() {
  // Declare the question and student variables
  struct question q;
  struct student s;

  // Get the input from the user
  get_input(&q, &s);

  // Display the question
  display_question(&q);

  // Get the answer from the user
  get_answer(&q, &s);

  // Display the score
  display_score(&s);

  return 0;
}