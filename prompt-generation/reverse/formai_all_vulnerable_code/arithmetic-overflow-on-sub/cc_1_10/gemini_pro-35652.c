//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables
  int words_per_minute;
  int characters_per_minute;
  int errors;
  int num_lines = 0;
  int num_words = 0;
  int num_characters = 0;
  int num_errors = 0;
  int start_time, end_time;
  char input[100];
  char target[100];
  char ch;

  // Print instructions
  printf("Instructions:\n");
  printf("1. Type the text that appears on the screen.\n");
  printf("2. Press enter when you are finished.\n");
  printf("3. The program will calculate your typing speed and accuracy.\n\n");

  // Get the target text
  printf("Enter the text you want to type:\n");
  fgets(target, 100, stdin);

  // Start the timer
  start_time = time(NULL);

  // Get the user's input
  printf("Type the text:\n");
  while ((ch = getchar()) != '\n') {
    if (ch == target[num_characters]) {
      num_characters++;
    } else {
      num_errors++;
    }
  }

  // Stop the timer
  end_time = time(NULL);

  // Calculate the results
  words_per_minute = (num_words / 5) * 60 / (end_time - start_time);
  characters_per_minute = (num_characters / 5) * 60 / (end_time - start_time);
  errors = num_errors * 100 / num_characters;

  // Print the results
  printf("Words per minute: %d\n", words_per_minute);
  printf("Characters per minute: %d\n", characters_per_minute);
  printf("Errors: %d\n", errors);

  return 0;
}