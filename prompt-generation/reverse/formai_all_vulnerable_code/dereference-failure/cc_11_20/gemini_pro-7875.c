//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024

int main()
{
  char line[MAX_LINE];
  char *args[MAX_LINE / 2 + 1];
  int status;

  while (1)
  {
    // Prompt the user for a command
    printf("shell> ");
    fflush(stdout);

    // Get the command line from the user
    if (fgets(line, MAX_LINE, stdin) == NULL)
    {
      perror("fgets");
      return 1;
    }

    // Parse the command line into arguments
    int argc = 0;
    char *token = strtok(line, " \t\n");
    while (token != NULL)
    {
      args[argc++] = token;
      token = strtok(NULL, " \t\n");
    }
    args[argc] = NULL;

    // Built-in commands
    if (strcmp(args[0], "exit") == 0)
    {
      return 0;
    }
    else if (strcmp(args[0], "cd") == 0)
    {
      if (argc > 1)
      {
        if (chdir(args[1]) != 0)
        {
          perror("chdir");
        }
      }
      else
      {
        printf("Usage: cd <directory>\n");
      }
    }

    // Fork a child process to execute the command
    pid_t pid = fork();
    if (pid == -1)
    {
      perror("fork");
      return 1;
    }
    else if (pid == 0)
    {
      // Child process
      if (execvp(args[0], args) == -1)
      {
        perror("execvp");
        return 1;
      }
    }
    else
    {
      // Parent process
      wait(&status);
    }
  }

  return 0;
}