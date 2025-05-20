//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCS 100
#define MAX_COMMAND_LENGTH 1024

char *procs[MAX_PROCS];
int num_procs = 0;

void launch_process(char *command) {
    int pid = fork();
    if (pid == 0) {
        execlp(command, command, NULL);
        perror("execlp");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        procs[num_procs++] = command;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    int i;
    for (i = 1; i < argc; i++) {
        strcat(command, " ");
        strcat(command, argv[i]);
    }

    launch_process(command);

    for (i = 0; i < num_procs; i++) {
        int status;
        waitpid(procs[i][0], &status, 0);
        free(procs[i]);
    }

    return 0;
}