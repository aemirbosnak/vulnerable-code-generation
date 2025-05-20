#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;
    char *command;

    if (argc < 2) {
        printf("Usage: %s command\n", argv[0]);
        return 1;
    }

    command = (char *)malloc(strlen(argv[1]) + 2);
    strcpy(command, "sh -c ");
    strcat(command, argv[1]);

    if ((pid = fork()) < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        execlp(command, command, (char *)NULL);
        perror("execlp failed");
        exit(1);
    }

    if (strchr(argv[1], '&')) {
        pid = fork();
        if (pid > 0) {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
