//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum number of words to store.
#define MAX_WORDS 1000

// The maximum length of a word.
#define MAX_WORD_LENGTH 20

// A struct to store a word and its frequency.
typedef struct {
  char word[MAX_WORD_LENGTH];
  int frequency;
} Word;

// A function to compare two words.
int compare_words(const void *a, const void *b) {
  const Word *word1 = (const Word *)a;
  const Word *word2 = (const Word *)b;
  return strcmp(word1->word, word2->word);
}

// A function to print a word and its frequency.
void print_word(const Word *word) {
  printf("%s: %d\n", word->word, word->frequency);
}

// A function to count the frequency of words in a file.
void count_words(const char *filename) {
  // Open the file.
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  // Create an array to store the words.
  Word words[MAX_WORDS];

  // Read the file and count the words.
  int num_words = 0;
  char word[MAX_WORD_LENGTH];
  while (fscanf(file, "%s", word) != EOF) {
    // Check if the word is already in the array.
    int found = 0;
    for (int i = 0; i < num_words; i++) {
      if (strcmp(words[i].word, word) == 0) {
        words[i].frequency++;
        found = 1;
        break;
      }
    }

    // If the word is not in the array, add it to the array.
    if (!found) {
      strcpy(words[num_words].word, word);
      words[num_words].frequency = 1;
      num_words++;
    }
  }

  // Close the file.
  fclose(file);

  // Sort the words by frequency.
  qsort(words, num_words, sizeof(Word), compare_words);

  // Print the words and their frequencies.
  for (int i = 0; i < num_words; i++) {
    print_word(&words[i]);
  }
}

int main(int argc, char *argv[]) {
  // Check if the user has provided a filename.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return 1;
  }

  // Count the words in the file.
  count_words(argv[1]);

  return 0;
}