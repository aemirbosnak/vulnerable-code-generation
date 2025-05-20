//FormAI DATASET v1.0 Category: System administration ; Style: synchronous
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

//Function to handle commands
void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        //child code
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        //error in forking
        perror("Error forking process");
    } else {
        //parent code
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

//Main function
int main() {
    char *args[100]; //array to hold commands
    char command[100]; //variable to hold command entered by user

    while (1) {
        printf("Enter command: ");
        fgets(command, 100, stdin);
        command[strlen(command) - 1] = '\0'; //remove new line character from command

        int i = 0;
        args[i] = strtok(command, " "); //split command into tokens

        //loop to split command into tokens and store in array
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        args[i] = NULL; //set last argument as NULL

        //check for exit command
        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(EXIT_SUCCESS);
        }

        //check for cd command
        if (strcmp(args[0], "cd") == 0) {
            if (chdir(args[1]) != 0) {
                perror("Error changing directory");
            }
            continue;
        }

        //check for help command
        if (strcmp(args[0], "help") == 0) {
            printf("List of available commands:\n");
            printf("cd <directory> - Change directory\n");
            printf("exit - Exit the shell\n");
            printf("help - Display list of available commands\n");
            continue;
        }

        execute_command(args); //execute command
    }

    return 0;
}