//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char input[100];
  char* args[10];

  // Display a bizarre welcome message
  printf("Welcome to the parallel universe shell!\n");
  printf("Your thoughts will be converted to code here.\n");
  printf("Type 'help' for assistance or 'exit' to leave the universe.\n");

  while(1) {
    // Display prompt
    printf("\n%s@parallel-universe ~$ ", getenv("USER"));

    // Get user input
    fgets(input, 100, stdin);

    // Tokenize user input
    char* token = strtok(input, " ");
    int i = 0;

    while(token != NULL) {
      args[i++] = token;
      token = strtok(NULL, " ");
    }

    args[i-1][strlen(args[i-1])-1] = '\0'; // Remove newline character

    // Check for built-in commands
    if(strcmp(args[0], "help") == 0) {
      printf("You are in a surreal universe, there is no help.\n");
    } else if(strcmp(args[0], "exit") == 0) {
      printf("You are returning to the normal universe.\n");
      break;
    } else {
      pid_t pid = fork();
      if(pid == 0) {
        // Child process
        execvp(args[0], args); // Execute command
        printf("Unknown command. Please try again.\n");
        exit(EXIT_FAILURE);
      } else if(pid < 0) {
        printf("Error forking.\n");
        exit(EXIT_FAILURE);
      } else {
        wait(NULL); // Wait for child process to finish
      }
    }
  }
  return 0;
}