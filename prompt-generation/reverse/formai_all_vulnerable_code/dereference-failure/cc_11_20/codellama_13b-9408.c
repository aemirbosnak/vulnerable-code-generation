//Code Llama-13B DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_ARGS 10

int main(int argc, char **argv) {
    char *args[MAX_ARGS];
    int i;

    // Get the command name
    char *cmd = argv[0];

    // Get the arguments
    for (i = 1; i < argc; i++) {
        args[i - 1] = argv[i];
    }

    // Check if the command is "echo"
    if (strcmp(cmd, "echo") == 0) {
        for (i = 0; i < argc - 1; i++) {
            printf("%s ", args[i]);
        }
        printf("\n");
    }

    // Check if the command is "cat"
    else if (strcmp(cmd, "cat") == 0) {
        for (i = 1; i < argc; i++) {
            FILE *file = fopen(args[i], "r");
            if (file == NULL) {
                printf("cat: %s: No such file or directory\n", args[i]);
                continue;
            }
            char c;
            while ((c = fgetc(file)) != EOF) {
                putchar(c);
            }
            fclose(file);
        }
    }

    // Check if the command is "cd"
    else if (strcmp(cmd, "cd") == 0) {
        if (argc < 2) {
            printf("cd: missing operand\n");
            return 1;
        }
        if (chdir(args[1]) != 0) {
            printf("cd: %s: No such file or directory\n", args[1]);
            return 1;
        }
    }

    // Check if the command is "pwd"
    else if (strcmp(cmd, "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            printf("pwd: getcwd() failed\n");
            return 1;
        }
        printf("%s\n", cwd);
    }

    // Check if the command is "exit"
    else if (strcmp(cmd, "exit") == 0) {
        return 0;
    }

    // If the command is not recognized, print an error message
    else {
        printf("Unknown command: %s\n", cmd);
        return 1;
    }

    return 0;
}