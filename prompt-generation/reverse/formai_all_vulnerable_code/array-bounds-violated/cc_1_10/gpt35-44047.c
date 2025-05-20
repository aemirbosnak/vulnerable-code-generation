//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Function to split command into arguments */
int parse_command(char *command, char **args) {
    int i = 0;
    char *token = strtok(command, " ");
    
    /* Tokenize command into arguments */
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    
    args[i] = NULL;
    
    /* Return the number of arguments */
    return i;
}

/* Function to execute command */
void execute_command(char **args, int arg_count) {
    pid_t pid;
    int status;
    
    /* Fork a child process */
    pid = fork();
    
    if (pid == 0) {
        /* Child process */
        if (execvp(args[0], args) < 0) {
            printf("Error executing command!\n");
            exit(1);
        }
    } else if (pid < 0) {
        /* Fork error */
        printf("Error forking child process!\n");
        exit(1);
    } else {
        /* Parent process */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

/* Main function */
int main(void) {
    char command[100];
    char *args[10];
    int arg_count;
    
    printf("Welcome to my shell!\n");
    
    while (1) {
        /* Read in command from user */
        printf("> ");
        fgets(command, 100, stdin);
        command[strlen(command) - 1] = '\0';
        
        /* Parse command into arguments */
        arg_count = parse_command(command, args);
        
        /* Execute command */
        execute_command(args, arg_count);
    }
    
    return 0;
}