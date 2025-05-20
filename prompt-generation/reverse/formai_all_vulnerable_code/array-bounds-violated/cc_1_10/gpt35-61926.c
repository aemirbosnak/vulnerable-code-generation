//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_BUFFER 100

int main() {
  char cmd[MAX_BUFFER];
  char *args[MAX_ARGS+1];
  pid_t pid;
  int status;

  printf("Welcome to Minimalist Shell!\n");

  while(1) {
    printf("> ");
    fgets(cmd, MAX_BUFFER, stdin);

    if(cmd[strlen(cmd)-1] == '\n')
      cmd[strlen(cmd)-1] = '\0';

    if(strcmp(cmd, "exit") == 0)
      exit(0);

    char *token = strtok(cmd, " ");
    int i = 0;
    while(token != NULL && i < MAX_ARGS) {
      args[i++] = token;
      token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid = fork();
    if(pid < 0) {
      printf("Fork failed!");
      exit(1);
    } else if(pid == 0) {
      if(execvp(args[0], args) < 0) {
        printf("%s: command not found\n", args[0]);
        exit(1);
      }
    } else {
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}