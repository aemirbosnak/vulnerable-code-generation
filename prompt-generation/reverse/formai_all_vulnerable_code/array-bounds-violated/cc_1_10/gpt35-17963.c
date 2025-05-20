//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_LINE 80 //maximum length of command
#define MAX_ARGS 20 //maximum amount of arguments in a command

int main(void) {
    char *args[MAX_ARGS]; //array for storing arguments
    char line[MAX_LINE]; //string for storing command line
    int status; //status of child process
    pid_t pid; //process ID of child process
    
    while (1) { //infinite loop until exit or nullptr is entered
        printf(">> "); //prompt
        fgets(line, MAX_LINE, stdin); //get input from user
        line[strlen(line) - 1] = '\0'; //remove newline character
        
        if (strcmp(line, "exit") == 0 || line == NULL) { //exit program if "exit" or nullptr is entered
            break; //break out of infinite loop
        }
        
        char *token = strtok(line, " "); //tokenize input by space
        int i = 0; //initialize argument index
        
        while (token != NULL) { //loop through each token
            args[i] = token; //add token to array
            i++; //increment index
            token = strtok(NULL, " "); //get next token
        }
        
        args[i] = NULL; //add nullptr to end of array
        
        pid = fork(); //create child process
        
        if (pid < 0) { //if error occurred
            fprintf(stderr, "Fork failed");
            exit(1);
        }
        else if (pid == 0) { //if child process
            if (execvp(args[0], args) == -1) { //execute command
                fprintf(stderr, "Execvp error\n");
                exit(1);
            }
        }
        else { //if parent process
            waitpid(pid, &status, 0); //wait for child process to complete
        }
    }
    
    return 0;
}