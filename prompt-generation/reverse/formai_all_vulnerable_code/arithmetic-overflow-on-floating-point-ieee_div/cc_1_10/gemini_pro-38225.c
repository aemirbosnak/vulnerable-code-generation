//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Type a sentence to test your speed.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // The sentence to type.
  char sentence[] = "The quick brown fox jumps over the lazy dog.";

  // The length of the sentence.
  int sentence_length = sizeof(sentence) - 1;

  // The time in milliseconds to start the timer.
  clock_t start_time = 0;

  // The time in milliseconds to stop the timer.
  clock_t end_time = 0;

  // The elapsed time in milliseconds.
  double elapsed_time = 0;

  // The number of characters typed per minute.
  double wpm = 0;

  // Start the timer.
  start_time = clock();

  // Prompt the user to type the sentence.
  printf("Type the following sentence as quickly as possible:\n\n%s\n\n", sentence);

  // Wait for the user to press the Enter key.
  while (getchar() != '\n') {
  }

  // Stop the timer.
  end_time = clock();

  // Calculate the elapsed time in milliseconds.
  elapsed_time = (double)(end_time - start_time);

  // Calculate the number of characters typed per minute.
  wpm = (double)(sentence_length / 5) * (60000 / elapsed_time);

  // Print the results.
  printf("\nYour typing speed is: %.2f WPM\n", wpm);

  return 0;
}