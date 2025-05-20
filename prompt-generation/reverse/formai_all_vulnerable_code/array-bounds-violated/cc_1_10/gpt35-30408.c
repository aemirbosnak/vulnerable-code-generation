//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 80
#define MAXARGS 20

void execute(char *args[], bool background) {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Forking error\n");
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("Exec failed\n");
        exit(EXIT_FAILURE);
    } else {
        if (!background) {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

int main() {
    char line[MAXLINE];
    char *args[MAXARGS];
    int argc;
    bool background;
    
    while (true) {
        printf("myshell > ");
        fgets(line, MAXLINE, stdin);
        line[strlen(line) - 1] = '\0';
        argc = 0;
        background = false;
        char *token = strtok(line, " ");
        while (token != NULL) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }
        if (argc == 0) continue;
        if (strcmp(args[argc - 1], "&") == 0) {
            background = true;
            args[--argc] = NULL;
        } else {
            args[argc] = NULL;            
        }
        execute(args, background);
    }
    
    return 0;
}