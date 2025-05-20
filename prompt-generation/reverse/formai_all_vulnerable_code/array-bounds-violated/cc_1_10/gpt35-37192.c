//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGUMENTS 10

int main()
{
  char *command;
  char *args[MAX_NUM_ARGUMENTS];
  char input_command[MAX_COMMAND_LENGTH];
  int is_exit = 0;
  int i;

  printf("************* WELCOME TO THE SHELL *************\n");
  printf("*************   Enter 'exit' to quit  *************\n");
  printf("\n");

  while (!is_exit)
  {
    printf(">> ");
    fgets(input_command, MAX_COMMAND_LENGTH, stdin);
    input_command[strlen(input_command) - 1] = '\0';

    i = 0;
    command = strtok(input_command, " ");

    while (command != NULL)
    {
      args[i] = strdup(command);
      i++;
      command = strtok(NULL, " ");
    }

    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0)
    {
      is_exit = 1;
    }
    else
    {
      pid_t pid = fork();

      if (pid == -1)
      {
        printf("Error: Unable to fork child process.\n");
      }
      else if (pid == 0)
      {
        execvp(args[0], args);
        printf("Error: Invalid command.\n");
        exit(1);
      }
      else
      {
        wait(NULL);
      }
    }

    // Free allocated memory for arguments
    for (i = 0; args[i] != NULL; i++)
    {
      free(args[i]);
    }
  }

  printf("*************  GOODBYE FROM THE SHELL! *************\n");

  return 0;
}