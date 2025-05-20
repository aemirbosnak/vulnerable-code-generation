//Falcon-180B DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <libgen.h>

#define MAX_LINE_LENGTH 1024
#define MAX_PATH_LENGTH 4096
#define MAX_ARG_LENGTH 4096
#define MAX_COMMAND_LENGTH 4096
#define MAX_ENV_LENGTH 4096

typedef struct {
    char *name;
    char *value;
} env_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        // Child process
        char **child_args = argv + 1;
        char *command = argv[1];
        char *args[MAX_ARG_LENGTH];
        int num_args = 0;

        while (*child_args!= NULL) {
            if (num_args >= MAX_ARG_LENGTH) {
                fprintf(stderr, "Too many arguments\n");
                exit(1);
            }
            args[num_args] = *child_args;
            child_args++;
            num_args++;
        }
        args[num_args] = NULL;

        execlp(command, command, NULL);
        fprintf(stderr, "execlp failed: %s\n", strerror(errno));
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}