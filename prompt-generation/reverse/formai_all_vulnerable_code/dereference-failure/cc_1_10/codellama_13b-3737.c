//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
/*
 * Surrealist Shell
 * -----------------
 * A unique C Basic Unix-like Shell program with a surrealist twist.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Initialize the shell
  printf("Welcome to the Surrealist Shell!\n");

  // Loop until the user exits
  while (1) {
    // Prompt the user for input
    printf("$ ");
    char *command = malloc(1024);
    fgets(command, 1024, stdin);

    // Parse the input
    char *token = strtok(command, " ");
    if (token == NULL) {
      continue;
    }

    // Handle the command
    if (strcmp(token, "cd") == 0) {
      // Change the working directory
      token = strtok(NULL, " ");
      if (token == NULL) {
        printf("usage: cd <directory>\n");
        continue;
      }
      if (chdir(token) != 0) {
        printf("cd: %s: No such file or directory\n", token);
      }
    } else if (strcmp(token, "echo") == 0) {
      // Print the rest of the input
      token = strtok(NULL, " ");
      if (token == NULL) {
        printf("usage: echo <string>\n");
        continue;
      }
      printf("%s\n", token);
    } else if (strcmp(token, "exit") == 0) {
      // Exit the shell
      break;
    } else {
      // Invalid command
      printf("Invalid command: %s\n", token);
    }
  }

  return 0;
}