//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 128

char* get_line(void);
int parse_cmd(char* cmd, char* args[], int* num_args);
int execute_cmd(char* cmd, char* args[], int num_args);
void print_prompt(void);

int main(void) {
    char* cmd;
    char* args[MAX_ARGS];
    int num_args;

    while (1) {
        print_prompt();
        cmd = get_line();
        if (cmd == NULL) {
            break;
        }
        if (parse_cmd(cmd, args, &num_args) != 0) {
            continue;
        }
        execute_cmd(cmd, args, num_args);
    }

    return 0;
}

char* get_line(void) {
    char* line = malloc(MAX_CMD_LEN * sizeof(char));
    if (line == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    if (fgets(line, MAX_CMD_LEN, stdin) == NULL) {
        free(line);
        return NULL;
    }
    line[strcspn(line, "\n")] = '\0';
    return line;
}

int parse_cmd(char* cmd, char* args[], int* num_args) {
    char* token;
    int i = 0;

    token = strtok(cmd, " ");
    while (token != NULL) {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    *num_args = i;
    return 0;
}

int execute_cmd(char* cmd, char* args[], int num_args) {
    pid_t pid;
    int status;

    if (num_args == 0) {
        return 0;
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(cmd, args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    waitpid(pid, &status, 0);
    return 0;
}

void print_prompt(void) {
    printf("> ");
    fflush(stdout);
}