//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome message
  printf("Welcome to the Typing Speed Test! Get ready to show off your lightning-fast fingers!\n\n");

  // Generate a random sentence
  char sentence[100];
  srand(time(NULL));
  int numWords = rand() % 10 + 10; // Generate a random number of words between 10 and 19
  for (int i = 0; i < numWords; i++) {
    int wordLength = rand() % 10 + 3; // Generate a random word length between 3 and 12
    for (int j = 0; j < wordLength; j++) {
      sentence[i * wordLength + j] = 'a' + rand() % 26; // Generate a random lowercase letter
    }
    sentence[i * wordLength + wordLength] = ' '; // Add a space after each word
  }
  sentence[numWords * numWords] = '\0'; // Null-terminate the sentence

  // Display the sentence to the user
  printf("Your sentence to type:\n%s\n", sentence);

  // Start the timer
  clock_t start = clock();

  // Get the user's input
  char input[100];
  printf("Type the sentence as fast as you can:\n");
  scanf("%[^\n]", input);

  // Stop the timer
  clock_t end = clock();

  // Calculate the typing speed
  double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
  double speed = (double)strlen(sentence) / timeTaken;

  // Display the results
  printf("\nWow, you typed %d words in %.2f seconds!\n", numWords, timeTaken);
  printf("Your typing speed is %.2f words per minute!\n", speed * 60);

  // Surprise message
  if (speed > 100) {
    printf("\nHoly smokes! You're a typing machine!\n");
  } else if (speed > 75) {
    printf("\nNice job! You're a speedy typer!\n");
  } else if (speed > 50) {
    printf("\nNot bad! You're getting there.\n");
  } else {
    printf("\nKeep practicing! You'll get faster with time.\n");
  }

  return 0;
}