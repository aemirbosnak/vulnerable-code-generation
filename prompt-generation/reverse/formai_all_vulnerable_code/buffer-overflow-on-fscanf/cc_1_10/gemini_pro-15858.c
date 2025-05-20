//GEMINI-pro DATASET v1.0 Category: Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10
#define MAX_LENGTH 100

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create an array of strings to store the words
  char words[SIZE][MAX_LENGTH];

  // Read the words from the file
  FILE *file = fopen("words.txt", "r");
  for (int i = 0; i < SIZE; i++) {
    fscanf(file, "%s", words[i]);
  }
  fclose(file);

  // Get a random word
  int randomIndex = rand() % SIZE;
  char *word = words[randomIndex];

  // Print the word
  printf("The word is: %s\n", word);

  // Get the user's guess
  char guess[MAX_LENGTH];
  printf("Guess a letter: ");
  scanf("%s", guess);

  // Check if the user's guess is correct
  int correct = 0;
  for (int i = 0; i < strlen(word); i++) {
    if (guess[0] == word[i]) {
      correct = 1;
      break;
    }
  }

  // Print the result
  if (correct) {
    printf("Correct!\n");
  } else {
    printf("Incorrect.\n");
  }

  return 0;
}