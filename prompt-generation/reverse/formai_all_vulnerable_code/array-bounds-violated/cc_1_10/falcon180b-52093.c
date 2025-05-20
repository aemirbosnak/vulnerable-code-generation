//Falcon-180B DATASET v1.0 Category: System administration ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_LINE 1024
#define MAX_COMMAND_ARGS 10

char *program_name;

void print_usage() {
    printf("Usage: %s <command> [<args>]\n", program_name);
}

int main(int argc, char *argv[]) {
    program_name = argv[0];

    if (argc == 1) {
        print_usage();
        return 1;
    }

    char *command = argv[1];
    char *args[MAX_COMMAND_ARGS];
    int num_args = 0;

    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            args[num_args++] = argv[i];
        }
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(command, args) == -1) {
            perror("execvp");
            return 1;
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}