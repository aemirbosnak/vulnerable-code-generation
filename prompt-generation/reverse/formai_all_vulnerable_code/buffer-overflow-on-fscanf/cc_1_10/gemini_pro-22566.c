//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct word {
  char word[MAX_WORD_LENGTH];
  int count;
} word;

int main() {
  // Load the dictionary into an array of words.
  FILE *fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    return EXIT_FAILURE;
  }

  word dictionary[MAX_WORDS];
  int num_words = 0;
  while (fscanf(fp, "%s", dictionary[num_words].word) != EOF) {
    dictionary[num_words].count = 0;
    num_words++;
  }
  fclose(fp);

  // Get the input text from the user.
  char input[1000];
  printf("Enter some text: ");
  fgets(input, sizeof(input), stdin);

  // Split the input text into words.
  char *words[100];
  int num_words_in_input = 0;
  char *word = strtok(input, " ");
  while (word != NULL) {
    words[num_words_in_input++] = word;
    word = strtok(NULL, " ");
  }

  // Check each word in the input text against the dictionary.
  for (int i = 0; i < num_words_in_input; i++) {
    int found = 0;
    for (int j = 0; j < num_words; j++) {
      if (strcmp(words[i], dictionary[j].word) == 0) {
        dictionary[j].count++;
        found = 1;
        break;
      }
    }

    // If the word was not found in the dictionary, print it out.
    if (!found) {
      printf("The word '%s' is not in the dictionary.\n", words[i]);
    }
  }

  // Print out the number of times each word in the dictionary was found in the input text.
  for (int i = 0; i < num_words; i++) {
    if (dictionary[i].count > 0) {
      printf("The word '%s' was found %d times in the input text.\n", dictionary[i].word, dictionary[i].count);
    }
  }

  return EXIT_SUCCESS;
}