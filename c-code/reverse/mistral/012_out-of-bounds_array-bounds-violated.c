#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int i, arg_index = 1, arg_count = 0;
    char **args;

    if (argc < 3) {
        printf("Usage: %s command argument1 argument2 ...\n", argv[0]);
        return 1;
    }

    args = (char **)malloc((argc - 2) * sizeof(char *));
    for (i = arg_index + 1; i < argc; ++i) {
        args[arg_count++] = argv[i];
    }
    args[arg_count] = NULL;

    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    } else if (pid > 0) {
        wait(NULL);
    } else {
        execvp(args[0], args);
        perror("Execvp failed");
        exit(1);
    }

    free(args);
    return 0;
}
