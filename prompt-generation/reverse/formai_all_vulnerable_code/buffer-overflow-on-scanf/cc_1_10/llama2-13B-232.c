//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

int main() {
  // Declare variables
  int age = 0;
  char name[50];
  int score = 0;
  int correct = 0;
  int questions = 0;

  // Print the title of the program
  printf("Welcome to the Magic Quiz! \n");

  // Ask the user for their name
  printf("What is your name? ");
  fgets(name, 50, stdin);

  // Ask the user for their age
  printf("How old are you? ");
  scanf("%d", &age);

  // Print the first question
  printf("Here is your first question: \n");
  printf("What is the capital of France? ");

  // Get the user's answer
  scanf("%s", name);

  // Check if the answer is correct
  if (strcmp(name, "Paris") == 0) {
    correct++;
    printf("Correct! The capital of France is indeed Paris.\n");
  } else {
    printf("Incorrect. The capital of France is Paris.\n");
  }

  // Increase the number of questions
  questions++;

  // Check if the user wants to continue
  printf("Do you want to continue? (Y/N) ");
  char answer;
  scanf(" %c", &answer);

  // If the user wants to continue, ask the next question
  if (answer == 'Y' || answer == 'y') {
    // Print the next question
    printf("Here is your next question: \n");
    printf("What is the largest planet in our solar system? ");

    // Get the user's answer
    scanf("%s", name);

    // Check if the answer is correct
    if (strcmp(name, "Jupiter") == 0) {
      correct++;
      printf("Correct! The largest planet in our solar system is indeed Jupiter.\n");
    } else {
      printf("Incorrect. The largest planet in our solar system is Jupiter.\n");
    }
  } else {
    printf("Goodbye! You scored %d out of %d correct answers.\n", correct, questions);
  }

  // Print the final score
  printf("Your final score is %d out of %d.\n", correct, questions);

  return 0;
}