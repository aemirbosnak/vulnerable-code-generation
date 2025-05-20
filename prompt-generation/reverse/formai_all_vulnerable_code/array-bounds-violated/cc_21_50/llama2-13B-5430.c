//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 50
#define MAGIC_NUMBER 42

int main() {
  int i, j, k, magic = 0;
  char word[MAX_LENGTH];
  char corrected[MAX_LENGTH];

  printf("Welcome to the Surprising Spell Checker! 😱\n");

  // Ask the user for a word to check
  printf("Enter a word: ");
  fgets(word, MAX_LENGTH, stdin);

  // Check if the word is already corrected
  for (i = 0; i < MAX_LENGTH; i++) {
    if (word[i] == 'e' && word[i + 1] == 'x') {
      // If the word is "ex", it's already corrected! 😱
      magic = MAGIC_NUMBER;
      break;
    }
  }

  // Check for vowels
  for (i = 0; i < MAX_LENGTH; i++) {
    if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
      // If the word contains a vowel, it must be a word! 😱
      magic++;
    }
  }

  // Check for consonants
  for (i = 0; i < MAX_LENGTH; i++) {
    if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') {
      // If the word contains a consonant, it must be a word! 😱
      magic++;
    }
  }

  // Check for special cases
  if (word[0] == 's' && word[1] == 'u' && word[2] == 'p' && word[3] == 'e' && word[4] == 'r') {
    // If the word is "super", it's already corrected! 😱
    magic = MAGIC_NUMBER;
  } else if (word[0] == 'p' && word[1] == 'e' && word[2] == 'n' && word[3] == 'i' && word[4] == 'd') {
    // If the word is "penis", it's already corrected! 😱
    magic = MAGIC_NUMBER;
  }

  // Calculate the score
  if (magic == 0) {
    // If the word is not corrected, the score is 0! 😱
    printf("Your score is 0! 😔\n");
  } else {
    // If the word is corrected, the score is the number of vowels! 😱
    printf("Your score is %d! 😱\n", magic);
  }

  // Print the corrected word
  for (i = 0; i < MAX_LENGTH; i++) {
    corrected[i] = word[i];
  }
  printf("The corrected word is: %s\n", corrected);

  return 0;
}