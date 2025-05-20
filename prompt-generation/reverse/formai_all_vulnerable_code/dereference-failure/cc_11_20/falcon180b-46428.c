//Falcon-180B DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main() {
    char command[MAX_LINE_SIZE];
    char *args[MAX_LINE_SIZE];
    int i, num_args;
    pid_t pid;

    printf("Welcome to the happy C system administration program!\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_LINE_SIZE, stdin);

        num_args = 0;
        args[num_args] = strtok(command, " ");

        while (args[num_args]!= NULL) {
            num_args++;
            args[num_args] = strtok(NULL, " ");
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "mkdir") == 0) {
            if (num_args!= 2) {
                printf("Invalid number of arguments for mkdir command.\n");
            } else {
                mkdir(args[1], 0755);
                printf("Directory %s created successfully!\n", args[1]);
            }
        } else if (strcmp(args[0], "touch") == 0) {
            if (num_args!= 2) {
                printf("Invalid number of arguments for touch command.\n");
            } else {
                int fd = open(args[1], O_CREAT | O_WRONLY, 0644);
                if (fd == -1) {
                    printf("Failed to create file %s.\n", args[1]);
                } else {
                    close(fd);
                    printf("File %s created successfully!\n", args[1]);
                }
            }
        } else if (strcmp(args[0], "ls") == 0) {
            if (num_args == 1) {
                system("ls");
            } else {
                system("ls -l ");
            }
        } else if (strcmp(args[0], "cd") == 0) {
            if (num_args!= 2) {
                printf("Invalid number of arguments for cd command.\n");
            } else {
                if (chdir(args[1]) == -1) {
                    printf("Failed to change directory to %s.\n", args[1]);
                }
            }
        } else if (strcmp(args[0], "pwd") == 0) {
            system("pwd");
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}