//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINE 80 /* Maximum line length */

int main(void) {

   char command[MAXLINE]; /* Stores the user's command */
   char *args[MAXLINE/2 + 1]; /* Stores the arguments given by the user */
   int should_run = 1; /* Boolean variable to determine when to exit the loop */

   while (should_run) {
      printf("unix-shell>"); /* Unix-like shell prompt */
      fflush(stdout); /* Flush buffer to ensure prompt appears */

      /* Read user's command */
      fgets(command, MAXLINE, stdin);
      /* Remove trailing newline character */
      if (command[strlen(command)-1] == '\n') {
         command[strlen(command)-1] = '\0';
      }

      /* Tokenize the command into arguments */
      int i=0;
      args[i] = strtok(command," "); /* First token */
      while (args[i] != NULL) {
         i++;
         args[i] = strtok(NULL," "); /* Subsequent tokens */
      }
      args[i] = NULL; /* Set last argument to NULL to terminate the list */

      if (args[i-1] != NULL && strcmp(args[i-1], "&") == 0) {
         /* Background process requested */
         pid_t pid = fork(); /* Create new process */
         if (pid == -1) {
            /* Error occurred */
            fprintf(stderr, "Error: Failed to create new process\n");
            exit(EXIT_FAILURE);
         } else if (pid == 0) {
            /* Child process */
            args[i-1] = NULL; /* Remove "&" argument */
            if (execvp(args[0], args) == -1) {
               /* Error occurred */
               fprintf(stderr, "Error: Failed to execute command\n");
               exit(EXIT_FAILURE);
            }
         } else {
            /* Parent process */
            printf("Running in background [PID %d]\n", pid);
         }
      } else {
         /* Foreground process requested */
         pid_t pid = fork(); /* Create new process */
         if (pid == -1) {
            /* Error occurred */
            fprintf(stderr, "Error: Failed to create new process\n");
            exit(EXIT_FAILURE);
         } else if (pid == 0) {
            /* Child process */
            if (execvp(args[0], args) == -1) {
               /* Error occurred */
               fprintf(stderr, "Error: Failed to execute command\n");
               exit(EXIT_FAILURE);
            }
         } else {
            /* Parent process */
            waitpid(pid, NULL, 0); /* Wait for child to complete */
         }
      }

      /* Check if user wants to exit */
      if (strcmp(args[0], "exit") == 0) {
         should_run = 0;
      }

   }

   return 0;
}