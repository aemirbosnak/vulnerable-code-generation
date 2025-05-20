//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

/* Secure C Basic Unix-like Shell */
int main(int argc, char* argv[]) {
    char line[MAX_INPUT_SIZE];            
    char* tokens[MAX_NUM_TOKENS];          
    char* pipeCmds[MAX_NUM_TOKENS];        
    char* backgroundCmds[MAX_NUM_TOKENS]; 
    pid_t pid;                             
    int status;
    int i, j, k;
    int numTokens, numPipes, numBackgroundCmds;

    while (1) {         
        /* Prompt for input */                  
        printf(">> ");  
        fgets(line, MAX_INPUT_SIZE, stdin);
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        /* Tokenize input by spaces */  
        numTokens = 0;                                   
        char* token = strtok(line, " ");                  
        while (token != NULL) {                           
            tokens[numTokens] = token;                    
            numTokens++;                                  
            token = strtok(NULL, " ");                     
        }
        tokens[numTokens] = NULL;                         

        /* Check for pipe and background commands */
        numPipes = 0;
        numBackgroundCmds = 0;
        for (i = 0; i < numTokens; i++) {
            if (strcmp(tokens[i], "|") == 0) {                    
                numPipes++;                                         
                pipeCmds[numPipes-1] = NULL;                        
            }
            else if (strcmp(tokens[i], "&") == 0) {                
                numBackgroundCmds++;                                
                backgroundCmds[numBackgroundCmds-1] = NULL;          
            }
            else {
                if (numPipes > 0) {                                  
                    pipeCmds[numPipes-1] = tokens[i];
                }
                else if (numBackgroundCmds > 0) {                     
                    backgroundCmds[numBackgroundCmds-1] = tokens[i];
                }
            }
        }

        /* Execute commands */
        int fd[2];                                
        int input = 0;                             
        for (i = 0; i <= numPipes; i++) {           
            if (i == numPipes) {                   
                if (numBackgroundCmds > 0) {
                    pid = fork();                     
                    if (pid == 0) {
                        execvp(backgroundCmds[0], backgroundCmds);
                    }
                    else if (pid < 0) {
                        perror("Fork failed");
                    }
                }
                else {
                    pid = fork();                     
                    if (pid == 0) {
                        execvp(tokens[0], tokens);
                    }
                    else if (pid < 0) {
                        perror("Fork failed");
                    }
                    else {
                        waitpid(pid, &status, 0);     
                    }
                }
            }
            else {
                pipe(fd);                          
                pid = fork();                       
                if (pid == 0) {
                    dup2(input, 0);                
                    if (i != numPipes) {
                        dup2(fd[1], 1);            
                    }
                    close(fd[0]);                  
                    /* Execute pipe command */
                    execvp(pipeCmds[i], pipeCmds);
                }
                else if (pid < 0) {
                    perror("Fork failed");
                }
                else {
                    waitpid(pid, &status, 0);       
                    close(fd[1]);                  
                    input = fd[0];                  
                }
            }
        }
    }
    return 0;
}