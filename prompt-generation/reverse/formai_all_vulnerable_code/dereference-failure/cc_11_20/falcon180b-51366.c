//Falcon-180B DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

int main(int argc, char *argv[]) {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    int argument_count;
    int status;

    printf("Welcome to the C System Administration Program!\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        argument_count = 0;

        char *token = strtok(command, DELIM);
        while (token!= NULL) {
            arguments[argument_count++] = token;
            if (argument_count >= MAX_ARGUMENTS) {
                printf("Too many arguments.\n");
                break;
            }
            token = strtok(NULL, DELIM);
        }

        if (strcmp(arguments[0], "exit") == 0) {
            break;
        } else if (strcmp(arguments[0], "mkdir") == 0) {
            if (argument_count!= 2) {
                printf("Usage: mkdir <directory>\n");
            } else {
                status = mkdir(arguments[1], 0755);
                if (status!= 0) {
                    printf("Error: %s\n", strerror(errno));
                }
            }
        } else if (strcmp(arguments[0], "rmdir") == 0) {
            if (argument_count!= 2) {
                printf("Usage: rmdir <directory>\n");
            } else {
                status = rmdir(arguments[1]);
                if (status!= 0) {
                    printf("Error: %s\n", strerror(errno));
                }
            }
        } else if (strcmp(arguments[0], "touch") == 0) {
            if (argument_count!= 2) {
                printf("Usage: touch <file>\n");
            } else {
                int fd = open(arguments[1], O_CREAT | O_WRONLY, 0644);
                if (fd == -1) {
                    printf("Error: %s\n", strerror(errno));
                } else {
                    close(fd);
                }
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}