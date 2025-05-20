//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length of command
#define MAX_HISTORY 10 // Maximum number of commands in history

char* history[MAX_HISTORY]; // Array to store command history
int history_count = 0; // Counter for number of commands in history

void read_command(char* args[], int *should_run, int *background)
{
    char cmd[MAX_LINE];
    char *token;

    fgets(cmd, MAX_LINE, stdin); // Read command from user

    // Remove trailing newline character
    if(cmd[strlen(cmd) - 1] == '\n') {
        cmd[strlen(cmd) - 1] = '\0';
    }

    // Check if command should be run in background
    if(cmd[strlen(cmd) - 1] == '&') {
        *background = 1;
        cmd[strlen(cmd) - 1] = '\0';
    }

    // Split command into tokens
    token = strtok(cmd, " ");
    int i = 0;
    while(token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // Mark end of argument list

    // Add command to history
    if(args[0] != NULL && strcmp(args[0], "history") != 0) {
        history[history_count % MAX_HISTORY] = strdup(cmd);
        history_count++;
    }

    // Check if command is "exit"
    if(args[0] != NULL && strcmp(args[0], "exit") == 0) {
        *should_run = 0;
    }
}

void print_history()
{
    int i;
    for(i = 0; i < history_count && i < MAX_HISTORY; i++) {
        printf("%d: %s\n", i+1, history[i]);
    }
}

int main(void)
{
    char *args[MAX_LINE/2 + 1]; // Arguments for command
    int should_run = 1; // Flag to determine when to exit
    int background; // Flag to determine if command should be run in the background
    int status; // Exit status of child process
    pid_t pid; // Process ID of child process

    while(should_run) {
        printf("osh> ");
        fflush(stdout);

        background = 0; // Reset background flag
        read_command(args, &should_run, &background); // Read command from user

        if(args[0] != NULL) {
            // Check if command is "history"
            if(strcmp(args[0], "history") == 0) {
                print_history();
            }
            else {
                pid = fork(); // Create child process
                if(pid < 0) { // Error handling
                    printf("Error occurred while forking.\n");
                }
                else if(pid == 0) { // Child process
                    if(execvp(args[0], args) < 0) { // Execute command
                        printf("Error occurred while executing command.\n");
                        exit(1);
                    }
                }
                else { // Parent process
                    if(background == 0) { // Wait for child process to complete
                        waitpid(pid, &status, 0);
                    }
                }
            }
        }
    }

    return 0;
}