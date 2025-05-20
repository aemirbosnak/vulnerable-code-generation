//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_LENGTH 1024

int main() {
  char buffer[BUFFER_LENGTH];
  char *args[64];
  char *token, *ptr;
  int i, status, ampersand;
  pid_t pid;

  while (1) {
    printf("myshell> ");
    fgets(buffer, BUFFER_LENGTH, stdin);
    buffer[strlen(buffer) - 1] = '\0';

    if (strcmp(buffer, "exit") == 0) {
      printf("Exiting myshell...\n");
      break;
    }

    i = 0;
    token = strtok_r(buffer, " ", &ptr);

    while (token != NULL) {
      args[i++] = token;
      token = strtok_r(NULL, " ", &ptr);
    }

    args[i] = NULL;

    if (i == 0) {
      continue;
    }

    ampersand = 0;

    if (strcmp(args[i - 1], "&") == 0) {
      args[i - 1] = NULL;
      ampersand = 1;
    }

    if ((pid = fork()) < 0) {
      printf("Fork error\n");
      continue;
    } else if (pid == 0) {
      if (execvp(args[0], args) < 0) {
        printf("Command not found\n");
      }

      exit(0);
    }

    if (ampersand == 0) {
      while (wait(&status) != pid)
        ;
    }
  }

  return 0;
}