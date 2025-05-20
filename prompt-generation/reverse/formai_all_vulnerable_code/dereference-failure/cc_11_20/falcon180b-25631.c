//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMANDS 100

struct command {
    char *path;
    char **argv;
    int argc;
    int background;
};

int main() {
    char line[MAX_LINE_LENGTH];
    char *token;
    struct command *commands = (struct command *)malloc(MAX_COMMANDS * sizeof(struct command));
    int num_commands = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }
        if (strcmp(token, "&") == 0) {
            token = strtok(NULL, " ");
        }
        if (num_commands >= MAX_COMMANDS) {
            printf("Too many commands.\n");
            return 1;
        }
        commands[num_commands].path = token;
        commands[num_commands].argv = (char **)malloc((num_commands + 1) * sizeof(char *));
        commands[num_commands].argv[0] = token;
        num_commands++;
        int i = 1;
        while ((token = strtok(NULL, " "))!= NULL) {
            commands[num_commands - 1].argv[i] = token;
            i++;
        }
        commands[num_commands - 1].argv[i] = NULL;
        commands[num_commands - 1].argc = i;
        commands[num_commands - 1].background = (num_commands > 1 && strcmp(token, "&") == 0);
    }
    fclose(stdin);

    for (int i = 0; i < num_commands; i++) {
        if (commands[i].background) {
            pid_t pid = fork();
            if (pid == 0) {
                execvp(commands[i].path, commands[i].argv);
                perror("execvp");
                exit(EXIT_FAILURE);
            } else if (pid < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            }
        } else {
            pid_t pid = fork();
            if (pid == 0) {
                execvp(commands[i].path, commands[i].argv);
                perror("execvp");
                exit(EXIT_FAILURE);
            } else if (pid < 0) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else {
                waitpid(pid, NULL, 0);
            }
        }
    }

    return 0;
}