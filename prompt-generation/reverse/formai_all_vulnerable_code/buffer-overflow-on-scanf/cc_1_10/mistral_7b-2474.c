//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_LENGTH 5
#define MAX_STRING_LENGTH 100
#define NUM_ROUNDS 7

// Function to generate random number
int random_number(int limit) {
  int rand_num;
  clock_t start = clock();

  rand_num = rand() % limit;
  clock_t end = clock();
  double elapsed_time = (end - start) / CLOCKS_PER_SEC;

  if (elapsed_time < 0.001) {
    random_number(limit); // Recursively call if time is too short
  }

  return rand_num;
}

// Function to perform encryption using surrealist logic
void encrypt_string(char *input, char *output) {
  char words[NUM_ROUNDS][WORD_LENGTH + 1];
  int i, j, k, rand_index;
  int is_vowel[WORD_LENGTH];
  int vowels[5] = {'a', 'e', 'i', 'o', 'u'};

  strncpy(words[0], input, WORD_LENGTH);
  words[0][WORD_LENGTH] = '\0';

  for (i = 1; i < NUM_ROUNDS; i++) {
    strncpy(words[i], words[i - 1], WORD_LENGTH);
    words[i][WORD_LENGTH] = '\0';

    for (j = 0; j < WORD_LENGTH; j++) {
      is_vowel[j] = 0;

      if (words[i - 1][j] == '\0') {
        break;
      }

      if (strchr(vowels, words[i - 1][j]) != NULL) {
        is_vowel[j] = 1;
      }
    }

    // Surrealist logic: If there are more vowels in a word than consonants, swap the position of the last consonant and vowel
    if (i % 2 == 0) {
      for (j = 0; j < WORD_LENGTH; j++) {
        if (is_vowel[j] == 1 && j != WORD_LENGTH - 1) {
          continue;
        }

        if (is_vowel[j] == 0 && j != 0) {
          k = j;
          j = WORD_LENGTH - 1;
          words[i][k] = words[i][j];
          words[i][j] = words[i][k];
          break;
        }
      }
    }

    // Surrealist logic: Randomly replace a character with another character
    rand_index = random_number(WORD_LENGTH);
    words[i][rand_index] = '!';
  }

  strcat(output, words[NUM_ROUNDS - 1]);
}

int main() {
  char input[MAX_STRING_LENGTH];
  char output[MAX_STRING_LENGTH];

  printf("Enter a string to encrypt: ");
  scanf("%s", input);

  encrypt_string(input, output);

  printf("Encrypted string: %s\n", output);

  return 0;
}