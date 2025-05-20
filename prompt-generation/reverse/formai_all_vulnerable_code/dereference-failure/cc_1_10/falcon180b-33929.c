//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_LINE_SIZE 1024
#define MAX_COMMAND_SIZE 4096
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char *builtins[] = { "cd", "exit", NULL };

int is_builtin(char *command) {
    char *ptr = command;
    while (*ptr) {
        if (strncmp(ptr, "cd", 2) == 0 || strncmp(ptr, "exit", 4) == 0) {
            return 1;
        }
        ptr++;
    }
    return 0;
}

int execute_command(char *command) {
    pid_t pid;
    int status;
    char *args[MAX_ARGUMENTS];
    int argc = 0;
    char *ptr = strtok(command, DELIM);
    while (ptr!= NULL && argc < MAX_ARGUMENTS) {
        args[argc++] = ptr;
        ptr = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    if (is_builtin(args[0])) {
        switch (args[0][0]) {
            case 'c': {
                if (args[1] == NULL) {
                    fprintf(stderr, "Expected argument to 'cd'\n");
                } else {
                    if (chdir(args[1])!= 0) {
                        perror("chdir");
                    }
                }
                break;
            }
            case 'e': {
                exit(0);
            }
            default: {
                fprintf(stderr, "Unknown builtin command '%s'\n", args[0]);
            }
        }
    } else {
        pid = fork();
        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}

int main_loop() {
    char command[MAX_LINE_SIZE];
    while (1) {
        fprintf(stdout, "> ");
        fgets(command, MAX_LINE_SIZE, stdin);
        command[strcspn(command, "\n")] = '\0';
        execute_command(command);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    main_loop();
    return 0;
}