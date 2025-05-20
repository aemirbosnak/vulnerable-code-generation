//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGUMENTS 10

int main()
{
  char* command;
  char* arguments[MAX_NUM_ARGUMENTS];
  char* path = "/bin/";
  char fullCommand[MAX_COMMAND_LENGTH];
  int commandIndex, argumentIndex, background, status, i;

  while (1)
  {
    printf("\nenter a command: ");
    fgets(fullCommand, MAX_COMMAND_LENGTH, stdin);
    fullCommand[strlen(fullCommand) - 1] = '\0'; // Remove newline character

    if (strcmp(fullCommand, "exit") == 0)
      exit(0);

    background = 0;

    // Split command into the command itself and its arguments
    command = strtok(fullCommand, " ");
    arguments[0] = command;

    for (argumentIndex = 1; argumentIndex < MAX_NUM_ARGUMENTS; argumentIndex++)
    {
      arguments[argumentIndex] = strtok(NULL, " ");
      if (arguments[argumentIndex] == NULL)
        break;
      if (strcmp(arguments[argumentIndex], "&") == 0)
      {
        background = 1;
        arguments[argumentIndex] = NULL;
      }
    }

    // If the command contains a slash (/) character, it's already a full path
    if (strchr(command, '/') != NULL)
    {
      path = "";
    }

    // Search all directories in $PATH to find the command
    i = 0;
    while (1)
    {
      commandIndex = i == 0 ? sprintf(fullCommand, "%s/%s", path, command) : sprintf(fullCommand, "%s%s/%s", arguments[0], path, command);

      if (access(fullCommand, F_OK) == 0)
        break;

      if (i == 1)
      {
        printf("command not found\n");
        break;
      }

      path = getenv("PATH");
      if (path == NULL)
      {
        printf("path not found\n");
        break;
      }

      i++;
    }

    if (fork() == 0)
    {
      // Child process
      execv(fullCommand, arguments);
      exit(0);
    }

    // Wait for child process to finish before taking more input
    if (background == 0)
      waitpid(-1, &status, 0);
  }

  return 0;
}