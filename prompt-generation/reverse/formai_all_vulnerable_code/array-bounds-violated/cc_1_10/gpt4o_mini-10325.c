//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_NUM_ARGS 100

void parse_command(char *line, char **args) {
    while (*line != '\0') {
        while (*line == ' ') 
            *line++ = '\0'; // Replace space with null character
        *args++ = line; // Save argument position
        while (*line != '\0' && *line != ' ') 
            line++; // Move to the end of argument
    }
    *args = NULL; // Null-terminate the argument list
}

void execute_command(char **args, int background) {
    pid_t pid = fork();

    if (pid == 0) { // Child process
        if (execvp(args[0], args) < 0) {
            perror("Exec failed");
            exit(1);
        }
    } else if (pid < 0) {
        perror("Fork failed");
    } else { // Parent process
        if (!background) {
            waitpid(pid, NULL, 0); // Wait for the child to finish
        }
    }
}

int main() {
    char line[MAX_CMD_LEN];
    char *args[MAX_NUM_ARGS];
    char *input;
    int background;

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin)) { // Read input
            perror("fgets failed");
            continue;
        }

        // Remove trailing newline character if present
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "exit") == 0) {
            break; // Exit shell
        }

        // Handle background execution
        background = 0;
        if (line[strlen(line) - 1] == '&') {
            background = 1;
            line[strlen(line) - 1] = '\0'; // Remove '&'
        }

        parse_command(line, args);
        execute_command(args, background);
    }

    return 0;
}