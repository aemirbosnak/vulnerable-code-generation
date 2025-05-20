//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define DELIM " \t\r\n\a"

char **split_string(char *string, char delimiter);
pid_t fork();
int execute_command(char **arguments);
void handle_signal(int signum);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;
    
    signal(SIGINT, handle_signal);
    
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        
        arguments = split_string(input, DELIM);
        
        if (arguments[0] == NULL)
            continue;
        
        pid = fork();
        
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            wait(NULL);
        }
    }
    
    return 0;
}

char **split_string(char *string, char delimiter) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(string, delimiter);
    
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, delimiter);
    }
    
    tokens[count - 1] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid;
    
    pid = fork();
    
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    
    return pid;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;
    
    if (arguments[0] == NULL)
        return 1;
    
    pid = fork();
    
    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    
    return 0;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\n");
    }
}