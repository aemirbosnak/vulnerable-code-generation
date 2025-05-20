//Code Llama-13B DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>

  #define SPAM_THRESHOLD 5

  typedef struct {
    char *word;
    int count;
  } WordCount;

  int main() {
    char line[1024];
    char *word;
    WordCount *word_counts;
    int i, j, k;

    // Initialize word counts
    word_counts = (WordCount *)malloc(sizeof(WordCount) * 1024);
    for (i = 0; i < 1024; i++) {
      word_counts[i].word = NULL;
      word_counts[i].count = 0;
    }

    // Read input line by line
    while (fgets(line, 1024, stdin)) {
      // Tokenize line
      word = strtok(line, " \t\n");
      while (word != NULL) {
        // Ignore punctuation
        if (!ispunct(word[0])) {
          // Check if word already exists in word counts
          for (i = 0; i < 1024; i++) {
            if (word_counts[i].word != NULL && strcmp(word_counts[i].word, word) == 0) {
              // Increment count
              word_counts[i].count++;
              break;
            }
          }
          // Add new word if not found
          if (i == 1024) {
            for (j = 0; j < 1024; j++) {
              if (word_counts[j].word == NULL) {
                word_counts[j].word = strdup(word);
                word_counts[j].count = 1;
                break;
              }
            }
          }
        }
        // Get next word
        word = strtok(NULL, " \t\n");
      }
    }

    // Print word counts
    for (i = 0; i < 1024; i++) {
      if (word_counts[i].word != NULL) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
      }
    }

    // Free memory
    for (i = 0; i < 1024; i++) {
      if (word_counts[i].word != NULL) {
        free(word_counts[i].word);
      }
    }
    free(word_counts);

    return 0;
  }