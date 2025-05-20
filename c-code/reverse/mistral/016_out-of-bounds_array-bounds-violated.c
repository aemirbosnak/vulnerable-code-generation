#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 128
#define MAX_CMD_LENGTH 64

void execute_command(char *command) {
    pid_t pid;
    int pipefd[2];
    char buffer[BUFFER_SIZE];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid > 0) { // parent process
        close(pipefd[0]);
        char cmd[MAX_CMD_LENGTH];
        strcpy(cmd, command);
        strcat(cmd, " | cat > output.txt");
        write(pipefd[1], cmd, strlen(cmd));
        close(pipefd[1]);
        wait(NULL);
    } else { // child process
        close(pipefd[1]);
        char buffer[BUFFER_SIZE];
        read(pipefd[0], buffer, BUFFER_SIZE);
        execlp(buffer, buffer, (char *)0);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char input[MAX_CMD_LENGTH];

    printf("Simple Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_CMD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        execute_command(input);
    }

    return 0;
}
