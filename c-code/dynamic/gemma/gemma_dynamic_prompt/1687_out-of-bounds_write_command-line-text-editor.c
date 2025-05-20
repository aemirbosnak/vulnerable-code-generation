#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = malloc(1024);
  int position = 0;
  int line_number = 1;

  // Loop until the user enters "exit"
  while (strcmp(buffer, "exit") != 0) {
    // Get the user input
    char input[1024];
    printf("Enter text: ");
    scanf("%s", input);

    // Write the input to the buffer
    int len = strlen(input);
    memcpy(buffer + position, input, len);
    position += len;

    // Increment the line number if necessary
    if (position - len >= 0) {
      line_number++;
    }

    // Print the current line
    int i = 0;
    for (; i < line_number - 1; i++) {
      printf("%s\n", buffer);
    }

    // Print the current line
    printf("%s\n", buffer + position - len);
  }

  free(buffer);
  return 0;
}
