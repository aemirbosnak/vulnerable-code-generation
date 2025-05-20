//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_WORD_LENGTH 20
#define MIN_WORD_LENGTH 3

int main() {
  // Generate a random word
  char word[MAX_WORD_LENGTH];
  srand(time(NULL));
  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    word[i] = 'a' + (rand() % 26);
  }

  // Check if the word is valid
  if (strlen(word) < MIN_WORD_LENGTH || strlen(word) > MAX_WORD_LENGTH) {
    printf("Invalid word! Please try again.\n");
    return 1;
  }

  // Calculate the word's complexity
  int complexity = 0;
  for (int i = 0; i < strlen(word); i++) {
    complexity += (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') ? 1 : 2;
  }

  // Print the word and its complexity
  printf("Your word is: %s\n", word);
  printf("Its complexity is: %d\n", complexity);

  // Generate a new word
  char new_word[MAX_WORD_LENGTH];
  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    new_word[i] = 'a' + (rand() % 26);
  }

  // Check if the new word is valid
  if (strlen(new_word) < MIN_WORD_LENGTH || strlen(new_word) > MAX_WORD_LENGTH) {
    printf("Invalid word! Please try again.\n");
    return 1;
  }

  // Calculate the new word's complexity
  complexity = 0;
  for (int i = 0; i < strlen(new_word); i++) {
    complexity += (new_word[i] == 'a' || new_word[i] == 'e' || new_word[i] == 'i' || new_word[i] == 'o' || new_word[i] == 'u') ? 1 : 2;
  }

  // Print the new word and its complexity
  printf("Your new word is: %s\n", new_word);
  printf("Its complexity is: %d\n", complexity);

  return 0;
}