//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LINE 1024

char **split_line(char *line) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(line, " \t\r\n");
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, " \t\r\n");
    }

    argv[argc] = NULL;
    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_LINE];
    char **argv;
    int background = 0;
    int exit_status = 0;

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        argv = split_line(input);
        if (argv[0] == NULL) {
            continue;
        }

        if (strcmp(argv[0], "exit") == 0) {
            break;
        } else if (strcmp(argv[0], "bg") == 0 || strcmp(argv[0], "fg") == 0) {
            if (argv[1] == NULL) {
                fprintf(stderr, "No job ID specified.\n");
            } else {
                int job_id = atoi(argv[1]);

                if (strcmp(argv[0], "bg") == 0) {
                    if (job_id > 0 && job_id <= 9) {
                        fprintf(stdout, "Job %d moved to background.\n", job_id);
                        background = 1;
                    } else {
                        fprintf(stderr, "No such job.\n");
                    }
                } else if (strcmp(argv[0], "fg") == 0) {
                    if (job_id > 0 && job_id <= 9) {
                        fprintf(stdout, "Job %d moved to foreground.\n", job_id);
                    } else {
                        fprintf(stderr, "No such job.\n");
                    }
                }
            }
        } else {
            if (background == 1) {
                fprintf(stdout, "[%d] %s", getpid(), input);
            }

            exit_status = execute_command(argv);

            if (WIFEXITED(exit_status)) {
                fprintf(stdout, "Exit status: %d\n", WEXITSTATUS(exit_status));
            }
        }
    }

    return 0;
}