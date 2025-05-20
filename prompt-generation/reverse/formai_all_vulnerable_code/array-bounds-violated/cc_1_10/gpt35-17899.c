//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_LENGTH 1024 // Maximum length of command string
#define MAX_ARGS 64     // Maximum number of arguments
#define PROMPT "$ "     // Default prompt

int main(){

    char input[MAX_LENGTH]; // Command input buffer
    char *args[MAX_ARGS];   // Command argument array
    char *token;            // Tokenizer for input string
    int status;             // Status returned from child processes
    pid_t pid;              // Process ID for child processes
    int argCount;           // Count of arguments in input string

    while(1){

        printf("%s", PROMPT);   // Print shell prompt
        fgets(input, MAX_LENGTH, stdin); // Get input from user

        // Remove trailing newline character
        if(input[strlen(input)-1] == '\n'){
            input[strlen(input)-1] = '\0';
        }

        // Parse input string into arguments
        token = strtok(input, " ");
        argCount = 0;
        while(token != NULL){
            args[argCount] = token;
            argCount++;
            token = strtok(NULL, " ");
        }
        args[argCount] = NULL;

        // Execute command
        pid = fork();
        if(pid == 0){ // Child process
            status = execvp(args[0], args);
            if(status == -1){
                printf("Error executing command: %s\n", args[0]);
                exit(EXIT_FAILURE);
            }
        }
        else if(pid > 0){ // Parent process
            waitpid(pid, &status, 0);
        }
        else{ // Fork error
            printf("Error creating child process\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}