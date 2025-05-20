//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_CMD_LENGTH 1000

void execute_commands(char *input)
{
    // Parse input into individual commands
    char *commands[MAX_ARGS];
    commands[0] = strtok(input, ";");
    int num_commands = 0;
    while(commands[num_commands] != NULL) {
        num_commands++;
        commands[num_commands] = strtok(NULL, ";");
    }

    // Process each individual command
    for(int i = 0; i < num_commands; i++) {

        // Parse command into arguments
        char *args[MAX_ARGS];
        args[0] = strtok(commands[i], " \t\n");
        int num_args = 0;
        while(args[num_args] != NULL) {
            num_args++;
            args[num_args] = strtok(NULL, " \t\n");
        }

        // Handle I/O redirection
        char *in_file = NULL;
        char *out_file = NULL;
        for(int j = 0; j < num_args; j++) {
            if(!strcmp(args[j], "<")) {
                in_file = args[j+1];
                args[j] = NULL;
                j++;
            }
            else if(!strcmp(args[j], ">")) {
                out_file = args[j+1];
                args[j] = NULL;
                j++;
            }
        }

        // Fork a child process to execute the command
        pid_t pid = fork();
        if(pid == 0) {

            // Redirect input and output if necessary
            if(in_file != NULL) {
                int in_fd = open(in_file, O_RDONLY);
                dup2(in_fd, STDIN_FILENO);
                close(in_fd);
            }
            if(out_file != NULL) {
                int out_fd = open(out_file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
                dup2(out_fd, STDOUT_FILENO);
                close(out_fd);
            }

            // Execute the command
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        else if(pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else {
            // Wait for child process to complete
            waitpid(pid, NULL, 0);
        }
    }
}

int main()
{
    char input[MAX_CMD_LENGTH];

    while(1) {
        // Print prompt and read input
        printf("> ");
        fflush(stdout);
        fgets(input, MAX_CMD_LENGTH, stdin);

        // Remove trailing newline character
        if(input[strlen(input)-1] == '\n') {
            input[strlen(input)-1] = '\0';
        }

        // Exit shell if "exit" command is entered
        if(!strcmp(input, "exit")) {
            break;
        }

        // Execute user command
        execute_commands(input);
    }

    return 0;
}