//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 10

void prompt() {
    printf("> ");
}

void parse_command(char* command, char** args) {
    int i = 0;
    char* token = strtok(command, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

void execute_command(char** args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[100];
    char* commands[MAX_COMMANDS];
    char* args[MAX_ARGS];
    
    while (1) {
        prompt();
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';
        
        int num_commands = 0;
        char* token = strtok(input, "|");
        while (token != NULL) {
            commands[num_commands++] = token;
            token = strtok(NULL, "|");
        }
        commands[num_commands] = NULL;
        
        int prev_pipe[2];
        for (int i = 0; i < num_commands; i++) {
            pipe(prev_pipe);
            
            char* command = commands[i];
            parse_command(command, args);
            
            pid_t pid = fork();
            if (pid < 0) {
                perror("fork failed");
            } else if (pid == 0) {
                if (i != 0) {
                    close(STDIN_FILENO);
                    dup2(prev_pipe[0], STDIN_FILENO);
                    close(prev_pipe[0]);
                }
                if (i != num_commands - 1) {
                    close(STDOUT_FILENO);
                    dup2(prev_pipe[1], STDOUT_FILENO);
                    close(prev_pipe[1]);
                }
                
                execvp(args[0], args);
                perror("execvp failed");
                exit(EXIT_FAILURE);
            } else {
                close(prev_pipe[0]);
                close(prev_pipe[1]);
                int status;
                waitpid(pid, &status, 0);
            }
        }
    }
    
    return 0;
}