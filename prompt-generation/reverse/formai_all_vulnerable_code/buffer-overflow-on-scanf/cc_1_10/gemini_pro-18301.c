//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store question and answer
typedef struct {
  char question[256];
  char options[4][64];
  int correctAnswer;
} Question;

// Function to generate random number
int generateRandomNumber(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// Function to display question and options
void displayQuestion(Question question) {
  printf("\n%s\n", question.question);
  for (int i = 0; i < 4; i++) {
    printf("%d. %s\n", i + 1, question.options[i]);
  }
}

// Function to check if answer is correct
int checkAnswer(Question question, int answer) {
  return question.correctAnswer == answer;
}

// Function to display result
void displayResult(int score, int totalQuestions) {
  printf("\nYour score: %d/%d\n", score, totalQuestions);
  if (score >= (totalQuestions / 2)) {
    printf("Congratulations! You have passed the exam.\n");
  } else {
    printf("Sorry, you have failed the exam.\n");
  }
}

// Main function
int main() {
  // Seed random number generator
  srand(time(NULL));

  // Create questions and answers
  Question questions[] = {
    {"What is the capital of India?", {"New Delhi", "Mumbai", "Kolkata", "Chennai"}, 1},
    {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1},
    {"What is the currency of India?", {"Rupee", "Dollar", "Euro", "Pound"}, 1},
    {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Rhinoceros"}, 1},
    {"What is the national bird of India?", {"Peacock", "Eagle", "Owl", "Parrot"}, 1}
  };

  // Get total number of questions
  int totalQuestions = sizeof(questions) / sizeof(Question);

  // Randomly select questions
  int selectedQuestions[totalQuestions];
  for (int i = 0; i < totalQuestions; i++) {
    selectedQuestions[i] = generateRandomNumber(0, totalQuestions - 1);
  }

  // Display questions and get answers
  int score = 0;
  for (int i = 0; i < totalQuestions; i++) {
    displayQuestion(questions[selectedQuestions[i]]);
    int answer;
    printf("Answer: ");
    scanf("%d", &answer);
    if (checkAnswer(questions[selectedQuestions[i]], answer)) {
      score++;
    }
  }

  // Display result
  displayResult(score, totalQuestions);

  return 0;
}