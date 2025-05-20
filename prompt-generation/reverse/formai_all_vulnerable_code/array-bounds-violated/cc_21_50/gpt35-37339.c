//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_COMMAND_LEN 100
#define MAX_NUM_COMMANDS 10

int main() {

    char *commands[MAX_NUM_COMMANDS][MAX_ARGS + 1];
    char command[MAX_COMMAND_LEN + 1];
    pid_t child_pid;
    int num_commands = 0, i, j;

    printf("CyberShell - The ultimate hacker's shell\n");
    printf("Enter the commands you want to execute (max %d):\n", MAX_NUM_COMMANDS);

    // Read the commands
    while (num_commands < MAX_NUM_COMMANDS) {
        printf("Command %d:> ", num_commands + 1);
        fgets(command, MAX_COMMAND_LEN, stdin);

        // Remove the trailing newline character
        command[strlen(command) - 1] = '\0';

        if (strlen(command) == 0) {
            break;
        }

        // Split the command into arguments
        char *arg = strtok(command, " ");
        int arg_num = 0;

        while (arg != NULL) {
            commands[num_commands][arg_num] = arg;
            arg = strtok(NULL, " ");
            arg_num++;

            if (arg_num == MAX_ARGS || strlen(arg) == 0) {
                break;
            }
        }

        commands[num_commands][arg_num] = NULL;
        num_commands++;
    }

    // Execute the commands
    int pipefd[MAX_NUM_COMMANDS - 1][2];

    for (i = 0; i < num_commands - 1; i++) {
        if (pipe(pipefd[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < num_commands; i++) {
        child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            // Child process

            int fd;
            if (i == 0) {
                dup2(pipefd[i][1], STDOUT_FILENO);
            } else if (i == num_commands - 1) {
                dup2(pipefd[i - 1][0], STDIN_FILENO);
            } else {
                dup2(pipefd[i][1], STDOUT_FILENO);
                dup2(pipefd[i - 1][0], STDIN_FILENO);
            }

            for (j = 0; j < num_commands - 1; j++) {
                if (close(pipefd[j][0]) == -1 || close(pipefd[j][1]) == -1) {
                    perror("close");
                    exit(EXIT_FAILURE);
                }
            }

            execvp(commands[i][0], commands[i]);

            perror(commands[i][0]);

            exit(EXIT_FAILURE);
        }
    }

    // Close the pipes
    for (i = 0; i < num_commands - 1; i++) {
        if (close(pipefd[i][0]) == -1 || close(pipefd[i][1]) == -1) {
            perror("close");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for the child processes to finish
    int status;
    for (i = 0; i < num_commands; i++) {
        if (wait(&status) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            printf("Command %d exited with status %d\n", i+1, WEXITSTATUS(status));
        }
    }

    return 0;
}