//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0

char **split(char *str, char delimiter);
int execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return EXIT_SUCCESS;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split(input, DELIM);
    int status = execute_command(args);

    if (status == 1) {
        printf("Error: Command not found\n");
    }
}

char **split(char *str, char delimiter) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, delimiter);
    }
    tokens[position] = NULL;
    return tokens;
}

int execute_command(char **args) {
    if (args[0] == NULL) {
        return FALSE;
    }

    if (strcmp(args[0], "exit") == 0) {
        return TRUE;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1]!= NULL) {
            if (chdir(args[1])!= 0) {
                perror("Error");
            }
        } else {
            printf("Usage: cd [directory]\n");
        }
        return TRUE;
    } else if (strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!= NULL) {
            printf("%s\n", cwd);
        } else {
            perror("Error");
        }
        return TRUE;
    } else {
        printf("Error: Command not found\n");
        return FALSE;
    }
}