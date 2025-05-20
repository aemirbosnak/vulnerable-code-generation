//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *command;
    int pid;
    int status;
} command_t;

int execute_command(command_t *cmd) {
    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error forking process\n");
        exit(1);
    }
    if (pid == 0) {
        execlp(cmd->command, cmd->command, NULL);
        exit(1);
    }
    int status;
    waitpid(pid, &status, 0);
    cmd->status = status;
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(1);
    }
    command_t commands[MAX_COMMANDS];
    int num_commands = 0;

    commands[num_commands].command = argv[1];
    execute_command(&commands[num_commands]);
    num_commands++;

    while (num_commands < MAX_COMMANDS && commands[num_commands - 1].status == 0) {
        char input[1024];
        printf("Enter next command: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        commands[num_commands].command = strdup(input);
        execute_command(&commands[num_commands]);
        num_commands++;
    }

    for (int i = 0; i < num_commands; i++) {
        if (commands[i].status!= 0) {
            fprintf(stderr, "Command '%s' failed with status %d\n", commands[i].command, commands[i].status);
        }
    }

    return 0;
}