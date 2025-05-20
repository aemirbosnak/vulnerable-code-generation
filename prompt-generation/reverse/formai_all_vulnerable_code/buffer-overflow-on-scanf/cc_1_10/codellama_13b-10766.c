//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 10
#define MAX_OPTIONS 4

// Structure to store a question
struct question {
  char text[MAX_QUESTIONS];
  char options[MAX_OPTIONS][MAX_ANSWERS];
  char correct_answer[MAX_ANSWERS];
};

// Function to print a question
void print_question(struct question q) {
  printf("%s\n", q.text);
  for (int i = 0; i < MAX_OPTIONS; i++) {
    printf("%d. %s\n", i + 1, q.options[i]);
  }
}

// Function to get a question from the user
struct question get_question() {
  struct question q;
  printf("Enter question text: ");
  scanf("%s", q.text);
  for (int i = 0; i < MAX_OPTIONS; i++) {
    printf("Enter option %d: ", i + 1);
    scanf("%s", q.options[i]);
  }
  printf("Enter correct answer: ");
  scanf("%s", q.correct_answer);
  return q;
}

// Function to check if a user's answer is correct
int check_answer(struct question q, char *user_answer) {
  if (strcmp(q.correct_answer, user_answer) == 0) {
    return 1;
  }
  return 0;
}

// Function to display the results of a quiz
void display_results(int num_correct, int num_questions) {
  printf("You scored %d out of %d.\n", num_correct, num_questions);
}

// Main function
int main() {
  // Initialize variables
  struct question questions[MAX_QUESTIONS];
  int num_questions = 0;
  int num_correct = 0;
  char user_answer[MAX_ANSWERS];

  // Get questions from user
  for (int i = 0; i < MAX_QUESTIONS; i++) {
    questions[i] = get_question();
    num_questions++;
  }

  // Shuffle questions
  srand(time(NULL));
  for (int i = 0; i < num_questions; i++) {
    int j = rand() % num_questions;
    struct question temp = questions[i];
    questions[i] = questions[j];
    questions[j] = temp;
  }

  // Display questions
  for (int i = 0; i < num_questions; i++) {
    print_question(questions[i]);
  }

  // Get user's answers
  for (int i = 0; i < num_questions; i++) {
    printf("Answer question %d: ", i + 1);
    scanf("%s", user_answer);
    if (check_answer(questions[i], user_answer)) {
      num_correct++;
    }
  }

  // Display results
  display_results(num_correct, num_questions);

  return 0;
}