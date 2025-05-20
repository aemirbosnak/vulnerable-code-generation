//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
//This program simulates a Unix-like shell that accepts user commands and executes them.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 //Maximum length of a user command
#define MAX_ARGUMENTS 10 //Maximum number of arguments for a command
#define TRUE 1
#define FALSE 0

int main() {

    char command[MAX_COMMAND_LENGTH]; //Buffer for user command
    char *arguments[MAX_ARGUMENTS]; //Arguments for user command
    int num_arguments; //Number of arguments for user command
    int should_run = TRUE; //Boolean flag to determine if program should keep running
    pid_t pid; //Process ID of child process
    int status; //Status of child process

    while (should_run) {
        printf(">");
        fflush(stdout); //Flush stdout buffer to print prompt

        //Read user command
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        //Parse user command into arguments
        num_arguments = 0;
        arguments[num_arguments] = strtok(command, " ");
        while ((arguments[++num_arguments] = strtok(NULL, " ")) != NULL);

        //Execute user command in child process
        pid = fork();
        if (pid < 0) {
            printf("Error: fork() failed!\n");
            exit(1);
        }
        else if (pid == 0) {
            execvp(arguments[0], arguments);
            printf("Error: execvp() failed!\n"); //execvp() only returns if it fails
            exit(1);
        }
        else {
            waitpid(pid, &status, 0); //Wait for child process to finish
            if (WIFEXITED(status)) {
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status)) {
                printf("Child process terminated by signal %d\n", WTERMSIG(status));
            }
        }

        //Check if user wants to exit
        if (strcmp(arguments[0], "exit") == 0) {
            should_run = FALSE;
        }
    }

    return 0;
}