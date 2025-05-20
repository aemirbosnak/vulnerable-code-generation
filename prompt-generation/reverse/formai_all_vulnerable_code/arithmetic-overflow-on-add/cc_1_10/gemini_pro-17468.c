//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the questions and answers
typedef struct Question {
  char question[256];
  char options[4][64];
  int correctAnswer;
} Question;

// Structure to store the student's responses
typedef struct StudentResponse {
  int questionNumber;
  int response;
} StudentResponse;

// Function to load the questions from a file
Question *loadQuestions(char *filename, int *numQuestions) {
  FILE *fp;
  char line[256];
  Question *questions;

  // Open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Count the number of questions
  while (fgets(line, sizeof(line), fp)) {
    (*numQuestions)++;
  }

  // Allocate memory for the questions
  questions = malloc(*numQuestions * sizeof(Question));
  if (questions == NULL) {
    printf("Error allocating memory for questions\n");
    fclose(fp);
    return NULL;
  }

  // Read the questions from the file
  rewind(fp);
  int i = 0;
  while (fgets(line, sizeof(line), fp)) {
    // Parse the question
    char *q = strtok(line, "|");
    strcpy(questions[i].question, q);

    // Parse the options
    for (int j = 0; j < 4; j++) {
      char *o = strtok(NULL, "|");
      strcpy(questions[i].options[j], o);
    }

    // Parse the correct answer
    char *a = strtok(NULL, "|");
    questions[i].correctAnswer = atoi(a);

    i++;
  }

  // Close the file
  fclose(fp);

  return questions;
}

// Function to display the questions
void displayQuestions(Question *questions, int numQuestions) {
  for (int i = 0; i < numQuestions; i++) {
    printf("Question %d:\n", i + 1);
    printf("%s\n", questions[i].question);
    for (int j = 0; j < 4; j++) {
      printf("%d: %s\n", j + 1, questions[i].options[j]);
    }
    printf("\n");
  }
}

// Function to get the student's responses
StudentResponse *getStudentResponses(int numQuestions) {
  StudentResponse *responses;

  // Allocate memory for the responses
  responses = malloc(numQuestions * sizeof(StudentResponse));
  if (responses == NULL) {
    printf("Error allocating memory for responses\n");
    return NULL;
  }

  // Get the responses from the student
  for (int i = 0; i < numQuestions; i++) {
    printf("Enter your response for question %d (1-4): ", i + 1);
    scanf("%d", &responses[i].response);

    // Validate the response
    while (responses[i].response < 1 || responses[i].response > 4) {
      printf("Invalid response. Enter a number between 1 and 4: ");
      scanf("%d", &responses[i].response);
    }
  }

  return responses;
}

// Function to grade the student's responses
int gradeResponses(Question *questions, int numQuestions, StudentResponse *responses) {
  int score = 0;

  for (int i = 0; i < numQuestions; i++) {
    if (responses[i].response == questions[i].correctAnswer) {
      score++;
    }
  }

  return score;
}

// Function to display the student's score
void displayScore(int score, int numQuestions) {
  printf("Your score is %d out of %d\n", score, numQuestions);
}

int main() {
  // Load the questions from the file
  char *filename = "questions.txt";
  int numQuestions;
  Question *questions = loadQuestions(filename, &numQuestions);
  if (questions == NULL) {
    return 1;
  }

  // Display the questions
  displayQuestions(questions, numQuestions);

  // Get the student's responses
  StudentResponse *responses = getStudentResponses(numQuestions);
  if (responses == NULL) {
    return 1;
  }

  // Grade the student's responses
  int score = gradeResponses(questions, numQuestions, responses);

  // Display the student's score
  displayScore(score, numQuestions);

  // Free the memory allocated for the questions and responses
  free(questions);
  free(responses);

  return 0;
}