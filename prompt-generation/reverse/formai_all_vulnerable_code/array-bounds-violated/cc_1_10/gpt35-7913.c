//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

// split the input buffer into tokens
char** tokenizeInput(char* inputBuffer) {
    char** tokens = (char**)malloc(MAX_NUM_TOKENS*sizeof(char*));
    char* token = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
    int position = 0, tokenIndex = 0;
    
    while (inputBuffer[position] != '\0') {
        char currentChar = inputBuffer[position];
        if (currentChar == ' ' || currentChar == '\n' || currentChar == '\t') {
            token[tokenIndex] = '\0';
            if (tokenIndex != 0) {
                tokens[tokenIndex++] = token;
                token = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
                tokenIndex = 0;
            }   
        } else {
            token[tokenIndex++] = currentChar;
        }
        position++;
    }
    
    tokens[tokenIndex] = NULL;
    free(token);
    return tokens;
}

int main(int argc, char* argv[]) {
    char inputBuffer[MAX_INPUT_SIZE];
    int pid, status;
    
    while (1) {
        printf("my-shell> ");
        fgets(inputBuffer, MAX_INPUT_SIZE, stdin);
        
        // remove trailing newline character
        inputBuffer[strlen(inputBuffer)-1] = '\0';
        
        // tokenize the input buffer
        char** tokens = tokenizeInput(inputBuffer);
        
        // fork a new process to execute the command
        pid = fork();
        if (pid < 0) {
            printf("Error: Failed to create a new process.\n");
            return 1;
        } else if (pid == 0) {
            // child process
            execvp(tokens[0], tokens);
            printf("Error: Failed to execute the command.\n");
            exit(1);
        } else {
            // parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        
        free(tokens);
    }
    
    return 0;
}