//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_TOKEN 64
#define MAX_CMD 128

char line[MAX_LINE];
char token[MAX_TOKEN][MAX_CMD];
char *path = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";

pid_t pid;
int status;

void sigint_handler(int signo) {
    printf("\n");
    fflush(stdout);
    exit(0);
}

void parse_line(char *line) {
    char *tokenizer = strtok(line, " ");
    int i = 0;

    while (tokenizer != NULL) {
        strcpy(token[i], tokenizer);
        i++;
        tokenizer = strtok(NULL, " ");
    }
}

void execute_command() {
    int i;

    if (strcmp(token[0], "exit") == 0) {
        exit(0);
    }

    if (strcmp(token[0], "cd") == 0) {
        chdir(token[1]);
        printf("> %s: %s\n", token[0], token[1]);
        return;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork Failed");
        exit(1);
    }

    if (pid > 0) {
        int wstatus;

        waitpid(pid, &wstatus, 0);
        status = WEXITSTATUS(wstatus);

        for (i = 0; i < i + 1; i++) {
            printf("%s ", token[i]);
        }
        printf("%s\n", "->");
        printf("%d\n", status);
    } else {
        if (execvp(token[0], token) < 0) {
            perror("Exec Failed");
            exit(1);
        }
    }
}

int main() {
    char *cwd;
    int i;

    signal(SIGINT, sigint_handler);

    while (1) {
        printf("> %s> ", getcwd(cwd, sizeof(cwd)));
        fgets(line, MAX_LINE, stdin);
        line[strlen(line) - 1] = '\0';

        parse_line(line);

        if (strcmp(token[0], "") == 0) {
            continue;
        }

        for (i = 0; i < i + 1; i++) {
            printf("%s ", token[i]);
        }
        printf("%s\n", "->");

        execute_command();
    }

    return 0;
}