//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 50

void fibonacci(int n) {
    int t1 = 0, t2 = 1, next;

    printf("Fibonacci Series up to %d:\n", n);
    printf("%d %d ", 0, 1);

    for (int i = 2; i <= n; ++i) {
        next = t1 + t2;
        t1 = t2;
        t2 = next;
        printf("%d ", next);
    }

    printf("\n");
}

void exec_cmd(char *cmd) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        execlp(cmd, cmd, (char *)NULL);
        perror("Error");
        exit(1);
    }

    if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        perror("Fork Failed");
        exit(1);
    }
}

int main() {
    int n, i;
    char str[100];

    printf("Enter a number: ");
    scanf("%d", &n);

    fibonacci(n);

    printf("Enter a command to execute: ");
    scanf("%s", str);

    printf("The Fibonacci sequence up to %d is calculated.\n", n);
    printf("Executing command: %s\n", str);

    exec_cmd(str);

    return 0;
}