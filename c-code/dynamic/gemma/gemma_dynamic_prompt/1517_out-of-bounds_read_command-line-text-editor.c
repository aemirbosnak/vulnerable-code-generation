#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *text = NULL;
  int size = 0;
  char ch;

  // Allocate memory for the text
  text = malloc(size);

  // Read character from the user
  ch = getchar();

  // While the user has not entered a newline character, keep reading characters and expanding the text buffer
  while (ch != '\n') {
    // Reallocate the text buffer if necessary
    if (size < 10) {
      size *= 2;
      text = realloc(text, size);
    }

    // Append the character to the text
    text[size - 1] = ch;
    size++;
    ch = getchar();
  }

  // Print the text
  printf("%s", text);

  // Free the memory allocated for the text
  free(text);

  return 0;
}
