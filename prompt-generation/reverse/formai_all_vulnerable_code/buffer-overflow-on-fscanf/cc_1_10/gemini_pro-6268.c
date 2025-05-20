//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

// Structure to store a question and its options
typedef struct Question {
  char question[256];
  char options[MAX_OPTIONS][256];
  int correct_option;
} Question;

// Array of questions
Question questions[MAX_QUESTIONS];

// Number of questions
int num_questions = 0;

// Function to load questions from a file
void load_questions(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the number of questions from the file
  fscanf(fp, "%d", &num_questions);

  // Read the questions and options from the file
  for (int i = 0; i < num_questions; i++) {
    fscanf(fp, "%s", questions[i].question);
    for (int j = 0; j < MAX_OPTIONS; j++) {
      fscanf(fp, "%s", questions[i].options[j]);
    }
    fscanf(fp, "%d", &questions[i].correct_option);
  }

  // Close the file
  fclose(fp);
}

// Function to display a question and its options
void display_question(int question_num) {
  // Display the question
  printf("Q%d: %s\n", question_num + 1, questions[question_num].question);

  // Display the options
  for (int i = 0; i < MAX_OPTIONS; i++) {
    printf("  %c) %s\n", 'A' + i, questions[question_num].options[i]);
  }
}

// Function to get the user's answer to a question
char get_answer() {
  // Get the user's input
  char answer;
  scanf(" %c", &answer);

  // Convert the answer to uppercase
  answer = toupper(answer);

  // Return the answer
  return answer;
}

// Function to check if the user's answer is correct
int is_correct_answer(int question_num, char answer) {
  // Check if the user's answer is the same as the correct answer
  return answer == 'A' + questions[question_num].correct_option;
}

// Main function
int main() {
  // Load the questions from the file
  load_questions("questions.txt");

  // Display the questions and get the user's answers
  int score = 0;
  for (int i = 0; i < num_questions; i++) {
    display_question(i);
    char answer = get_answer();
    if (is_correct_answer(i, answer)) {
      score++;
    }
  }

  // Display the user's score
  printf("Your score is %d out of %d.\n", score, num_questions);

  return 0;
}