//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of the input text
#define MAX_TEXT_LENGTH 1000

// Define the minimum number of words to type
#define MIN_WORDS_TO_TYPE 100

// Define the maximum time limit in seconds
#define MAX_TIME_LIMIT 60

// Define the number of correct words to type
#define CORRECT_WORDS_TO_TYPE 95

// Define the number of incorrect words to type
#define INCORRECT_WORDS_TO_TYPE 5

// Define the accuracy threshold
#define ACCURACY_THRESHOLD 0.95

// Define the speed threshold
#define SPEED_THRESHOLD 60

// Define the welcome message
#define WELCOME_MESSAGE "Welcome to the Typing Speed Test!"

// Define the instructions message
#define INSTRUCTIONS_MESSAGE "Type the following text as accurately and quickly as possible. You have 60 seconds."

// Define the start message
#define START_MESSAGE "Press any key to start."

// Define the end message
#define END_MESSAGE "Time's up!"

// Define the results message
#define RESULTS_MESSAGE "Your results are:"

// Define the accuracy message
#define ACCURACY_MESSAGE "Accuracy: %d%%"

// Define the speed message
#define SPEED_MESSAGE "Speed: %d words per minute"

// Define the congratulations message
#define CONGRATULATIONS_MESSAGE "Congratulations! You passed the test."

// Define the failure message
#define FAILURE_MESSAGE "Sorry, you failed the test."

// Define the main function
int main() {
  // Print the welcome message
  printf("%s\n", WELCOME_MESSAGE);

  // Print the instructions message
  printf("%s\n", INSTRUCTIONS_MESSAGE);

  // Prompt the user to press any key to start
  printf("%s\n", START_MESSAGE);
  getchar();

  // Start the timer
  clock_t start = clock();

  // Get the input text from the user
  char text[MAX_TEXT_LENGTH];
  printf("Type the following text:\n");
  scanf("%s", text);

  // Stop the timer
  clock_t end = clock();

  // Calculate the elapsed time in seconds
  double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Calculate the number of words typed
  int words_typed = strlen(text) / 5;

  // Calculate the accuracy
  double accuracy = (double)CORRECT_WORDS_TO_TYPE / (double)(CORRECT_WORDS_TO_TYPE + INCORRECT_WORDS_TO_TYPE);

  // Calculate the speed
  double speed = (double)words_typed / elapsed_time * 60;

  // Print the results message
  printf("%s\n", RESULTS_MESSAGE);

  // Print the accuracy message
  printf(ACCURACY_MESSAGE, (int)(accuracy * 100));

  // Print the speed message
  printf(SPEED_MESSAGE, (int)speed);

  // Check if the user passed the test
  if (accuracy >= ACCURACY_THRESHOLD && speed >= SPEED_THRESHOLD) {
    // Print the congratulations message
    printf("%s\n", CONGRATULATIONS_MESSAGE);
  } else {
    // Print the failure message
    printf("%s\n", FAILURE_MESSAGE);
  }

  return 0;
}