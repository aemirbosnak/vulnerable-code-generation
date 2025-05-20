#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 128

int main(int argc, char *argv[], char *envp[]) {
    char buffer[BUFFER_SIZE];
    char *token;
    pid_t pid;
    int status;

    if (argc < 2) {
        printf("Usage: simple_shell command\n");
        return 1;
    }

    strcpy(buffer, argv[1]);
    token = strtok(buffer, " ");

    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        char *args[10];
        int i = 0;

        while ((token = strtok(NULL, " ")) != NULL) {
            args[i++] = token;
        }
        args[i] = NULL;

        execvp(args[0], args);
        perror("Exec failed");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}
