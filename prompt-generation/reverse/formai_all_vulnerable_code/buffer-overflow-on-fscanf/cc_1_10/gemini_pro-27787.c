//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store question and answer
typedef struct Question {
  char question[256];
  char options[4][64];
  int correct_answer;
} Question;

// Function to generate random number within a given range
int rand_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to load questions from a file
Question* load_questions(char* filename, int* num_questions) {
  // Open the file
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the number of questions
  fscanf(file, "%d", num_questions);

  // Allocate memory for the questions
  Question* questions = malloc(*num_questions * sizeof(Question));

  // Read each question and its options
  for (int i = 0; i < *num_questions; i++) {
    fscanf(file, "%s\n", questions[i].question);
    for (int j = 0; j < 4; j++) {
      fscanf(file, "%s\n", questions[i].options[j]);
    }
    fscanf(file, "%d\n", &questions[i].correct_answer);
  }

  // Close the file
  fclose(file);

  // Return the questions
  return questions;
}

// Function to display a question and its options
void display_question(Question question) {
  // Display the question
  printf("%s\n", question.question);

  // Display the options
  for (int i = 0; i < 4; i++) {
    printf("%d. %s\n", i + 1, question.options[i]);
  }
}

// Function to get user input as an integer
int get_int() {
  int input;
  scanf("%d", &input);
  return input;
}

// Function to check if the user's answer is correct
int check_answer(Question question, int answer) {
  return question.correct_answer == answer;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Load the questions from the file
  int num_questions;
  Question* questions = load_questions("questions.txt", &num_questions);

  // Shuffle the questions
  for (int i = 0; i < num_questions; i++) {
    int j = rand_range(i, num_questions - 1);
    Question temp = questions[i];
    questions[i] = questions[j];
    questions[j] = temp;
  }

  // Display the questions and get user input
  int score = 0;
  for (int i = 0; i < num_questions; i++) {
    display_question(questions[i]);
    int answer = get_int();
    if (check_answer(questions[i], answer)) {
      score++;
    }
  }

  // Display the score
  printf("Your score is %d/%d\n", score, num_questions);

  // Free the memory allocated for the questions
  free(questions);

  return 0;
}