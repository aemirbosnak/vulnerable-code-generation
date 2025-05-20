//Code Llama-13B DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
// Typing Speed Test
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  // Declare variables
  char word[100], temp[100], guess[100];
  int i, j, k, n, score = 0, total_score = 0;
  float wpm = 0.0;

  // Initialize variables
  word[0] = '\0';
  temp[0] = '\0';
  guess[0] = '\0';
  n = 0;

  // Generate random word
  srand(time(NULL));
  for (i = 0; i < 100; i++) {
    word[i] = (char)rand() % 26 + 'A';
  }

  // Print random word
  printf("The word is: ");
  for (i = 0; i < 100; i++) {
    printf("%c", word[i]);
  }
  printf("\n");

  // Get user input
  printf("Enter the word: ");
  scanf("%s", guess);

  // Check if guess is correct
  if (strcmp(word, guess) == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect.\n");
  }

  // Calculate total score
  total_score = score / 100.0;

  // Calculate WPM
  wpm = total_score / 5.0;

  // Print result
  printf("Your score is: %d\n", score);
  printf("Your total score is: %.2f\n", total_score);
  printf("Your WPM is: %.2f\n", wpm);

  return 0;
}