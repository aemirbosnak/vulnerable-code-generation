//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **environ;

int main(int argc, char **argv) {
    char *line;
    char *delim = " ";
    char **tokens;
    int status;

    environ = argv + argc + 1;

    while (1) {
        printf("> ");
        if (fgets(line, 1024, stdin) == NULL) {
            printf("\n");
            exit(1);
        }

        tokens = strtok_r(line, delim, &line);
        if (tokens == NULL) {
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(tokens[0], "cd") == 0) {
            if (tokens[1] == NULL) {
                printf("Directory not specified.\n");
            } else {
                if (chdir(tokens[1])!= 0) {
                    perror("chdir");
                }
            }
        } else if (strcmp(tokens[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd))!= NULL) {
                printf("%s\n", cwd);
            } else {
                perror("getcwd");
            }
        } else {
            pid_t pid;
            int fd[2];

            if (pipe(fd)!= 0) {
                perror("pipe");
                exit(1);
            }

            pid = fork();

            if (pid == -1) {
                perror("fork");
                exit(1);
            } else if (pid == 0) {
                dup2(fd[0], STDIN_FILENO);
                close(fd[1]);

                if (execvp(tokens[0], tokens) == -1) {
                    perror("execvp");
                    exit(1);
                }
            } else {
                close(fd[0]);

                if (write(fd[1], line, strlen(line))!= strlen(line)) {
                    perror("write");
                }

                close(fd[1]);

                waitpid(pid, &status, WUNTRACED);
            }
        }
    }

    return 0;
}