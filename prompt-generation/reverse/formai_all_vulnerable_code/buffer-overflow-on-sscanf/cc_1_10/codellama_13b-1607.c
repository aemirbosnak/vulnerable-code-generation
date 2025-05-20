//Code Llama-13B DATASET v1.0 Category: System boot optimizer ; Style: cheerful
// System boot optimizer in a cheerful style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  printf("Hello, world!\n");

  // Initialize variables
  int i, j, k;
  char input[100];
  char command[100];
  char *token;

  // Main loop
  while (1) {
    // Print prompt
    printf(">>> ");

    // Get input
    fgets(input, 100, stdin);

    // Tokenize input
    token = strtok(input, " ");

    // Check for exit command
    if (strcmp(token, "exit") == 0) {
      break;
    }

    // Parse input
    sscanf(token, "%s %s %s", command, &i, &j);

    // Execute command
    if (strcmp(command, "add") == 0) {
      k = i + j;
      printf("%d\n", k);
    } else if (strcmp(command, "sub") == 0) {
      k = i - j;
      printf("%d\n", k);
    } else if (strcmp(command, "mul") == 0) {
      k = i * j;
      printf("%d\n", k);
    } else if (strcmp(command, "div") == 0) {
      k = i / j;
      printf("%d\n", k);
    } else {
      printf("Invalid command\n");
    }
  }

  // Exit program
  return 0;
}