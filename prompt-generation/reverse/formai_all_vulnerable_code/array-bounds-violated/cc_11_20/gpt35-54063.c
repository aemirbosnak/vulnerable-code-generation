//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define TRUE 1
#define FALSE 0

int main(void) {
    char *args[MAX_LINE/2+1];   
    char userInput[MAX_LINE];
    int should_run = TRUE;
    int bg = FALSE;
    int status;

    while (should_run) {
        fflush(stdout);
        printf("osh> ");
        fflush(stdout);

        fgets(userInput, MAX_LINE, stdin);
        userInput[strlen(userInput)-1] = '\0';

        if (strcmp(userInput, "exit") == 0) {
            should_run = FALSE;
            continue;
        }

        if (userInput[strlen(userInput)-1] == '&') {
            bg = TRUE;
            userInput[strlen(userInput)-1] = '\0';
        }

        int i = 0;
        char *token = strtok(userInput, " ");
        while(token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        if (bg == TRUE) {
            int pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
                fprintf(stderr, "Unknown command: %s\n", args[0]);
                exit(1);
            } else if (pid < 0) {
                fprintf(stderr, "Failed to fork\n");
                exit(1);
            }
        } else {
            int pid = fork();
            if (pid == 0) {
                int ret = execvp(args[0], args);
                if (ret == -1) {
                    fprintf(stderr, "Unknown command: %s\n", args[0]);
                    exit(1);
                }
            } else if (pid < 0) {
                fprintf(stderr, "Failed to fork\n");
                exit(1);
            } else {
                waitpid(pid, &status, 0);
            }
        }
        bg = FALSE;
    }

    printf("Goodbye!\n");
    return 0;
}