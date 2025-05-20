//FormAI DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char dict[100][20]; // dictionary array
  char line[100]; // input line array
  int num_words, dict_size, i, j, k, l;
  int word_count[100]; // keeps count of each word

  // Read dictionary
  printf("Enter dictionary words (end with blank line):\n");
  dict_size = 0;
  while (fgets(dict[dict_size], 20, stdin) != NULL) {
    if (dict[dict_size][0] == '\n') break; // stop reading if blank line
    dict[dict_size][strlen(dict[dict_size])-1] = '\0'; // remove newline character
    dict_size++;
  }
  printf("Dictionary size: %d\n", dict_size);

  // Read input line
  printf("Enter a line of text:\n");
  fgets(line, 100, stdin);

  // Remove punctuation marks and convert to lowercase
  for (i = 0; i < strlen(line); i++) {
    if (ispunct(line[i])) { // check if character is a punctuation mark
      for (j = i; j < strlen(line); j++) {
        line[j] = line[j+1]; // move characters one position left to remove punctuation mark
      }
      i--; // check the new character at the same position
    }
    else {
      line[i] = tolower(line[i]); // convert to lowercase
    }
  }

  // Count number of words in line
  num_words = 0;
  for (i = 0; i < strlen(line); i++) {
    if (isspace(line[i])) num_words++; // count spaces to count number of words
  }
  if (strlen(line) > 0) num_words++; // add 1 if line is not empty

  // Initialize word count array
  for (i = 0; i < num_words; i++) {
    word_count[i] = 0;
  }

  // Check each word against dictionary
  i = 0; // index of current word
  j = 0; // index of current character in word
  while (i < num_words) {
    if (!isalpha(line[j])) { // check if current character is not a letter (end of word)
      if (j > 0 && isalpha(line[j-1])) { // check if previous character is a letter (not double space)
        char word[20];
        strncpy(word, line+i, j-i); // copy word from input line
        word[j-i] = '\0';
        for (k = 0; k < dict_size; k++) { // check against dictionary
          if (strcmp(word, dict[k]) == 0) word_count[i]++; // increment count if match found
        }
      }
      i++; // move to next word
    }
    j++; // move to next character
  }

  // Print word count results
  printf("The number of times each dictionary word appears in the input line:\n");
  for (i = 0; i < num_words; i++) {
    if (word_count[i] > 0) {
      printf("%s: %d\n", dict[i], word_count[i]);
    }
  }

  return 0;
}