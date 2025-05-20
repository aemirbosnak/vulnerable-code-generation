//FormAI DATASET v1.0 Category: Math exercise ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int getInput();
void generateQuestion();
int calculateAnswer();
void evaluateAnswer(int answer, int correctAnswer);

// Global variables
int num1, num2;

int main() {
   srand(time(0)); // Seed the random number generator

   printf("Welcome to the Math Exercise Program!\n\n");

   int numQuestions = getInput(); // Get user input for number of questions

   int numCorrect = 0; // Keep track of correct answers
   for (int i = 0; i < numQuestions; i++) {
      generateQuestion(); // Generate a new question
      int correctAnswer = calculateAnswer(); // Calculated correct answer
      int userAnswer = getInput(); // Get user input for answer
      evaluateAnswer(userAnswer, correctAnswer); // Check if user answer is correct and give feedback
      if (userAnswer == correctAnswer) {
         numCorrect++;
      }
   }

   printf("\n\nYou answered %d out of %d questions correctly.\n", numCorrect, numQuestions);
   if (numCorrect == numQuestions) {
      printf("Congratulations! You have mastered basic arithmetic!\n");
   } else {
      printf("You may benefit from practicing more basic arithmetic.\n");
   }

   return 0;
}

int getInput() {
   int input;
   while (1) { // Loop until valid input is entered
      printf("Enter a positive integer: ");
      if (scanf("%d", &input) == 1 && input > 0) {
         return input;
      } else {
         printf("Invalid input. Please enter a positive integer.\n");
         fflush(stdin); // Clear the input buffer if invalid input is entered
      }
   }
}

void generateQuestion() {
   num1 = rand() % 10 + 1; // Generate a random number between 1 and 10
   num2 = rand() % 10 + 1;
   printf("\nWhat is %d + %d?\n", num1, num2);
}

int calculateAnswer() {
   return num1 + num2;
}

void evaluateAnswer(int answer, int correctAnswer) {
   if (answer == correctAnswer) {
      printf("Correct!\n");
   } else {
      printf("Incorrect. The correct answer is %d.\n", correctAnswer);
   }
}