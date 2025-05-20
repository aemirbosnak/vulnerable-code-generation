//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0

char **split_string(char *string);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    char **args = split_string(input);
    int status = execute_command(args);
    if (status == 0) {
        printf("Command executed successfully.\n");
    } else {
        printf("Command execution failed.\n");
    }
    return 0;
}

char **split_string(char *string) {
    int length = strlen(string);
    int count = 0;
    char **tokens = malloc(sizeof(char *) * (length + 1));
    char *token = strtok(string, DELIM);
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **args) {
    int pid = fork();
    if (pid == -1) {
        printf("Fork failed.\n");
        return FALSE;
    } else if (pid == 0) {
        execvp(args[0], args);
        printf("Command not found.\n");
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
        return TRUE;
    }
}