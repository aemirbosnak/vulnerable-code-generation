//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

char input[MAX_INPUT_SIZE];
char *token[MAX_NUM_TOKENS];
int num_tokens;

void parse_input(char *line) {
    char *tokenizer = strtok(line, " ");
    num_tokens = 0;
    while (tokenizer != NULL) {
        token[num_tokens] = tokenizer;
        num_tokens++;
        tokenizer = strtok(NULL, " ");
    }
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        WIFEXITED(status) ? printf("Child process exited with status %d\n", WEXITSTATUS(status)) : printf("Child process terminated by signal %d\n", WTERMSIG(status));
    } else {
        if (execvp(token[0], token) < 0) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    char *prompt = "myshell> ";
    int c;

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';
        parse_input(input);
        execute_command(token);
    }

    return 0;
}