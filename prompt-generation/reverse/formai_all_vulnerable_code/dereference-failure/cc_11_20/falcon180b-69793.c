//Falcon-180B DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char *token;
    int background = 0;
    int num_arguments = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));

    while(1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        token = strtok(input_buffer, DELIM);

        if(strcmp(token, "exit") == 0) {
            break;
        } else if(strcmp(token, "bg") == 0) {
            background = 1;
            token = strtok(NULL, DELIM);
        } else if(strcmp(token, "fg") == 0) {
            background = 0;
            token = strtok(NULL, DELIM);
        }

        if(token == NULL) {
            continue;
        }

        arguments[num_arguments] = strdup(token);
        num_arguments++;

        if(background == 1) {
            if(num_arguments < 2) {
                printf("Not enough arguments for background process.\n");
                continue;
            }
            pid_t pid = fork();

            if(pid == 0) {
                execvp(arguments[0], arguments);
                perror("execvp");
                exit(1);
            } else if(pid < 0) {
                perror("fork");
            }
        } else {
            if(num_arguments < 1) {
                printf("Not enough arguments.\n");
                continue;
            }
            pid_t pid = fork();

            if(pid == 0) {
                execvp(arguments[0], arguments);
                perror("execvp");
                exit(1);
            } else if(pid < 0) {
                perror("fork");
            }

            wait(NULL);
        }

        num_arguments = 0;
    }

    for(int i = 0; i < num_arguments; i++) {
        free(arguments[i]);
    }
    free(arguments);

    return 0;
}