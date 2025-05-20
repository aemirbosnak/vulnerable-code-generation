//LLAMA2-13B DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare global variables
int quizScore = 0;
int correctAnswers = 0;
char guessedLetter = 'a'; // Default guessed letter is "a"

// Function to print a question
void printQuestion(char *question) {
  printf("%s\n", question);
}

// Function to get a guess from the user
char getGuess() {
  char guess;
  printf("Guess a letter: ");
  scanf(" %c", &guess);
  return guess;
}

// Function to check if the guess is correct
int checkAnswer(char guessedLetter, char correctLetter) {
  if (guessedLetter == correctLetter) {
    correctAnswers++;
    return 1;
  } else {
    return 0;
  }
}

// Function to print the quiz results
void printResults() {
  printf("Quiz Results:\n");
  printf("Correct Answers: %d\n", correctAnswers);
  printf("Quiz Score: %d\n", quizScore);
}

int main() {
  // Print the first question
  printQuestion("What is the capital of France?");

  // Get the user's guess
  char guess = getGuess();

  // Check if the guess is correct
  int isCorrect = checkAnswer(guess, 'P');

  // Update the quiz score and correct answers
  if (isCorrect) {
    quizScore++;
    correctAnswers++;
  }

  // Print the next question
  printQuestion("What is the smallest planet in our solar system?");

  // Get the user's guess
  guess = getGuess();

  // Check if the guess is correct
  isCorrect = checkAnswer(guess, 'M');

  // Update the quiz score and correct answers
  if (isCorrect) {
    quizScore++;
    correctAnswers++;
  }

  // Print the next question
  printQuestion("What is the largest planet in our solar system?");

  // Get the user's guess
  guess = getGuess();

  // Check if the guess is correct
  isCorrect = checkAnswer(guess, 'J');

  // Update the quiz score and correct answers
  if (isCorrect) {
    quizScore++;
    correctAnswers++;
  }

  // Print the results
  printResults();

  return 0;
}