//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
// C program to implement a basic Unix-like shell
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// define the maximum length of the command and arguments
#define MAX_CMD_LEN 256
#define MAX_ARGS 10

int main(int argc, char *argv[]) {
  char cmd[MAX_CMD_LEN];
  char *args[MAX_ARGS];
  int status;

  // loop until the user enters "exit" or presses Ctrl+D
  while (1) {
    // print the prompt
    printf("$ ");
    // read the user input
    fgets(cmd, MAX_CMD_LEN, stdin);
    // remove the newline character
    cmd[strcspn(cmd, "\n")] = '\0';
    // split the input into arguments
    args[0] = strtok(cmd, " ");
    int i = 1;
    while (args[i - 1] != NULL && i < MAX_ARGS) {
      args[i] = strtok(NULL, " ");
      i++;
    }
    // check if the command is "exit"
    if (strcmp(args[0], "exit") == 0) {
      break;
    }
    // fork a child process
    pid_t pid = fork();
    if (pid == 0) {
      // child process
      // execute the command
      execvp(args[0], args);
      // if execvp returns, an error occurred
      perror("execvp");
      exit(1);
    } else {
      // parent process
      // wait for the child process to terminate
      wait(&status);
      // print the exit status
      printf("Child process exited with status %d\n", status);
    }
  }

  return 0;
}