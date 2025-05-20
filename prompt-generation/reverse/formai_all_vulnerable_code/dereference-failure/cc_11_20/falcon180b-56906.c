//Falcon-180B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " "

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char *token;
    pid_t child_pid;
    int status;

    while(1) {
        printf("Enter command: ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        token = strtok(input_buffer, DELIM);

        if(strcmp(token, "exit") == 0) {
            break;
        } else if(strcmp(token, "cd") == 0) {
            token = strtok(NULL, DELIM);
            if(token == NULL) {
                printf("Directory not specified.\n");
            } else {
                if(chdir(token)!= 0) {
                    perror("chdir");
                }
            }
        } else if(strcmp(token, "mkdir") == 0) {
            token = strtok(NULL, DELIM);
            if(token == NULL) {
                printf("Directory name not specified.\n");
            } else {
                if(mkdir(token, 0777)!= 0) {
                    perror("mkdir");
                }
            }
        } else if(strcmp(token, "touch") == 0) {
            token = strtok(NULL, DELIM);
            if(token == NULL) {
                printf("File name not specified.\n");
            } else {
                int file = open(token, O_CREAT | O_WRONLY, 0777);
                if(file == -1) {
                    perror("touch");
                } else {
                    close(file);
                }
            }
        } else if(strcmp(token, "rm") == 0) {
            token = strtok(NULL, DELIM);
            if(token == NULL) {
                printf("File/Directory name not specified.\n");
            } else {
                if(unlink(token)!= 0) {
                    perror("rm");
                }
            }
        } else if(strcmp(token, "ls") == 0) {
            system("ls");
        } else if(strcmp(token, "ps") == 0) {
            system("ps");
        } else {
            child_pid = fork();

            if(child_pid == 0) {
                execlp(token, token, NULL);
            } else if(child_pid == -1) {
                perror("fork");
            }

            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}