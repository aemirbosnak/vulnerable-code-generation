//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>

  int main() {
    // Initialize variables
    char word[256];
    int word_count = 0;
    int word_length = 0;
    int word_index = 0;
    int word_frequency[256] = {0};

    // Read input from user
    while (fgets(word, sizeof(word), stdin) != NULL) {
      // Remove trailing newline character
      word[strcspn(word, "\n")] = '\0';

      // Remove leading and trailing whitespace
      char* start = word;
      while (isspace(*start)) {
        start++;
      }
      char* end = start + strlen(start) - 1;
      while (isspace(*end)) {
        end--;
      }
      *(end + 1) = '\0';

      // Convert word to lowercase
      char* p = start;
      while (*p) {
        *p = tolower(*p);
        p++;
      }

      // Count word frequency
      word_length = strlen(start);
      word_index = 0;
      while (word_index < word_length) {
        word_frequency[start[word_index]]++;
        word_index++;
      }
      word_count++;
    }

    // Print word frequency table
    printf("Word Frequency Table:\n");
    for (int i = 0; i < 256; i++) {
      if (word_frequency[i] != 0) {
        printf("%c: %d\n", i, word_frequency[i]);
      }
    }

    // Print total word count
    printf("Total word count: %d\n", word_count);

    return 0;
  }