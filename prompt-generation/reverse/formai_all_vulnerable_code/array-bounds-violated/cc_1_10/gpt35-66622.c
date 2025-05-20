//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void) {
  char *args[MAX_LINE / 2 + 1]; /* command line arguments */
  int should_run = 1; /* flag to determine when to exit program */
  int background = 0; /* flag for running process in the background */
  pid_t pid; /* process id */
  int status; /* wait status of child process */
  
  while (should_run) {
    printf("osh> ");
    fflush(stdout);
    char input[MAX_LINE];
    fgets(input, MAX_LINE, stdin);
    input[strlen(input)-1] = '\0'; // remove newline character
    
    // tokenize input into arguments
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
      args[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    args[i] = NULL; // mark end of argument list
    
    // check for background flag
    if (strcmp(args[i-1], "&") == 0) {
      background = 1;
      args[i-1] = NULL;
    }
    
    // exit command
    if (strcmp(args[0], "exit") == 0) {
      should_run = 0;
      continue;
    }
    
    // fork child process
    pid = fork();
    if (pid < 0) {
      fprintf(stderr, "Fork failed");
      return 1;
    }
    
    // child process
    else if (pid == 0) {
      if (execvp(args[0], args) == -1) {
        fprintf(stderr, "Invalid command\n");
      }
      exit(0);
    }
    
    // parent process
    else {
      if (background == 0) {
        waitpid(pid, &status, 0);
      }
      else {
        printf("Process %d running in background\n", pid);
      }
    }
  }
  
  return 0;
}