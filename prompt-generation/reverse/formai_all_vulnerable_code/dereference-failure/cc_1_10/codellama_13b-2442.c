//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
// A simple Unix-like shell program in C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT 80
#define MAX_COMMANDS 10

// Struct to store commands and arguments
typedef struct {
  char command[MAX_INPUT];
  char args[MAX_INPUT];
} command_t;

// Function to parse user input and store in a command struct
void parse_input(char *input, command_t *command) {
  // Split input into command and arguments
  char *token = strtok(input, " ");
  strcpy(command->command, token);
  token = strtok(NULL, " ");
  while (token != NULL) {
    strcat(command->args, token);
    token = strtok(NULL, " ");
  }
}

// Function to execute a command and its arguments
int execute_command(command_t *command) {
  // Fork a new process
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    return 1;
  }
  if (pid == 0) {
    // Child process
    execlp(command->command, command->command, command->args, NULL);
    perror("execlp");
    exit(1);
  } else {
    // Parent process
    wait(NULL);
  }
  return 0;
}

// Function to handle user input
int handle_input(char *input) {
  command_t command;
  parse_input(input, &command);
  return execute_command(&command);
}

// Function to display a prompt
void display_prompt() {
  printf("myshell> ");
}

// Main function
int main() {
  char input[MAX_INPUT];
  while (1) {
    display_prompt();
    fgets(input, MAX_INPUT, stdin);
    if (handle_input(input) != 0) {
      perror("handle_input");
      exit(1);
    }
  }
  return 0;
}