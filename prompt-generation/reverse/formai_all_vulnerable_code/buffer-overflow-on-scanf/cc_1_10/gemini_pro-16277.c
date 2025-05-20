//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to print a happy message
void printHappyMessage() {
  printf("\nCongratulations! You are a Periodic Table genius!\n\n");
  printf("Here's a smiley face to brighten your day: :)\n\n");
}

// Function to ask a question
int askQuestion(char *question, char *answer) {
  char userAnswer[100];
  printf("%s", question);
  scanf("%s", userAnswer);
  return strcmp(userAnswer, answer) == 0;
}

// Function to play the game
void playGame() {
  // Array of questions
  char *questions[] = {
    "What is the chemical symbol for gold?",
    "What is the atomic number of oxygen?",
    "What is the name of the element with the symbol Fe?",
    "What is the heaviest element on the Periodic Table?",
    "What is the lightest element on the Periodic Table?",
    "What is the most reactive element on the Periodic Table?",
    "What is the least reactive element on the Periodic Table?",
    "What is the symbol for the noble gas helium?",
    "What is the name of the element with the symbol Na?",
    "What is the atomic number of chlorine?"
  };

  // Array of answers
  char *answers[] = {
    "Au",
    "8",
    "Iron",
    "Oganesson",
    "Hydrogen",
    "Fluorine",
    "Helium",
    "He",
    "Sodium",
    "17"
  };

  // Initialize score to 0
  int score = 0;

  // Loop through questions
  for (int i = 0; i < 10; i++) {
    // Ask question and check answer
    if (askQuestion(questions[i], answers[i])) {
      // Increment score
      score++;
    }
  }

  // Print score
  printf("Your score is: %d\n", score);

  // Print happy message if score is perfect
  if (score == 10) {
    printHappyMessage();
  }
}

// Main function
int main() {
  // Seed random number generator
  srand(time(NULL));

  // Play game
  playGame();

  return 0;
}