//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define DELIMITER " "

// Function to split a string by a delimiter
char **split(char *str, char delimiter) {
    char **tokens = NULL;
    int count = 0;
    char *token;
    char *context = str;

    while ((token = strtok(context, delimiter))) {
        tokens = realloc(tokens, sizeof(char *) * (++count));
        tokens[count - 1] = token;
        context = NULL;
    }

    return tokens;
}

// Function to execute a command
void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

// Function to print the process list
void print_process_list() {
    FILE *fp;
    char line[1024];
    char *token;
    pid_t pid;
    int status;

    fp = fopen("/proc/self/status", "r");

    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, DELIMITER);
        pid = atoi(token);
        execute_command(split(line, DELIMITER));
    }

    fclose(fp);
}

// Function to handle SIGINT
void handle_sigint(int signum) {
    printf("\nExiting...\n");
    exit(1);
}

int main() {
    signal(SIGINT, handle_sigint);

    print_process_list();

    return 0;
}