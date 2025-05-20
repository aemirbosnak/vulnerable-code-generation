//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char* split_input[MAX_ARGS];
    char* commands[] = {"ls", "cd", "pwd", "exit"}; // list of commands
    int num_commands = 4; // number of commands
    int status;
    pid_t pid;

    while (1) {
        // print prompt
        printf("mind-bending-shell$ ");

        // get input from user
        fgets(input, MAX_LENGTH, stdin);

        // check if user wants to exit
        if (strcmp(input, "exit\n") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // split input into separate strings (arguments)
        char* token = strtok(input, " ");
        int i = 0;
        while (token != NULL) {
            split_input[i++] = token;
            token = strtok(NULL, " ");
        }
        split_input[i-1][strlen(split_input[i-1])-1] = '\0'; // remove newline character from last argument

        // check if input matches any of the commands
        int command_found = 0;
        for (int j = 0; j < num_commands; j++) {
            if (strcmp(split_input[0], commands[j]) == 0) {
                command_found = 1;
                break;
            }
        }

        if (!command_found) {
            printf("Command not found: %s\n", split_input[0]);
            continue;
        }

        pid = fork(); // create child process
        if (pid == -1) {
            printf("Error: fork failed\n");
            exit(1);
        } else if (pid == 0) { // child process
            if (strcmp(split_input[0], "ls") == 0) { // ls command
                if (split_input[1] == NULL) {
                    execlp("ls", "ls", NULL); 
                } else {
                    execlp("ls", "ls", split_input[1], NULL); 
                }
            } else if (strcmp(split_input[0], "cd") == 0) { // cd command
                if (split_input[1] == NULL) {
                    printf("Error: Please provide a directory to change to\n");
                    exit(1);
                } else {
                    chdir(split_input[1]);
                }
            } else if (strcmp(split_input[0], "pwd") == 0) { // pwd command
                char cwd[1024];
                getcwd(cwd, sizeof(cwd));
                printf("%s\n", cwd);
            }
            exit(0);
        } else { // parent process
            wait(&status); // wait for child process to finish
        }
    }

    return 0;
}