//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* Maximum length of a command */
#define MAX_HISTORY 10 /* Maximum number of commands stored in history */

int main(void)
{
    char *args[MAX_LINE/2 + 1]; /* Command line arguments */
    char history[MAX_HISTORY][MAX_LINE]; /* Array to store command history */
    int should_run = 1; /* Flag to determine when to exit program */
    int history_count = 0; /* Counter for history array */
    int i, j, k;

    while (should_run) {
        printf("osh> "); /* Print shell prompt */
        fflush(stdout);

        /* Read command from user */
        char input[MAX_LINE];
        fgets(input, sizeof(input), stdin);

        /* Remove trailing newline character */
        if (input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }

        if (strcmp(input, "\0") == 0) { /* Check for empty command */
            continue;
        }

        /* Add command to history array */
        if (history_count < MAX_HISTORY) {
            strcpy(history[history_count], input);
            history_count++;
        } else {
            for (i = 1; i < MAX_HISTORY; i++) {
                strcpy(history[i-1], history[i]);
            }
            strcpy(history[MAX_HISTORY-1], input);
        }

        /* Parse command line arguments */
        char *token = strtok(input, " ");
        i = 0;
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; /* Add terminating NULL */

        if (strcmp(args[0], "exit") == 0) { /* Check for exit command */
            should_run = 0;
            continue;
        }

        /* Check for history command */
        if (strcmp(args[0], "history") == 0) {
            for (j = 0; j < history_count; j++) {
                printf("%d. %s\n", j+1, history[j]);
            }
            continue;
        }

        /* Check for !! shortcut */
        if (strcmp(args[0], "!!") == 0) {
            if (history_count == 0) { /* Check if history is empty */
                printf("No commands in history\n");
                continue;
            }
            char *last_command = history[history_count-1];
            strcpy(input, last_command);
            /* Parse last command */
            char *token = strtok(input, " ");
            i = 0;
            while (token != NULL) {
                args[i] = token;
                i++;
                token = strtok(NULL, " ");
            }
            args[i] = NULL; /* Add terminating NULL */
        }

        /* Check for !n shortcut */
        if (args[0][0] == '!') {
            char *num_str = args[0]+1; /* Skip '!' */
            int num = atoi(num_str);
            if (num <= 0 || num > history_count) {
                printf("Invalid command number\n");
                continue;
            }
            char *history_command = history[num-1];
            strcpy(input, history_command);
            /* Parse history command */
            char *token = strtok(input, " ");
            i = 0;
            while (token != NULL) {
                args[i] = token;
                i++;
                token = strtok(NULL, " ");
            }
            args[i] = NULL; /* Add terminating NULL */
        }

        /* Fork child process */
        pid_t pid = fork();
        if (pid == 0) { /* Child process */
            if (execvp(args[0], args) == -1) {
                printf("Unknown command\n");
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {
            printf("Fork failed\n");
        } else { /* Parent process */
            /* Wait for child process to terminate */
            wait(NULL);
        }
    }

    return 0;
}