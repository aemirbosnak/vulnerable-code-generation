//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of words in a sentence
#define MAX_WORDS 10

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the number of seconds for the test
#define TEST_DURATION 60

// Function to generate a random sentence
char *generate_sentence() {
  // Allocate memory for the sentence
  char *sentence = malloc(MAX_WORDS * MAX_WORD_LENGTH);

  // Generate a random number of words for the sentence
  int num_words = rand() % MAX_WORDS + 1;

  // Generate each word in the sentence
  for (int i = 0; i < num_words; i++) {
    // Generate a random length for the word
    int word_length = rand() % MAX_WORD_LENGTH + 1;

    // Generate the word
    for (int j = 0; j < word_length; j++) {
      sentence[i * MAX_WORD_LENGTH + j] = 'a' + rand() % 26;
    }

    // Add a space after the word
    sentence[i * MAX_WORD_LENGTH + word_length] = ' ';
  }

  // Remove the last space from the sentence
  sentence[num_words * MAX_WORD_LENGTH - 1] = '\0';

  // Return the sentence
  return sentence;
}

// Function to start the typing speed test
void start_test() {
  // Generate a random sentence
  char *sentence = generate_sentence();

  // Print the sentence to the user
  printf("Type the following sentence as quickly and accurately as possible:\n");
  printf("%s\n", sentence);

  // Start the timer
  time_t start_time = time(NULL);

  // Get the user's input
  char *user_input = malloc(strlen(sentence) + 1);
  scanf("%s", user_input);

  // Stop the timer
  time_t end_time = time(NULL);

  // Calculate the typing speed
  int num_characters = strlen(sentence);
  int num_seconds = end_time - start_time;
  int typing_speed = (num_characters / num_seconds) * 60;

  // Print the results of the test
  printf("Your typing speed is %d words per minute.\n", typing_speed);

  // Free the memory allocated for the sentence and user input
  free(sentence);
  free(user_input);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Ask the user if they want to start the test
  printf("Are you ready to start the typing speed test? (y/n)\n");
  char input;
  scanf(" %c", &input);

  // Start the test if the user enters 'y'
  if (input == 'y') {
    start_test();
  } else {
    printf("Okay, maybe next time!\n");
  }

  return 0;
}