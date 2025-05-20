//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024 // buffer size for input

int main() {
    char buffer[BUFFER_SIZE]; // input buffer
    char *tokens[100]; // array of tokens from input
    int token_num; // number of tokens in array

    printf("Welcome to the YakYak Unix-like Shell!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("YakYak>> "); // prompt for input
        fgets(buffer, BUFFER_SIZE, stdin); // get input from user
        buffer[strlen(buffer) - 1] = '\0'; // remove new line character at end of input

        if(strcmp(buffer, "exit") == 0) { // check for exit command
            printf("Goodbye!\n");
            break;
        }

        char *token = strtok(buffer, " "); // tokenizing input
        token_num = 0;

        while(token != NULL) {
            tokens[token_num] = token;
            token_num++;
            token = strtok(NULL, " ");
        }

        tokens[token_num] = NULL; // set last token to NULL for execvp()

        pid_t pid = fork(); // fork process to execute command

        if (pid == -1) { // check for fork error
            perror("Error: fork()");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // child process code
            execvp(tokens[0], tokens); // execute command
            perror("Error: execvp()"); // if execvp returns, there was an error
            exit(EXIT_FAILURE);
        } else { // parent process code
            waitpid(pid, NULL, 0); // wait for child process to complete
        }
    }

    return 0;
}