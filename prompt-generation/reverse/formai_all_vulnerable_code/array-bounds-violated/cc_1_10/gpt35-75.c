//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* Maximum length of command */
#define HISTORY_SIZE 10 /* Maximum number of commands in history */

char* history[HISTORY_SIZE];
int history_count = 0;

/* Display the command history */
void show_history() {
    printf("Command History:\n");
    for(int i=0; i<history_count; i++) {
        printf("%d: %s", i+1, history[i]);
    }
}

/* Execute a command */
void execute_command(char **args, int background) {
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        /* Child process */
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        /* Error forking */
        perror("fork");
    } else {
        /* Parent process */
        if (background == 0) {
            /* Wait for child process to finish */
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
}

/* Parse and execute a command */
void parse_command(char *command) {
    /* Tokenize the command */
    char *args[MAX_LINE/2+1]; /* Maximum of 40 arguments */
    int arg_count = 0;
    char *token = strtok(command, " ");
    while (token != NULL) {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " ");
    }
    if (arg_count == 0) {
        /* Empty command */
        return;
    }
    /* Check for background execution */
    int background = 0;
    if (strcmp(args[arg_count-1], "&") == 0) {
        background = 1;
        args[arg_count-1] = NULL;
        arg_count--;
    }
    /* Check for built-in commands */
    if (strcmp(args[0], "exit") == 0) {
        exit(0); /* Exit shell */
    } else if (strcmp(args[0], "history") == 0) {
        show_history(); /* Display command history */
    } else {
        /* Execute command */
        execute_command(args, background);
        /* Add command to history */
        if (history_count < HISTORY_SIZE) {
            history[history_count] = strdup(command);
            history_count++;
        } else {
            /* Shift commands in history */
            for(int i=0; i<HISTORY_SIZE-1; i++) {
                free(history[i]);
                history[i] = strdup(history[i+1]);
            }
            free(history[HISTORY_SIZE-1]);
            history[HISTORY_SIZE-1] = strdup(command);
        }
    }
}

int main(void) {
    char command[MAX_LINE];
    while (1) {
        /* Display prompt */
        printf("shell> ");
        fflush(stdout);
        /* Read command */
        fgets(command, MAX_LINE, stdin);
        command[strlen(command)-1] = '\0'; /* Remove newline character */
        /* Exit on EOF (Ctrl+D) */
        if (feof(stdin)) {
            printf("\n");
            exit(0);
        }
        /* Execute command */
        parse_command(command);
    }
    return 0;
}