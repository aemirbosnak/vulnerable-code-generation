//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read a line of text from a file
char *readLine(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  // Allocate memory for the line
  line = malloc(MAX_LINE_LENGTH);
  if (line == NULL) {
    perror("malloc");
    return NULL;
  }

  // Read a line of text from the file
  read = getline(&line, &len, fp);
  if (read == -1) {
    perror("getline");
    free(line);
    return NULL;
  }

  // Remove the newline character from the end of the line
  if (line[read - 1] == '\n') {
    line[read - 1] = '\0';
  }

  return line;
}

// Function to count the number of words in a line of text
int countWords(char *line) {
  int words = 0;
  int inWord = 0;
  int i;

  for (i = 0; i < strlen(line); i++) {
    if (isspace(line[i])) {
      inWord = 0;
    } else if (!inWord) {
      words++;
      inWord = 1;
    }
  }

  return words;
}

// Function to print the longest word in a line of text
void printLongestWord(char *line) {
  char *longestWord = NULL;
  int longestWordLength = 0;
  char *wordStart = NULL;
  int wordLength = 0;
  int i;

  for (i = 0; i < strlen(line); i++) {
    if (isspace(line[i])) {
      if (wordLength > longestWordLength) {
        longestWord = wordStart;
        longestWordLength = wordLength;
      }
      wordStart = NULL;
      wordLength = 0;
    } else if (wordStart == NULL) {
      wordStart = &line[i];
      wordLength = 1;
    } else {
      wordLength++;
    }
  }

  if (wordLength > longestWordLength) {
    longestWord = wordStart;
    longestWordLength = wordLength;
  }

  if (longestWord != NULL) {
    printf("Longest word: %s\n", longestWord);
  } else {
    printf("No words found in line.\n");
  }
}

int main() {
  // Open the file for reading
  FILE *fp = fopen("text.txt", "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Read each line of the file and process it
  char *line;
  while ((line = readLine(fp)) != NULL) {
    printf("Line: %s\n", line);
    printf("Number of words: %d\n", countWords(line));
    printLongestWord(line);
    printf("\n");

    // Free the memory allocated for the line
    free(line);
  }

  // Close the file
  fclose(fp);

  return EXIT_SUCCESS;
}