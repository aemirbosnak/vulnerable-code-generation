//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

/* Define constant for maximum input length */
#define MAX_INPUT_LENGTH 256

/* Define constant for maximum number of arguments */
#define MAX_ARGS 10

/* Define constant for maximum command length */
#define MAX_CMD_LENGTH 50

/* Define function to check if a character is a valid command character */
bool is_valid_char(char c) {
    return (isalnum(c) || c == '/');
}

/* Define function to check if command contains invalid characters */
bool contains_invalid_chars(char *cmd) {
    int i;
    for(i = 0; i < strlen(cmd); i++) {
        if(!is_valid_char(cmd[i])) {
            return true;
        }
    }
    return false;
}

/* Define function to split input into argument array */
void parse_input(char *input, char **argv) {
    int argc = 0;
    while(*input != '\0') {
        /* Skip any leading white space */
        while(isspace(*input)) {
            input++;
        }
        /* Break if end of input reached */
        if(*input == '\0') {
            break;
        }
        /* Start of an argument */
        argv[argc++] = input;
        /* Skip argument */
        while(*input != '\0' && !isspace(*input)) {
            input++;
        }
        /* Null terminate argument */
        if(*input != '\0') {
            *input++ = '\0';
        }
    }
    /* Null terminate argument array */
    argv[argc] = NULL;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char *argv[MAX_ARGS];
    char cmd[MAX_CMD_LENGTH];
    int status;
    pid_t pid;

    while(true) {
        printf("Paranoid-Shell> ");
        fflush(stdout);
        fgets(input, sizeof(input), stdin);
        /* Remove newline character at end of input */
        input[strlen(input) - 1] = '\0';
        /* Check for invalid characters in input */
        if(contains_invalid_chars(input)) {
            printf("Invalid input: command contains invalid characters\n");
            continue;
        }
        /* Parse input into argument array */
        parse_input(input, argv);
        /* Check if input is empty */
        if(!argv[0]) {
            continue;
        }
        /* Check if command is "exit" */
        if(strcmp(argv[0], "exit") == 0) {
            break;
        }
        /* Check if command is "rm" */
        if(strcmp(argv[0], "rm") == 0) {
            printf("Are you sure you want to delete %s? (yes/no): ", argv[1]);
            fflush(stdout);
            fgets(cmd, sizeof(cmd), stdin);
            /* Remove newline character at end of input */
            cmd[strlen(cmd) - 1] = '\0';
            if(strcmp(cmd, "yes") == 0) {
                printf("Deleting %s\n", argv[1]);
                /* Launch rm command as a child process */
                pid = fork();
                if(pid == 0) {
                    /* Child process */
                    execvp(argv[0], argv);
                    /* If execvp returns, an error occurred */
                    perror("execvp");
                    exit(EXIT_FAILURE);
                } else if(pid < 0) {
                    /* fork failed */
                    perror("fork");
                    exit(EXIT_FAILURE);
                } else {
                    /* Parent process */
                    /* Wait for child to complete */
                    do {
                        pid = waitpid(pid, &status, WUNTRACED);
                    } while(!WIFEXITED(status) && !WIFSIGNALED(status));
                }
            } else {
                printf("Aborting deletion of %s\n", argv[1]);
            }
        } else {
            /* Launch command as a child process */
            pid = fork();
            if(pid == 0) {
                /* Child process */
                execvp(argv[0], argv);
                /* If execvp returns, an error occurred */
                perror("execvp");
                exit(EXIT_FAILURE);
            } else if(pid < 0) {
                /* fork failed */
                perror("fork");
                exit(EXIT_FAILURE);
            } else {
                /* Parent process */
                /* Wait for child to complete */
                do {
                    pid = waitpid(pid, &status, WUNTRACED);
                } while(!WIFEXITED(status) && !WIFSIGNALED(status));
            }
        }
    }

    return 0;
}