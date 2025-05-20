//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#define MAX_INPUT 1024
#define MAX_TOKEN 64
#define MAX_CMD_ARG 32
#define MAX_CMD_LINE 256
#define DELIM " \t\r\n\a"
int main(int argc, char *argv[]) {
    char input[MAX_CMD_LINE], token[MAX_TOKEN];
    char **args, *ptr;
    pid_t pid;
    int stat_loc;
    int i = 0;
    int input_length = 0;
    char file_path[MAX_CMD_LINE];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    while (1) {
        printf("\033[1;33m%s> ", "MyShell");
        fgets(input, MAX_CMD_LINE, stdin);
        input[strlen(input) - 1] = '\0';
        input_length = strlen(input);
        
        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        args = (char **)calloc(MAX_CMD_ARG, sizeof(char *));
        char *tokenized_input[MAX_CMD_ARG];
        int token_count = 0;
        
        ptr = strtok(input, DELIM);
        while (ptr != NULL) {
            tokenized_input[token_count++] = strdup(ptr);
            ptr = strtok(NULL, DELIM);
        }
        
        for (i = 0; i < token_count; i++) {
            args[i] = tokenized_input[i];
        }
        args[i] = NULL;
        
        if (strcmp(args[0], "cd") == 0) {
            if (chdir(args[1]) != 0) {
                perror("Error");
            }
            continue;
        }
        
        if ((pid = fork()) < 0) {
            perror("Error: Fork Failed");
            continue;
        }
        
        if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("Error: Execution Failed");
                exit(1);
            }
        } else {
            wait(&stat_loc);
        }
        
        for (i = 0; i < token_count; i++) {
            free(tokenized_input[i]);
        }
        free(args);
        
        bzero(input, MAX_CMD_LINE);
    }
    
    return 0;
}