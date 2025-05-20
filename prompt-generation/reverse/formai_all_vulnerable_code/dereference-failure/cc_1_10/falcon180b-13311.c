//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(line, DELIM);

    while(token!= NULL) {
        tokens[position] = token;
        position++;

        if(position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

pid_t launch_shell(char **tokens) {
    pid_t pid;
    int status;

    if(tokens[0] == NULL)
        return -1;

    pid = fork();

    if(pid == -1) {
        perror("fork");
        return -1;
    } else if(pid == 0) {
        if(execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) &&!WIFSIGNALED(status));
    }

    return pid;
}

void loop(void) {
    char line[MAX_COMMAND_LENGTH];
    char **tokens;
    pid_t pid;

    printf("Linus Torvalds Shell\n");

    while(fgets(line, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        tokens = split_line(line);
        pid = launch_shell(tokens);

        if(pid!= -1) {
            waitpid(pid, NULL, 0);
        }
    }
}

int main(int argc, char *argv[]) {
    loop();
    return 0;
}