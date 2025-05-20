//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

#define BUFFERSIZE 256
#define ARG_MAX_NUM 16
#define ARG_BUFFERSIZE 64
#define PROMPT "ush>"

int main() {
    char *user_input;
    char **arguments;
    int num_arguments, should_run=1;
    char cwd[BUFFERSIZE];
    pid_t pid;
    int status;
    
    user_input = (char*) malloc(BUFFERSIZE * sizeof(char));
    if (!user_input) {
        perror("Error: unable to allocate memory for user input.\n");
        exit(EXIT_FAILURE);
    }
    
    arguments = (char**) malloc(ARG_MAX_NUM * sizeof(char*));
    if (!arguments) {
        perror("Error: unable to allocate memory for arguments.\n");
        exit(EXIT_FAILURE);
    }
    
    while(should_run) {
        getcwd(cwd, BUFFERSIZE);
        printf("%s%s ", cwd, PROMPT);
        fflush(stdout);
        
        if (!fgets(user_input, BUFFERSIZE, stdin))
            break; 
        
        num_arguments = 0;
        arguments[num_arguments] = strtok(user_input, " \n");
        while(arguments[num_arguments] != NULL) {
            num_arguments += 1;
            arguments[num_arguments] = strtok(NULL, " \n");
        }
        arguments[num_arguments] = NULL;
        
        if (arguments[0] == NULL)
            continue;
        
        if (strcmp(arguments[0], "exit") == 0) {
            should_run = 0;
            continue;
        }
        
        pid = fork();
        if (pid < 0) {
            perror("Error: unable to fork process.\n");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            if (execvp(arguments[0], arguments) < 0) {
                perror("Error: unable to execute command.\n");
                exit(EXIT_FAILURE);
            }
        }
        else {
            waitpid(pid, &status, WUNTRACED);
        }
    }
    
    free(user_input);
    free(arguments);
    return 0;
}