//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *str) {
  int count = 0;
  int i = 0;
  while (str[i]) {
    if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
      count++;
    }
    i++;
  }
  return count + 1;
}

// Function to count the number of lines in a string
int countLines(char *str) {
  int count = 0;
  int i = 0;
  while (str[i]) {
    if (str[i] == '\n') {
      count++;
    }
    i++;
  }
  return count + 1;
}

// Function to count the number of characters in a string
int countChars(char *str) {
  int count = 0;
  int i = 0;
  while (str[i]) {
    count++;
    i++;
  }
  return count;
}

// Function to print the histogram of a string
void printHistogram(char *str) {
  int i;
  int counts[256];
  memset(counts, 0, sizeof(counts));
  for (i = 0; str[i]; i++) {
    counts[(int)str[i]]++;
  }
  for (i = 0; i < 256; i++) {
    if (counts[i] > 0) {
      printf("%c: %d\n", i, counts[i]);
    }
  }
}

int main() {
  // Get the input string from the user
  char str[1000];
  printf("Enter a string: ");
  gets(str);

  // Count the number of words, lines, and characters in the string
  int numWords = countWords(str);
  int numLines = countLines(str);
  int numChars = countChars(str);

  // Print the results
  printf("Number of words: %d\n", numWords);
  printf("Number of lines: %d\n", numLines);
  printf("Number of characters: %d\n", numChars);
  printf("\n");
  printHistogram(str);

  return 0;
}