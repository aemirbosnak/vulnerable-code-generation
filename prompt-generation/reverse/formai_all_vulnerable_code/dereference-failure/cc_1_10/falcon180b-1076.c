//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;

    char *copy = strdup(string);
    char *word = strtok(copy, DELIM);

    while (word!= NULL) {
        words++;
        bufsize += strlen(word) + 1;
        word = strtok(NULL, DELIM);
    }

    tokens = malloc(sizeof(char *) * (words + 1));
    if (tokens == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(1);
    }

    token = strtok(copy, DELIM);
    int i = 0;
    while (token!= NULL) {
        tokens[i] = token;
        token = strtok(NULL, DELIM);
        i++;
    }
    tokens[words] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    if ((pid = vfork()) == -1) {
        fprintf(stderr, "Error: fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        return pid;
    } else {
        int status;
        waitpid(pid, &status, 0);
        return pid;
    }
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;
    pid_t pid;

    printf("Ken Thompson's Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        tokens = split_string(input);

        if (argc == 1) {
            pid = fork();
            if (pid == 0) {
                execlp(tokens[0], tokens[0], NULL);
            } else {
                waitpid(pid, NULL, 0);
            }
        } else if (strcmp(tokens[0], "exit") == 0) {
            break;
        } else {
            fprintf(stderr, "Error: invalid command.\n");
        }
    }

    return 0;
}