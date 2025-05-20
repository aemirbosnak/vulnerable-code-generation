//FormAI DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_ARGS 10

/* Function to execute a command with arguments */
int execute_command(char *cmd, char **args) {

    pid_t pid;
    int status;
    char *envp[] = { NULL };

    pid = fork();
    
    if (pid == -1) {
        printf("Error: Fork failed. %s.\n", strerror(errno));
        return 1;
    } 
    else if (pid == 0) {
        /* In child process */
        int ret = execve(cmd, args, envp);
        if (ret == -1) {
            printf("Error: Failed to execute '%s' %s.\n", cmd, strerror(errno));
            return 1;
        }
    } 
    else {
        /* In parent process */
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
    }
    
    return 0;

}

/* Function to parse a command with arguments and execute it */
int parse_command(char *command) {
    
    int i = 0;
    char *args[MAX_COMMAND_ARGS];
    char *arg;
    char *saveptr;
    char *token;

    /* Tokenize the command */
    token = strtok_r(command, " ", &saveptr);
    while (token != NULL && i < MAX_COMMAND_ARGS - 1) {
        args[i++] = token;
        token = strtok_r(NULL, " ", &saveptr);
    }
    args[i] = NULL;
    
    /* Execute the command */
    return execute_command(args[0], args);
}

int main() {
   
    char command[256];
    int ret;

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0'; /* Remove newline character */
        if (strlen(command) == 0) {
            continue;
        }
        if (strcmp(command, "exit") == 0) {
            break;
        }
        ret = parse_command(command);
        if (ret != 0) {
            printf("Error: Command failed with status %d.\n", ret);
        }
    }

    return 0;
}