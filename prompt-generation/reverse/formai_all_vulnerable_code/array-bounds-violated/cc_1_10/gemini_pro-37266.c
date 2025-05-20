//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Count the number of words in a string.
int count_words(char *str) {
  int words = 0;
  int in_word = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      in_word = 0;
    } else if (!in_word) {
      in_word = 1;
      words++;
    }
  }

  return words;
}

// Print a histogram of the word lengths in a string.
void print_histogram(char *str) {
  int lengths[100] = {0};

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      continue;
    }

    int length = 0;
    while (str[i] != ' ' && str[i] != '\0') {
      length++;
      i++;
    }

    lengths[length - 1]++;
  }

  for (int i = 0; i < 100; i++) {
    if (lengths[i] > 0) {
      printf("%d: %d\n", i + 1, lengths[i]);
    }
  }
}

// Main function.
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    return 1;
  }

  char *str = argv[1];

  int words = count_words(str);
  printf("Number of words: %d\n", words);

  print_histogram(str);

  return 0;
}