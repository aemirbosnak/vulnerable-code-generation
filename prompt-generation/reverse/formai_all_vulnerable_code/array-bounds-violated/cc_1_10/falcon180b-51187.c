//Falcon-180B DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ENV_VARIABLES 10

typedef struct {
    char *name;
    char *value;
} env_variable_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s command [arguments]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    char *arguments[MAX_ARGUMENTS];
    int num_arguments = 0;

    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            arguments[num_arguments++] = argv[i];
        }
    }

    pid_t pid = fork();

    if (pid == -1) {
        printf("Error forking process\n");
        return 1;
    } else if (pid == 0) {
        for (int i = 0; i < num_arguments; i++) {
            char *argument = arguments[i];
            char *env_value = getenv(argument);

            if (env_value!= NULL) {
                arguments[i] = env_value;
            }
        }

        execvp(command, arguments);
        printf("Error executing command\n");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}