//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_LEN 1024

// Function that handles the execution of input commands
void execute_cmd(char **argv)
{
     pid_t pid;
     int status;
     
     pid = fork();
     
     // If there is an error creating the child process
     if (pid < 0) {
         printf("Error: could not create child process\n");
         exit(1);
     }
     
     // If we are in the child process
     else if (pid == 0) {
         if (execvp(*argv, argv) < 0) {
             printf("Error: could not execute command\n");
             exit(1);
         }
     }
     
     // If we are in the parent process
     else {
         while (wait(&status) != pid);
     }
}

int main()
{
     char *args[MAX_LEN/2 + 1];
     char command[MAX_LEN];
     int should_run = 1;
     
     while (should_run) {
         
         // Get user input
         printf("osh> ");
         fflush(stdout);
         fgets(command, MAX_LEN, stdin);
         
         // Remove newline character at the end of the input
         if (command[strlen(command)-1] == '\n')
             command[strlen(command)-1] = '\0';
         
         // Parse user input
         char *token = strtok(command, " ");
         int i = 0;
         while (token) {
             args[i] = token;
             token = strtok(NULL, " ");
             i++;
         }
         args[i] = NULL;
         
         // Handle commands
         if (strcmp(args[0], "exit") == 0)
             should_run = 0;
         else if (strcmp(args[0], "cd") == 0) {
             char *dir = args[1];
             if (dir == NULL) {
                 printf("Error: missing argument\n");
             }
             else if (chdir(dir) < 0) {
                 printf("Error: could not change directory\n");
             }
         }
         else {
             execute_cmd(args);
         }
     }
     
     return 0;
}