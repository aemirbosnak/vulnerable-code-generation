//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main() {
    char buf[BUF_SIZE];
    pid_t pid;
    int status;

    while (1) {
        printf("mini-shell > ");
        if (fgets(buf, BUF_SIZE, stdin) == NULL) {
            if (feof(stdin)) {
                printf("\n");
                exit(0);
            } else {
                perror("fgets");
                exit(1);
            }
        }

        buf[strlen(buf) - 1] = '\0';  // Remove newline

        if (strcmp(buf, "exit") == 0) {
            exit(0);
        } else {
            pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(1);
            } else if (pid == 0) {
                if (execlp("/bin/sh", "sh", "-c", buf, NULL) == -1) {
                    perror("execlp");
                    exit(1);
                }
            } else {
                waitpid(pid, &status, 0);
                if (WEXITSTATUS(status) != 0) {
                    printf("Command failed with exit status %d\n", WEXITSTATUS(status));
                }
            }
        }
    }

    return 0;
}