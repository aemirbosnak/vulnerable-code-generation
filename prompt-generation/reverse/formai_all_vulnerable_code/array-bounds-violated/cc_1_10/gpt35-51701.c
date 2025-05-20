//FormAI DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    int pid, status;
    char command[BUFFER_SIZE];
    char *command_args[10];

    printf("Welcome to the System Administration Example Program!\n");
    printf("Please enter a command to execute:\n");

    while (1) {
        fgets(command, BUFFER_SIZE, stdin); 
        command[strlen(command) - 1] = '\0'; 

        if (!strcmp(command, "exit")) {
            printf("Goodbye!\n");
            break;
        }

        char *token = strtok(command, " ");

        int i = 0;
        while (token != NULL) {
            command_args[i++] = token;
            token = strtok(NULL, " ");
        }
        command_args[i] = NULL;

        if ((pid = fork()) == 0) { 

            int res = execvp(command_args[0], command_args); 

            if (res == -1) { 
                printf("Invalid command.\n");
            }

        } else {

            waitpid(pid, &status, 0);
            if (status == -1) {
                printf("Command execution failed.\n");
            }

        }
    }

    return 0;
}