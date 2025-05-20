//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT 1024

int main()
{
    char input[MAX_INPUT];
    char *args[50];
    int i, status;

    while(1) {
        printf(">> ");
        fgets(input, MAX_INPUT, stdin);

        input[strlen(input)-1] = '\0';

        if(strcmp(input, "exit") == 0) {
            exit(0);
        }

        char *token = strtok(input, " ");
        i = 0;
        while(token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        pid_t pid = fork();

        if(pid < 0) {
            perror("fork error");
            exit(-1);
        }
        else if(pid == 0) {
            execvp(args[0], args);
            printf("Command not found\n");
            exit(-1);
        }
        else {
            waitpid(-1, &status, 0);
        }

    }

    return 0;
}