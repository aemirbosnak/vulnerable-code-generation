//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LINE 1024 /* The maximum length of a command line. */
#define MAX_ARGS 10   /* The maximum number of arguments in a command line. */

int main(int argc, char *argv[]) {
  char *line;           /* The command line entered by the user. */
  char *args[MAX_ARGS]; /* The arguments in the command line. */
  int num_args;         /* The number of arguments in the command line. */
  int pid;              /* The process ID of the child process. */
  int status;           /* The status of the child process. */

  /* Get the command line from the user. */
  printf("$ ");
  line = malloc(MAX_LINE);
  if (line == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  if (fgets(line, MAX_LINE, stdin) == NULL) {
    perror("fgets");
    exit(EXIT_FAILURE);
  }

  /* Parse the command line into arguments. */
  num_args = 0;
  args[num_args] = strtok(line, " ");
  while (args[num_args] != NULL) {
    num_args++;
    args[num_args] = strtok(NULL, " ");
  }

  /* Check if the command line is empty. */
  if (num_args == 0) {
    printf("Command line is empty.\n");
    return 0;
  }

  /* Check if the command is "exit". */
  if (strcmp(args[0], "exit") == 0) {
    exit(EXIT_SUCCESS);
  }

  /* Fork a child process. */
  pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  /* Execute the command in the child process. */
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(EXIT_FAILURE);
    }
  }

  /* Wait for the child process to terminate. */
  if (wait(&status) == -1) {
    perror("wait");
    exit(EXIT_FAILURE);
  }

  /* Check the status of the child process. */
  if (WIFEXITED(status)) {
    printf("Command exited with status %d.\n", WEXITSTATUS(status));
  } else if (WIFSIGNALED(status)) {
    printf("Command was terminated by signal %d.\n", WTERMSIG(status));
  }

  /* Free the memory allocated for the command line. */
  free(line);

  /* Return to the shell. */
  printf("$ ");
  return 0;
}