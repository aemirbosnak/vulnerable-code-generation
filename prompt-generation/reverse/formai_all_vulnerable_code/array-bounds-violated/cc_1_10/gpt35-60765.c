//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10 //Maximum number of commands possible in a Simple Command
#define MAX_ARGUMENTS 10 //Maximum number of arguments possible in a Simple Command

void parse_commands(char* input, char** commands);
int parse_simple_command(char* command, char** arguments);
void execute_commands(char** commands);

int main(int argc, char** argv) {

  char input[1024];
  char* commands[MAX_COMMANDS];

  while(1) {
    printf(">> ");
    fgets(input, sizeof(input), stdin);
    
    //Remove trailing newline character from input
    input[strlen(input)-1] = '\0';
    
    //Skip empty inputs
    if(strcmp(input, "") == 0) {
      continue;
    }
    
    //Parse commands and execute them
    parse_commands(input, commands);
    execute_commands(commands);
  }

  return 0;
}

void parse_commands(char* input, char** commands) {
  int count = 0;
  char* token = strtok(input, "|");
  
  //Split input by delimiter '|'
  while(token != NULL) {

    //Remove leading/trailing whitespace from command
    int i = 0;
    while(token[i] == ' ') {
      i++;
    }
    char* command = token + i;

    i = strlen(command) - 1;
    while(command[i] == ' ') {
      command[i] = '\0';
      i--;
    }

    commands[count++] = command;

    //Get next token
    token = strtok(NULL, "|");
  }

  //Set the last command to NULL
  commands[count] = NULL;
}

int parse_simple_command(char* command, char** arguments) {
  int count = 0;
  char* token = strtok(command, " ");

  //Split command by delimiter ' '
  while(token != NULL) {
    arguments[count++] = token;

    //Get next token
    token = strtok(NULL, " ");
  }

  //Set the last argument to NULL
  arguments[count] = NULL;

  return count;
}

void execute_commands(char** commands) {
  int pipefd[2];
  int input_fd = 0;

  for(int i = 0; commands[i] != NULL; i++) {
    char* arguments[MAX_ARGUMENTS];
    int argc = parse_simple_command(commands[i], arguments);

    //Create new pipe for each command except the last one
    if(commands[i+1] != NULL) {
      pipe(pipefd);
    }

    pid_t pid = fork();

    if(pid == 0) { //Child process
      
      if(commands[i+1] != NULL) {
        //Set stdout of child process to write end of pipe
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
      }

      if(input_fd != 0) {
        //Set stdin of child process to read end of previous pipe
        dup2(input_fd, STDIN_FILENO);
        close(input_fd);
      }

      //Execute command
      if(execvp(arguments[0], arguments) == -1) {
        printf("Error executing command\n");
        exit(EXIT_FAILURE);
      }
      exit(EXIT_SUCCESS);

    } else if(pid < 0) { //Error creating child process
      printf("Error creating child process\n");
      return;
    }

    if(commands[i+1] != NULL) {
      close(pipefd[1]);
      input_fd = pipefd[0];
    }

  }

  //Parent process: wait for child processes to finish
  for(int i = 0; commands[i] != NULL; i++) {
    wait(NULL);
  }
}