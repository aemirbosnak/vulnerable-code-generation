//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a word
typedef struct {
  char *word;
  int count;
} Word;

// Define a function to compare two words
int compare_words(const void *a, const void *b) {
  Word *word1 = (Word *)a;
  Word *word2 = (Word *)b;
  return strcmp(word1->word, word2->word);
}

// Define a function to print a word
void print_word(Word *word) {
  printf("%s: %d\n", word->word, word->count);
}

// Define a function to count the number of occurrences of each word in a text
int count_words(char *text, Word **words) {
  // Split the text into words
  char *token = strtok(text, " ");

  // Allocate memory for the words array
  int num_words = 0;
  while (token != NULL) {
    num_words++;
    *words = realloc(*words, num_words * sizeof(Word));
    (*words)[num_words - 1].word = strdup(token);
    (*words)[num_words - 1].count = 0;
    token = strtok(NULL, " ");
  }

  // Count the number of occurrences of each word
  for (int i = 0; i < num_words; i++) {
    for (int j = i + 1; j < num_words; j++) {
      if (strcmp((*words)[i].word, (*words)[j].word) == 0) {
        (*words)[i].count++;
        free((*words)[j].word);
        (*words)[j] = (*words)[num_words - 1];
        num_words--;
        j--;
      }
    }
  }

  return num_words;
}

// Define a function to print the words in sorted order
void print_words(Word *words, int num_words) {
  // Sort the words in ascending order
  qsort(words, num_words, sizeof(Word), compare_words);

  // Print the words
  for (int i = 0; i < num_words; i++) {
    print_word(&words[i]);
  }
}

int main() {
  // Get the text from the user
  char *text = (char *)malloc(1000 * sizeof(char));
  printf("Enter the text: ");
  gets(text);

  // Count the number of occurrences of each word in the text
  Word *words = NULL;
  int num_words = count_words(text, &words);

  // Print the words in sorted order
  print_words(words, num_words);

  // Free the memory allocated for the words array
  for (int i = 0; i < num_words; i++) {
    free(words[i].word);
  }
  free(words);

  // Free the memory allocated for the text
  free(text);

  return 0;
}