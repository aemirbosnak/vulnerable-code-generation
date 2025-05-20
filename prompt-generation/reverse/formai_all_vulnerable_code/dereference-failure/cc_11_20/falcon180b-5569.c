//Falcon-180B DATASET v1.0 Category: System administration ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char *argv[MAX_ARGUMENTS];
int argc;

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char *token;
    pid_t child_pid;
    int status;

    printf("Welcome to the command prompt!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        token = strtok(input, " ");
        if (token == NULL) {
            continue;
        }

        for (int i = 0; i < MAX_ARGUMENTS; i++) {
            argv[i] = NULL;
        }

        argc = 0;
        while ((token = strtok(NULL, " "))!= NULL) {
            argv[argc++] = token;
            if (argc >= MAX_ARGUMENTS) {
                break;
            }
        }

        if (strcmp(argv[0], "exit") == 0) {
            break;
        } else if (strcmp(argv[0], "cd") == 0) {
            if (argc!= 2) {
                printf("Usage: cd [directory]\n");
            } else {
                int result = chdir(argv[1]);
                if (result!= 0) {
                    perror("chdir");
                }
            }
        } else if (strcmp(argv[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd))!= NULL) {
                printf("%s\n", cwd);
            } else {
                perror("getcwd");
            }
        } else {
            child_pid = fork();

            if (child_pid == 0) {
                execvp(argv[0], argv);
                perror("execvp");
                exit(1);
            } else if (child_pid < 0) {
                perror("fork");
            } else {
                waitpid(child_pid, &status, 0);
            }
        }
    }

    return 0;
}