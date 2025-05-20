//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_DEPTH 10

void async_fib(int n, int depth, int *result, void (*callback)(int *)) {
    if (depth == MAX_DEPTH) {
        *result = n;
        callback(result);
        return;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork() error");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // parent process
        int child_result;
        waitpid(pid, &child_result, 0);
        *result = n + WEXITSTATUS(child_result);
        callback(result);
    } else {
        srand(time(NULL) ^ getpid());

        int fib1 = rand() % 10;
        int fib2 = rand() % 10;

        int fib1_result = 0;
        int fib2_result = 0;

        async_fib(fib1, depth + 1, &fib1_result, NULL);
        async_fib(fib2, depth + 1, &fib2_result, NULL);

        exit(fib1_result + fib2_result);
    }
}

void callback(int *result) {
    printf("The Fibonacci result is: %d\n", *result);
}

int main() {
    int result;

    async_fib(5, 1, &result, callback);

    pause();

    return 0;
}