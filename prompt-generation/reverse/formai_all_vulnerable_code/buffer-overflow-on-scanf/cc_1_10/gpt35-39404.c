//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 // Maximum command length allowed
#define MAX_NUM_ARGUMENTS 10 // Maximum number of arguments (including command itself) allowed

int main()
{
  char *command; // String to hold the command typed by user
  char *arguments[MAX_NUM_ARGUMENTS]; // Array to hold the arguments parsed from command
  char *current_directory; // String to hold the current working directory
  int i; // Iterate over arguments when parsing command
  pid_t child_pid; // Child pid when forking
  int status; // Status of child upon exiting

  // Keep running the shell until user types 'exit'
  while (1)
  {
    // Display prompt with current working directory and wait for user input
    current_directory = getcwd(NULL, 0);
    printf("%s> ", current_directory);
    free(current_directory);
    command = (char *) calloc(MAX_COMMAND_LENGTH, sizeof(char));
    scanf("%[^\n]", command);
    getchar(); // Eat trailing \n

    // If user typed 'exit', break the loop and exit the shell
    if (strcmp(command, "exit") == 0)
    {
      break;
    }

    // Parse command and arguments
    i = 0;
    arguments[i] = strtok(command, " ");
    while (arguments[i] != NULL)
    {
      i++;
      arguments[i] = strtok(NULL, " ");
    }

    // Fork child and execute command
    child_pid = fork();
    if (child_pid == -1)
    {
      printf("Error: failed to fork child.\n");
    }
    else if (child_pid == 0)
    {
      execvp(arguments[0], arguments);
      printf("Error: failed to execute command '%s'.\n", arguments[0]);
      exit(1);
    }
    else
    {
      waitpid(child_pid, &status, 0);
    }

    // Clean up command and arguments for next iteration
    free(command);
    for (i = 0; i < MAX_NUM_ARGUMENTS; i++)
    {
      arguments[i] = NULL;
    }
  }

  return 0; // Exit normally
}