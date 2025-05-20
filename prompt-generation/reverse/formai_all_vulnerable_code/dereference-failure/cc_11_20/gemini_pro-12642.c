//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

int main() {
  // Read the input text file.
  FILE *input_file = fopen("input.txt", "r");
  if (input_file == NULL) {
    fprintf(stderr, "Error opening input file.\n");
    return EXIT_FAILURE;
  }

  // Allocate memory for the lines of text.
  char **lines = malloc(MAX_LINES * sizeof(char *));
  if (lines == NULL) {
    fprintf(stderr, "Error allocating memory for lines.\n");
    return EXIT_FAILURE;
  }

  // Read the lines of text into the array.
  int num_lines = 0;
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
    lines[num_lines] = malloc(strlen(line) + 1);
    if (lines[num_lines] == NULL) {
      fprintf(stderr, "Error allocating memory for line %d.\n", num_lines);
      return EXIT_FAILURE;
    }
    strcpy(lines[num_lines], line);
    num_lines++;
  }

  // Close the input file.
  fclose(input_file);

  // Process the lines of text.
  for (int i = 0; i < num_lines; i++) {
    // Convert the line to lowercase.
    for (int j = 0; j < strlen(lines[i]); j++) {
      lines[i][j] = tolower(lines[i][j]);
    }

    // Remove all punctuation from the line.
    for (int j = 0; j < strlen(lines[i]); j++) {
      if (!isalpha(lines[i][j])) {
        lines[i][j] = ' ';
      }
    }

    // Tokenize the line into words.
    char *words[MAX_LINE_LENGTH];
    int num_words = 0;
    char *token = strtok(lines[i], " ");
    while (token != NULL) {
      words[num_words] = token;
      num_words++;
      token = strtok(NULL, " ");
    }

    // Count the number of occurrences of each word.
    int word_counts[MAX_LINE_LENGTH];
    for (int j = 0; j < num_words; j++) {
      word_counts[j] = 0;
      for (int k = 0; k < num_words; k++) {
        if (strcmp(words[j], words[k]) == 0) {
          word_counts[j]++;
        }
      }
    }

    // Print the words and their counts.
    for (int j = 0; j < num_words; j++) {
      printf("%s: %d\n", words[j], word_counts[j]);
    }
  }

  // Free the memory allocated for the lines of text.
  for (int i = 0; i < num_lines; i++) {
    free(lines[i]);
  }
  free(lines);

  return EXIT_SUCCESS;
}