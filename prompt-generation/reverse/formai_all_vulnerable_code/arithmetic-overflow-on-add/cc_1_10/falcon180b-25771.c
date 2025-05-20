//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>

#define NUM_PROCS 5
#define SLEEP_SEC 2
#define SLEEP_USEC 0

char **create_argv(int argc, char *argv[]) {
    char **new_argv = malloc((argc + 1) * sizeof(char *));
    int i;

    for (i = 0; i < argc; i++) {
        new_argv[i] = argv[i];
    }

    new_argv[argc] = NULL;

    return new_argv;
}

void print_cpu_usage(pid_t pid) {
    struct rusage usage;

    if (getrusage(RUSAGE_CHILDREN, &usage) == -1) {
        perror("getrusage");
        exit(EXIT_FAILURE);
    }

    printf("PID: %d\n", pid);
    printf("CPU usage: %.2f%%\n", (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) * 100.0 / SLEEP_SEC);
}

int main() {
    pid_t pids[NUM_PROCS];
    int i;

    for (i = 0; i < NUM_PROCS; i++) {
        pids[i] = fork();

        if (pids[i] == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pids[i] == 0) {
            execlp("sleep", "sleep", "2", NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_PROCS; i++) {
        waitpid(pids[i], NULL, WNOHANG);
    }

    for (i = 0; i < NUM_PROCS; i++) {
        print_cpu_usage(pids[i]);
    }

    return 0;
}