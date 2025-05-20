//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the question
typedef struct {
  char question[100];
  char options[4][50];
  int correct_answer;
} Question;

// Structure to store the student's answer
typedef struct {
  int question_number;
  int answer;
} Answer;

// Function to read a question from a file
Question read_question(FILE *fp) {
  Question q;
  fscanf(fp, "%s", q.question);
  for (int i = 0; i < 4; i++) {
    fscanf(fp, "%s", q.options[i]);
  }
  fscanf(fp, "%d", &q.correct_answer);
  return q;
}

// Function to write a question to a file
void write_question(FILE *fp, Question q) {
  fprintf(fp, "%s\n", q.question);
  for (int i = 0; i < 4; i++) {
    fprintf(fp, "%s\n", q.options[i]);
  }
  fprintf(fp, "%d\n", q.correct_answer);
}

// Function to read the student's answer
Answer read_answer(FILE *fp) {
  Answer a;
  fscanf(fp, "%d", &a.question_number);
  fscanf(fp, "%d", &a.answer);
  return a;
}

// Function to write the student's answer
void write_answer(FILE *fp, Answer a) {
  fprintf(fp, "%d %d\n", a.question_number, a.answer);
}

// Function to evaluate the student's answer
int evaluate_answer(Question q, Answer a) {
  return q.correct_answer == a.answer;
}

// Function to print the result
void print_result(int score, int total) {
  printf("Your score is %d out of %d\n", score, total);
}

// Main function
int main() {
  // Open the question file
  FILE *fp = fopen("questions.txt", "r");
  if (fp == NULL) {
    perror("Error opening question file");
    exit(1);
  }

  // Read the number of questions
  int num_questions;
  fscanf(fp, "%d", &num_questions);

  // Allocate memory for the questions
  Question *questions = malloc(sizeof(Question) * num_questions);
  if (questions == NULL) {
    perror("Error allocating memory for questions");
    exit(1);
  }

  // Read the questions
  for (int i = 0; i < num_questions; i++) {
    questions[i] = read_question(fp);
  }

  // Close the question file
  fclose(fp);

  // Open the answer file
  fp = fopen("answers.txt", "w");
  if (fp == NULL) {
    perror("Error opening answer file");
    exit(1);
  }

  // Get the student's answers
  for (int i = 0; i < num_questions; i++) {
    printf("Question %d: %s\n", i + 1, questions[i].question);
    for (int j = 0; j < 4; j++) {
      printf("%d. %s\n", j + 1, questions[i].options[j]);
    }
    int answer;
    printf("Your answer: ");
    scanf("%d", &answer);
    Answer a = {i + 1, answer};
    write_answer(fp, a);
  }

  // Close the answer file
  fclose(fp);

  // Evaluate the student's answers
  int score = 0;
  for (int i = 0; i < num_questions; i++) {
    Answer a = read_answer(fp);
    score += evaluate_answer(questions[i], a);
  }

  // Print the result
  print_result(score, num_questions);

  // Free the memory
  free(questions);

  return 0;
}