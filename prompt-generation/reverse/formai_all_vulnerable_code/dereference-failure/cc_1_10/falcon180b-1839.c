//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command);
int execute_command(char **args);
void print_prompt(char *username);
void loop(char *username);

int main(int argc, char *argv[]) {
    char *username = argv[1];
    char input[MAX_COMMAND_LENGTH];

    print_prompt(username);
    loop(username);

    return 0;
}

void print_prompt(char *username) {
    printf("%s@unix-shell:~$ ", username);
}

void loop(char *username) {
    char input[MAX_COMMAND_LENGTH];

    while(1) {
        printf("%s@unix-shell:~$ ", username);
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **args = split_command(input);
        int status = execute_command(args);

        if(status == 1) {
            printf("%s@unix-shell:~$ ", username);
        }
    }
}

char **split_command(char *command) {
    char **args = (char **)malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token;

    token = strtok(command, DELIM);
    while(token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL) {
        return 1;
    }

    if(strcmp(args[0], "exit") == 0) {
        return 1;
    } else if(strcmp(args[0], "cd") == 0) {
        if(args[1]!= NULL) {
            if(chdir(args[1])!= 0) {
                perror("chdir");
            }
        } else {
            fprintf(stderr, "cd: Argument required.\n");
        }
    } else if(strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        if(getcwd(cwd, sizeof(cwd))!= NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd");
        }
    } else {
        pid = fork();

        if(pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else if(pid < 0) {
            fprintf(stderr, "fork: Error.\n");
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}