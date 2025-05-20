#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr = NULL;
  int i = 0;

  // Allocate memory for the text editor
  ptr = malloc(1024);

  // Get the text editor's input
  printf("Enter text: ");
  scanf("%s", ptr);

  // Dereference the pointer to the memory
  (*(ptr + 1024)) = 'A';

  // Print the text editor's output
  printf("Your text: %s", ptr);

  // Free the memory allocated for the text editor
  free(ptr);

  return 0;
}
