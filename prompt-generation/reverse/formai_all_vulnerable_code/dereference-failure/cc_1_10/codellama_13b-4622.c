//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
/*
 * Basic Unix-like Shell in Claude Shannon style
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10

int main(int argc, char *argv[]) {
  // Declare variables
  char *cmd;
  char *args[MAX_ARGS];
  int i;
  int status;

  // Loop until the user exits
  while (1) {
    // Print the prompt
    printf("$ ");

    // Read the command from the user
    cmd = malloc(sizeof(char) * 100);
    fgets(cmd, 100, stdin);

    // Parse the command into arguments
    for (i = 0; i < MAX_ARGS; i++) {
      args[i] = strtok(cmd, " ");
      if (args[i] == NULL) {
        break;
      }
    }

    // Check if the user wants to exit
    if (strcmp(args[0], "exit") == 0) {
      break;
    }

    // Execute the command
    if (fork() == 0) {
      execvp(args[0], args);
      exit(1);
    } else {
      wait(&status);
    }
  }

  return 0;
}