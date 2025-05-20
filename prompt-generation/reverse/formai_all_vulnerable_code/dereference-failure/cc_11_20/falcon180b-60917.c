//Falcon-180B DATASET v1.0 Category: System administration ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char input[BUFFER_SIZE];
    char *command;
    char *args[10];
    int num_args;
    int i;
    int status;

    printf("Alan Turing's System Administration Program\n");
    while (1) {
        printf("> ");
        fgets(input, BUFFER_SIZE, stdin);
        command = strtok(input, " \n");

        num_args = 0;
        args[num_args] = strtok(NULL, " \n");
        while (args[num_args]!= NULL) {
            num_args++;
            args[num_args] = strtok(NULL, " \n");
        }

        if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else if (strcmp(command, "ls") == 0) {
            system("ls");
        } else if (strcmp(command, "mkdir") == 0) {
            if (num_args!= 2) {
                printf("Invalid number of arguments for mkdir\n");
            } else {
                status = mkdir(args[1], 0777);
                if (status == 0) {
                    printf("Directory created successfully\n");
                } else {
                    perror("mkdir");
                }
            }
        } else if (strcmp(command, "rmdir") == 0) {
            if (num_args!= 2) {
                printf("Invalid number of arguments for rmdir\n");
            } else {
                status = rmdir(args[1]);
                if (status == 0) {
                    printf("Directory removed successfully\n");
                } else {
                    perror("rmdir");
                }
            }
        } else if (strcmp(command, "touch") == 0) {
            if (num_args!= 2) {
                printf("Invalid number of arguments for touch\n");
            } else {
                FILE *file;
                file = fopen(args[1], "w");
                if (file == NULL) {
                    perror("touch");
                } else {
                    fclose(file);
                    printf("File created successfully\n");
                }
            }
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}