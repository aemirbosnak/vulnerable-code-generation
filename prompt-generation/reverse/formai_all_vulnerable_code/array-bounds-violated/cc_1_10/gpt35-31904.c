//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGUMENTS 64

void print_grateful_message(void) {
  printf("Grateful shell prompts you to enter a command:\n");
}

int main (void) {
  char input[MAX_INPUT_LENGTH];
  char *arguments[MAX_ARGUMENTS];
  int i;

  while (1) {
    print_grateful_message();
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strlen(input)-1] = '\0'; // Remove newline character

    // Parse command into arguments array
    char *token = strtok(input, " ");
    i = 0;
    while (token != NULL) {
      arguments[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    arguments[i] = NULL;

    // Handle exit command
    if (strcmp(arguments[0], "exit") == 0) {
      printf("Thank you for using Grateful shell!\n");
      exit(0);
    }

    int pid = fork(); // Fork to create new child process

    if (pid == -1) {
      printf("Error: Fork failed. %s\n", strerror(errno));
      exit(1);
    } else if (pid == 0) {
      // Child process
      int result = execvp(arguments[0], arguments);
      if (result == -1) {
        printf("Error: Command not found. %s\n", strerror(errno));
        exit(1);
      }
    } else {
      // Parent process
      int status;
      waitpid(pid, &status, 0); // Wait for child process to finish
    }
  }

  return 0; // Should never be reached
}