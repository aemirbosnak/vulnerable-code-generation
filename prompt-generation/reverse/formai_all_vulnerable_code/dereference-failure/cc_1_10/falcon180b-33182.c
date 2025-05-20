//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

char **environ;
char *shell_prompt = "shell> ";

void init_shell() {
    environ = (char **)malloc(sizeof(char *) * 10);
    environ[0] = (char *)malloc(sizeof(char) * 7);
    strcpy(environ[0], "HOME=~");
    environ[1] = (char *)malloc(sizeof(char) * 7);
    strcpy(environ[1], "TERM=xterm");
    environ[2] = NULL;
}

void print_prompt() {
    printf("%s", shell_prompt);
    fflush(stdout);
}

int execute_command(char *command) {
    pid_t pid;
    int status;
    char *argv[10];
    int argc;

    argv[0] = strtok(command, " ");
    argc = 1;
    while ((argv[argc] = strtok(NULL, " "))!= NULL) {
        argc++;
    }
    argv[argc] = NULL;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(argv[0], argv);
        perror("execvp");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

int main() {
    init_shell();
    while (1) {
        print_prompt();
        char input[100];
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';
        int status = execute_command(input);
        if (status == 1) {
            printf("Error: %s\n", strerror(errno));
        }
    }
    return 0;
}