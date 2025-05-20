//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Function to read a line from the input file
char *read_line(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  if ((read = getline(&line, &len, fp)) != -1) {
    // Remove the newline character from the end of the line
    if (line[read - 1] == '\n') {
      line[read - 1] = '\0';
    }
  }

  return line;
}

// Function to translate a line of Cat Language to English
char *translate_line(char *line) {
  char *english_line = malloc(MAX_LINE_LENGTH);
  int i = 0;
  int j = 0;

  while (line[i] != '\0') {
    switch (line[i]) {
      case 'a':
        english_line[j++] = 'e';
        break;
      case 'e':
        english_line[j++] = 'i';
        break;
      case 'i':
        english_line[j++] = 'o';
        break;
      case 'o':
        english_line[j++] = 'u';
        break;
      case 'u':
        english_line[j++] = 'a';
        break;
      default:
        english_line[j++] = line[i];
        break;
    }

    i++;
  }

  english_line[j] = '\0';

  return english_line;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the input file was specified
  if (argc < 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  // Open the input file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("Error opening input file");
    return 1;
  }

  // Read the input file line by line
  char *line;
  while ((line = read_line(fp)) != NULL) {
    // Translate the line of Cat Language to English
    char *english_line = translate_line(line);

    // Print the English translation of the line
    printf("%s\n", english_line);

    // Free the memory allocated for the English translation
    free(english_line);

    // Free the memory allocated for the original line
    free(line);
  }

  // Close the input file
  fclose(fp);

  return 0;
}