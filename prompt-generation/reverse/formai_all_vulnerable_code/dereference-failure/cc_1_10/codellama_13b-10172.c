//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
/*
 * Word Frequency Counter
 *
 * This program reads a text file and counts the frequency of each word
 * in the file. The frequency of each word is printed to the console.
 *
 * Usage: ./word_frequency_counter <file_name>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20

int main(int argc, char *argv[]) {
  // Check command-line arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
    return 1;
  }

  // Open file and read its contents
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
    return 1;
  }

  // Create a buffer to store the file contents
  char buffer[1000];

  // Read the file contents into the buffer
  int buffer_size = fread(buffer, 1, 1000, file);
  fclose(file);

  // Split the buffer into individual words
  char *words[100];
  int num_words = 0;
  char *p = buffer;
  while (*p != '\0') {
    // Find the next word
    char *word = strtok(p, " ");
    p = NULL;
    if (word == NULL) {
      break;
    }

    // Add the word to the list of words
    words[num_words] = word;
    num_words++;
  }

  // Count the frequency of each word
  int word_counts[num_words];
  for (int i = 0; i < num_words; i++) {
    word_counts[i] = 0;
    for (int j = 0; j < num_words; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        word_counts[i]++;
      }
    }
  }

  // Print the frequency of each word
  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i], word_counts[i]);
  }

  return 0;
}