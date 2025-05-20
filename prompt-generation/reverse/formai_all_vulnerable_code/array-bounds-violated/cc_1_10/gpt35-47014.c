//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    char *arg_list[MAX_ARGS]; // array to hold command and arguments
    int status;
    
    while(1) { // Shell loop
        printf("myshell > "); // prompt
        fgets(input, MAX_LEN, stdin); // get user input
        
        // remove new line character from input
        if(input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0'; 
        }
        
        // parse input to separate command and arguments
        char *token = strtok(input, " ");
        int i = 0;
        while(token != NULL && i < MAX_ARGS-1) {
            arg_list[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        arg_list[i] = NULL; // null terminate the argument list
        
        // exit shell if user enters "exit"
        if(strcmp(arg_list[0], "exit") == 0) {
            printf("Exiting shell...\n");
            exit(0);
        }
        
        pid_t pid = fork(); // create new process
        if(pid == 0) { // child process
            execvp(arg_list[0], arg_list); // execute command with arguments
            printf("Error: command %s not found\n", arg_list[0]); // execvp returns only if there is an error
            exit(1);
        } else if(pid > 0) { // parent process
            waitpid(pid, &status, 0); // wait for child to finish
        } else { // fork error
            printf("Error: fork failed\n");
            exit(1);
        }
    }
    return 0;
}