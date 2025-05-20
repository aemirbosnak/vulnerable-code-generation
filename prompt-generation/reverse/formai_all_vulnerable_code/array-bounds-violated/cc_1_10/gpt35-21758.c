//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_NUM_ARGUMENTS 10

int main() {
  char command[MAX_COMMAND_LENGTH];
  char *token[MAX_NUM_ARGUMENTS];
  int status = 0;
  
  while (1) {
    printf("$ ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    command[strlen(command) - 1] = '\0'; //remove newline character

    if (strcmp(command, "exit") == 0) {
      break;
    }

    pid_t pid = fork();

    if (pid == -1) {
      perror("fork failed");
      exit(1);
    }
    else if (pid == 0) { //child process
      int index = 0;
      token[index] = strtok(command, " ");

      while (token[index] != NULL) {
        index++;
        token[index] = strtok(NULL, " ");
      }
      token[index] = NULL; //set last element to NULL for execvp()

      execvp(token[0], token);

      perror("execvp failed");
      exit(1);
    }
    else { //parent process
      waitpid(pid, &status, 0);

      if (WIFEXITED(status)) {
        printf("Child process exited with status %d\n", WEXITSTATUS(status));
      }
    }
  }

  return 0;
}