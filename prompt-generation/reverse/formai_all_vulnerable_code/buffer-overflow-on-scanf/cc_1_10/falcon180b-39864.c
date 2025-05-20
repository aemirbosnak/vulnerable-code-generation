//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string, int *count);
pid_t fork(void);
int execute_command(char **args);
void print_prompt(char *username);

int main(void) {
    char username[32];
    printf("Enter your username: ");
    scanf("%s", username);

    while (1) {
        print_prompt(username);
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char **args = split_string(input, NULL);
        if (args[0] == NULL)
            continue;

        pid_t pid = fork();
        if (pid == -1) {
            printf("Error forking process\n");
            continue;
        } else if (pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *string, int *count) {
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    int i = 0;
    char *token = strtok(string, DELIM);
    while (token!= NULL && i < MAX_ARGUMENTS) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, DELIM);
    }
    *count = i;
    return tokens;
}

pid_t fork(void) {
    return fork();
}

int execute_command(char **args) {
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking process\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error executing command\n");
            return 1;
        }
    } else {
        waitpid(pid, NULL, 0);
    }
    return 0;
}

void print_prompt(char *username) {
    printf("%s@shell: ", username);
}