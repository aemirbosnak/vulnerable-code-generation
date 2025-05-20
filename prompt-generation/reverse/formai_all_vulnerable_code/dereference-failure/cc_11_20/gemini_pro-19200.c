//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *input;
  int size = 0;

  // Get the input from the user.
  printf("Enter your string: ");
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    size++;
  }

  // Allocate memory for the input.
  input = malloc(size + 1);
  if (input == NULL) {
    fprintf(stderr, "Error: could not allocate memory.\n");
    return EXIT_FAILURE;
  }

  // Copy the input into the allocated memory.
  rewind(stdin);
  int i = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
    input[i++] = c;
  }
  input[i] = '\0';

  // Count the number of words in the input.
  int words = 0;
  int in_word = 0;
  for (i = 0; i < size; i++) {
    if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
      in_word = 0;
    } else if (!in_word) {
      words++;
      in_word = 1;
    }
  }

  // Print the number of words to the console.
  printf("The number of words in your string is: %d\n", words);

  // Free the allocated memory.
  free(input);

  return EXIT_SUCCESS;
}