//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
  // Get the input text from the user.
  char *text = malloc(sizeof(char) * 10000);
  printf("Enter your text:\n");
  scanf("%[^\n]", text);

  // Tokenize the input text into words.
  int num_words = 0;
  char *words[10000];
  char *word = strtok(text, " ");
  while (word != NULL) {
    words[num_words] = word;
    num_words++;
    word = strtok(NULL, " ");
  }

  // Count the number of occurrences of each word.
  int word_counts[10000];
  for (int i = 0; i < num_words; i++) {
    int count = 0;
    for (int j = 0; j < num_words; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        count++;
      }
    }
    word_counts[i] = count;
  }

  // Sort the words by their frequency.
  for (int i = 0; i < num_words - 1; i++) {
    for (int j = i + 1; j < num_words; j++) {
      if (word_counts[i] < word_counts[j]) {
        int temp_count = word_counts[i];
        word_counts[i] = word_counts[j];
        word_counts[j] = temp_count;

        char *temp_word = words[i];
        words[i] = words[j];
        words[j] = temp_word;
      }
    }
  }

  // Print the top 10 most frequent words.
  printf("The top 10 most frequent words are:\n");
  for (int i = 0; i < 10 && i < num_words; i++) {
    printf("%s: %d\n", words[i], word_counts[i]);
  }

  // Free the allocated memory.
  free(text);
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }

  return 0;
}