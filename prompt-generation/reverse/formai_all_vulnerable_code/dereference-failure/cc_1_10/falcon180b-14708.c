//Falcon-180B DATASET v1.0 Category: System administration ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *input);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_command(input);
        int status = execute_command(args);

        for(int i=0; args[i]!=NULL; i++) {
            free(args[i]);
        }
        free(args);

        if(status == 1) {
            printf("Child process terminated abnormally.\n");
        }
    }

    return 0;
}

char **split_command(char *input) {
    char *token = strtok(input, DELIM);
    int count = 0;
    char **args = (char **)malloc(sizeof(char *) * (MAX_COMMAND_LENGTH/2));

    while(token!= NULL) {
        args[count] = (char *)malloc(sizeof(char) * (strlen(token)+1));
        strcpy(args[count], token);
        count++;
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if(pid == -1) {
        perror("fork");
        return 1;
    } else if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}