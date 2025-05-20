//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
  int bufsize = 0, wordcount = 0;
  char **words = NULL;
  char *token;

  while (*str) {
    if (isspace(*str)) {
      *str = '\0';
      wordcount++;
    }
    str++;
  }

  words = malloc((wordcount + 1) * sizeof(char *));
  str = strtok_r(str, DELIM, &token);

  while (str) {
    words[wordcount] = strdup(str);
    wordcount++;
    str = strtok_r(NULL, DELIM, &token);
  }

  return words;
}

int execute_command(char **args) {
  pid_t pid;
  int status;

  pid = fork();

  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(1);
    }
  } else {
    waitpid(pid, &status, 0);
  }

  return 0;
}

int main(int argc, char *argv[]) {
  char input[MAX_COMMAND_LENGTH];
  char **args;

  printf("Welcome to the shape shifting shell!\n");

  while (1) {
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_string(input);
    execute_command(args);
  }

  return 0;
}