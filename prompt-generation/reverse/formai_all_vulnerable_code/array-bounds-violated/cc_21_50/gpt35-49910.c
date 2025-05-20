//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
// Unix-like Shell Program in C Language

/* ============================================================================
 * Written by: [YOUR NAME]
 * Date: [DATE OF CREATION]
 * Description: This code implements a basic Unix-like shell program in C language. 
 * The shell allows users to run various commands, such as cd, echo, ls, pwd, etc.
 * It also supports pipelining of multiple commands, input/output redirection, 
 * and background processes.
 * 
 * DISCLAIMER: This code is for educational purposes only. It is not meant to be 
 * used in production systems.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 10

int main () {
    int status;
    char command[100];
    char *commands[MAX_COMMANDS][MAX_ARGS];
    int i, j;
    int background_process = 0;
    int input_redirection = 0;
    char input_file[50];
    int output_redirection = 0;
    char output_file[50];
    
    while (1) {
        printf(">>> ");
        fflush(stdout);
        fgets(command, 100, stdin);
        command[strlen(command) - 1] = '\0';
        
        // Parsing the command
        i = 0;
        j = 0;
        while (command[i] != '\0') {
            if (command[i] == '|') {
                commands[j][j] = NULL; // End of current command
                j++; // Next command
            }
            else if (command[i] == '&') {
                background_process = 1;
                commands[j][j] = NULL;
            }
            else if (command[i] == '<') {
                input_redirection = 1;
                sscanf(command + i + 1, "%s", input_file);
            }
            else if (command[i] == '>') {
                output_redirection = 1;
                sscanf(command + i + 1, "%s", output_file);
            }
            else if (command[i] != ' ') {
                // Start of new argument for current command
                if (commands[j][0] == NULL) {
                    commands[j][0] = command + i;
                    j++;
                }
                // Adding new argument
                else {
                    commands[j - 1][i - j] = command + i;
                }
                // Jumping to the end of the current argument
                while (command[i] != ' ' && command[i] != '\0') {
                    i++;
                }
                continue;
            }
            i++;
        }
        commands[j][j] = NULL; // End of last command
        
        // Executing the command(s)
        int num_commands = j + 1;
        int pipes[num_commands - 1][2];
        pid_t pids[num_commands];
        
        for (i = 0; i < num_commands; i++) {
            // Creating pipe for communication between two commands
            if (i < num_commands - 1) {
                if (pipe(pipes[i]) == -1) {
                    perror("pipe");
                    exit(EXIT_FAILURE);
                }
            }
            // Forking current command
            pids[i] = fork();
            if (pids[i] == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            // Child process
            else if (pids[i] == 0) {
                // Input redirection
                if (input_redirection && i == 0) {
                    freopen(input_file, "r", stdin);
                }
                // Output redirection
                if (output_redirection && i == num_commands - 1) {
                    freopen(output_file, "w", stdout);
                }
                // Closing read end of previous pipe
                if (i > 0) {
                    close(pipes[i - 1][1]);
                    dup2(pipes[i - 1][0], STDIN_FILENO);
                }
                // Closing write end of current pipe
                if (i < num_commands - 1) {
                    close(pipes[i][0]);
                    dup2(pipes[i][1], STDOUT_FILENO);
                }
                // Executing the current command
                if (execvp(commands[i][0], commands[i]) == -1) {
                    perror("exec");
                    exit(EXIT_FAILURE);
                }
            }
        }
        
        // Closing pipes after all commands have executed
        for (i = 0; i < num_commands - 1; i++) {
            close(pipes[i][0]);
            close(pipes[i][1]);
        }
        
        // Waiting for all child processes to terminate
        for (i = 0; i < num_commands; i++) {
            waitpid(pids[i], &status, 0);
        }
        
        // Reseting variables for next command
        background_process = 0;
        input_redirection = 0;
        output_redirection = 0;
        for (i = 0; i < MAX_COMMANDS; i++) {
            for (j = 0; j < MAX_ARGS; j++) {
                commands[i][j] = NULL;
            }
        }
    }
    
    return 0;
}