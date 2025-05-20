//Code Llama-13B DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int i, n;
    char **argv;
    char *process;
    int status;

    argv = malloc(sizeof(char *) * 100);
    process = malloc(sizeof(char) * 100);

    printf("Welcome to the C System Process Viewer\n");
    printf("====================================\n");

    printf("Enter the process name or PID: ");
    scanf("%s", process);

    if (process[0] == 'P') {
        pid_t pid = atoi(&process[1]);
        int result = waitpid(pid, &status, WNOHANG);
        if (result == -1) {
            perror("waitpid");
            exit(1);
        }

        if (WIFEXITED(status)) {
            printf("Process %d exited with status %d\n", pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Process %d terminated by signal %d\n", pid, WTERMSIG(status));
        } else {
            printf("Process %d is still running\n", pid);
        }
    } else {
        n = 0;
        while (1) {
            argv[n] = malloc(sizeof(char) * 100);
            printf("Enter the %dth argument: ", n + 1);
            scanf("%s", argv[n]);
            if (argv[n][0] == '\0') {
                break;
            }
            n++;
        }

        pid_t pid = fork();
        if (pid == 0) {
            execvp(process, argv);
        } else {
            int result = waitpid(pid, &status, 0);
            if (result == -1) {
                perror("waitpid");
                exit(1);
            }

            if (WIFEXITED(status)) {
                printf("Process %d exited with status %d\n", pid, WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Process %d terminated by signal %d\n", pid, WTERMSIG(status));
            } else {
                printf("Process %d is still running\n", pid);
            }
        }
    }

    return 0;
}