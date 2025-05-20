//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 1024 //Maximum length of command
#define MAX_ARGS 64 // Maximum number of arguments

int main(){
    char command[MAX_COMMAND_LEN];
    char *args[MAX_ARGS]; 

    printf("Welcome to UnicornShell!\n");
    printf("Type 'exit' to quit the shell.\n\n");

    while (1) { // Loop until the user decides to quit
        printf("UnicornShell:~$ "); // Prompt the user
        fgets(command, MAX_COMMAND_LEN, stdin); // Read the user input
        
        //Remove the newline character from the command string
        if (command[strlen(command)-1] == '\n'){
            command[strlen(command)-1] = '\0';
        }

        //Check if the user wants to exit the shell 
        if (strcmp(command, "exit") == 0) {
            printf("Goodbye! Thanks for using UnicornShell.\n");
            exit(0);
        }

        char *token;
        int i = 0;

        //Get the first token
        token = strtok(command, " ");

        //Walk through the other tokens
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }

        //Set the last element of the args array to null
        args[i] = NULL;

        pid_t pid;
        int status;

        //Create a child process to run the command
        if ((pid = fork()) < 0){
            printf("Error: Could not create child process!");
            exit(1);
        }
        
        if (pid == 0){ //Child process
            int ret = execvp(args[0], args);
            if (ret < 0){
               printf("Error: Could not execute command!"); 
            }
            exit(0);
        }else{ //Parent process
            waitpid(pid, &status, 0); //Wait for the child process to complete
        }
    }
    return 0; //Success!
}