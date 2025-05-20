//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100 // The maximum char length for input

int main()
{
  srand(time(NULL)); // Seed the random number generator

  printf("\n"); // Print blank line for aesthetics

  // Array of randomly generated words for typing test
  char *words[] = {"algorithm",
                   "binary",
                   "byte",
                   "compiler",
                   "debugger",
                   "encryption",
                   "file",
                   "function",
                   "hardware",
                   "integer",
                   "kernel",
                   "logic",
                   "memory",
                   "network",
                   "operating",
                   "program",
                   "queue",
                   "recursive",
                   "software",
                   "terminal",
                   "utility",
                   "variable",
                   "window",
                   "zero"};

  // Number of words in the array
  int num_words = sizeof(words)/sizeof(words[0]);

  // Initialization variables
  int num_chars_typed = 0; // Number of characters typed
  int num_words_typed = 0; // Number of words typed
  int index = rand() % num_words; // Randomly choose a word from array
  printf("Type the following word: %s\n\n", words[index]); // Prompt user to type the word

  // Measure the time taken for the user to type the word
  clock_t start_time = clock();

  // User input buffer
  char input[MAX_LEN];

  // Read user input
  fgets(input, MAX_LEN, stdin);

  // Remove newline character from input
  input[strlen(input)-1] = '\0';

  // Count number of characters and words typed
  for (int i = 0; i < strlen(input); i++)
  {
    if (input[i] == ' ') // Check if space character
    {
      num_words_typed++; // Increment number of words typed
    }
    num_chars_typed++; // Increment number of characters typed
  }
  num_words_typed++; // Add one to account for the last word typed

  clock_t end_time = clock(); // Stop timer

  // Calculate elapsed time and typing speed
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  double typing_speed = (double)num_chars_typed / elapsed_time * 60; // WPM

  printf("\n");

  // Print results
  printf("You typed %d characters in %.2f seconds.\n", num_chars_typed, elapsed_time);
  printf("You typed %d words at a speed of %.2f words per minute.\n", num_words_typed, typing_speed);

  return 0; // End program
}