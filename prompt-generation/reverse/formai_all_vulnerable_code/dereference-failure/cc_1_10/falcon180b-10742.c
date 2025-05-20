//Falcon-180B DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char *command = NULL;
char *arguments[MAX_ARGUMENTS] = { NULL };
int num_arguments = 0;

void read_command() {
    printf("Enter command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = '\0';
    
    char *token = strtok(command, " ");
    while (token!= NULL) {
        arguments[num_arguments] = token;
        num_arguments++;
        if (num_arguments >= MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
}

void execute_command() {
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    printf("Welcome to the cryptic shell!\n");
    
    while (1) {
        read_command();
        execute_command();
    }
    
    return 0;
}