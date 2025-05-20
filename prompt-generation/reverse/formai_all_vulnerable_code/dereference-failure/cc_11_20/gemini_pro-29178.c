//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *str, *token;
  int i = 0, j, k, count = 0, words = 0, max_len = 0;
  char **ptr;

  printf("Enter a string: ");
  str = malloc(sizeof(char) * 100);
  scanf("%[^\n]%*c", str);

  // Count the number of words
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      words++;
    }
  }

  words++;

  // Allocate memory for the array of pointers
  ptr = malloc(sizeof(char *) * words);

  // Tokenize the string
  token = strtok(str, " ");
  ptr[0] = malloc(sizeof(char) * strlen(token));
  strcpy(ptr[0], token);

  j = 1;
  while (token != NULL) {
    token = strtok(NULL, " ");
    if (token != NULL) {
      ptr[j] = malloc(sizeof(char) * strlen(token));
      strcpy(ptr[j], token);
      j++;
    }
  }

  // Find the maximum length of a word
  for (i = 0; i < j; i++) {
    if (strlen(ptr[i]) > max_len) {
      max_len = strlen(ptr[i]);
    }
  }

  // Initialize the count array
  int *count_arr = malloc(sizeof(int) * max_len);
  for (i = 0; i < max_len; i++) {
    count_arr[i] = 0;
  }

  // Count the frequency of each word length
  for (i = 0; i < j; i++) {
    count_arr[strlen(ptr[i]) - 1]++;
  }

  // Print the frequency of each word length
  for (i = 0; i < max_len; i++) {
    if (count_arr[i] > 0) {
      printf("%d-letter words: %d\n", i + 1, count_arr[i]);
    }
  }

  // Free the allocated memory
  free(str);
  for (i = 0; i < j; i++) {
    free(ptr[i]);
  }
  free(ptr);
  free(count_arr);

  return 0;
}