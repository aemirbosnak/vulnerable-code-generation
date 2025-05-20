//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024

void main(int argc, char **argv) {
  char input[MAX_INPUT_SIZE];
  char *token;
  int i, j, k;
  pid_t pid;
  char *cmd[3];

  while (1) {
    printf("\n%s%c", "Enter command (type 'exit' to quit): ", 27); // ANSI escape code for reverse video mode
    fgets(input, MAX_INPUT_SIZE, stdin); // read user input
    input[strlen(input) - 1] = '\0'; // remove newline character

    if (strcmp(input, "exit") == 0) { // check if user entered 'exit'
      break;
    }

    token = strtok(input, " "); // tokenize input by space

    cmd[0] = (char *) malloc(strlen(token) + 1); // allocate memory for command array
    strcpy(cmd[0], token); // copy command to command array

    i = 1;

    while ((token = strtok(NULL, " "))) { // tokenize remaining input
      cmd[i++] = (char *) malloc(strlen(token) + 1); // allocate memory for arguments
      strcpy(cmd[i - 1], token); // copy argument to command array
    }

    cmd[i] = NULL; // set last element to NULL

    if ((pid = fork()) < 0) { // fork process
      printf("\n%s%cError: Fork failed.%c\n", 27, 7, 27);
      for (i = 0; i < i; i++) {
        free(cmd[i]);
      }
      free(cmd);
    } else if (pid == 0) { // child process
      execvp(cmd[0], cmd); // execute command
      printf("\n%s%cError: Execution failed.%c\n", 27, 7, 27);
      for (i = 0; i < i; i++) {
        free(cmd[i]);
      }
      free(cmd);
      exit(1);
    } else { // parent process
      waitpid(pid, NULL, 0); // wait for child process to finish
    }

    for (i = 0; i < i; i++) {
      free(cmd[i]);
    }
    free(cmd);
  }
}