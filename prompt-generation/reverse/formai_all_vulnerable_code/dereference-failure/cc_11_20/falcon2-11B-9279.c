//Falcon2-11B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char buf[BUFSIZ];
    pid_t pid;
    int status;
    char* command;

    while (1) {
        printf("$ ");
        fgets(buf, sizeof(buf), stdin);
        command = strtok(buf, "\n");
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "cd") == 0) {
            char* new_dir;
            ssize_t len = getcwd(buf, sizeof(buf));
            new_dir = (char*)malloc(len+1);
            if (new_dir == NULL) {
                printf("Out of memory\n");
                continue;
            }
            if (chdir(new_dir) == -1) {
                free(new_dir);
                printf("Cannot change directory\n");
                continue;
            }
            free(new_dir);
            continue;
        } else if (strcmp(command, "pwd") == 0) {
            char* new_dir;
            ssize_t len = getcwd(buf, sizeof(buf));
            new_dir = (char*)malloc(len+1);
            if (new_dir == NULL) {
                printf("Out of memory\n");
                continue;
            }
            if (chdir(new_dir) == -1) {
                free(new_dir);
                printf("Cannot change directory\n");
                continue;
            }
            free(new_dir);
            continue;
        } else if (strcmp(command, "exec") == 0) {
            pid = fork();
            if (pid == -1) {
                printf("Fork failed\n");
                continue;
            } else if (pid == 0) {
                if (execvp(command, &command) == -1) {
                    exit(1);
                }
            } else {
                waitpid(pid, &status, 0);
                if (WIFEXITED(status)) {
                    printf("Exit status: %d\n", WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                    printf("Signal status: %d\n", WTERMSIG(status));
                } else {
                    printf("Error status\n");
                }
            }
        } else if (strcmp(command, "sleep") == 0) {
            pid = fork();
            if (pid == -1) {
                printf("Fork failed\n");
                continue;
            } else if (pid == 0) {
                sleep(atoi(command + 5));
            } else {
                waitpid(pid, &status, 0);
                if (WIFEXITED(status)) {
                    printf("Exit status: %d\n", WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                    printf("Signal status: %d\n", WTERMSIG(status));
                } else {
                    printf("Error status\n");
                }
            }
        } else {
            printf("Unrecognized command\n");
        }
    }

    return 0;
}