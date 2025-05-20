//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char *line, *argv[100];
    int argc, status;
    while (1) {
        printf("~$: ");
        line = NULL;
        size_t len = 0;
        if (getline(&line, &len, stdin) == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }
        
        if (strlen(line) == 0)
            continue;
        
        argc = 0;
        char *token = strtok(line, " \n");
        while (token != NULL) {
            argv[argc++] = token;
            token = strtok(NULL, " \n");
        }
        argv[argc] = NULL;
        
        if (strcmp(argv[0], "exit") == 0) {
            exit(EXIT_SUCCESS);
        }
        
        pid_t pid = fork();
        if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else if (pid > 0) {
            wait(&status);
            if (WIFEXITED(status)) {
                printf("Process exited with status %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Process terminated by signal %d\n", WTERMSIG(status));
            }
        } else {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        
        free(line);
    }
    
    return 0;
}