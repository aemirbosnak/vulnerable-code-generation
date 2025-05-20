//Falcon-180B DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char *delimiter = " ";
    char *token;
    pid_t pid;
    int status;

    while (1) {
        printf("Enter command: ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        token = strtok(input_buffer, delimiter);

        if (strcmp(token, "exit") == 0) {
            break;
        } else if (strcmp(token, "cd") == 0) {
            token = strtok(NULL, delimiter);
            if (chdir(token) == -1) {
                perror("Error");
            }
        } else if (strcmp(token, "mkdir") == 0) {
            token = strtok(NULL, delimiter);
            if (mkdir(token, 0755) == -1) {
                perror("Error");
            }
        } else if (strcmp(token, "rmdir") == 0) {
            token = strtok(NULL, delimiter);
            if (rmdir(token) == -1) {
                perror("Error");
            }
        } else if (strcmp(token, "touch") == 0) {
            token = strtok(NULL, delimiter);
            int fd = open(token, O_CREAT | O_WRONLY, 0644);
            if (fd == -1) {
                perror("Error");
            } else {
                close(fd);
            }
        } else if (strcmp(token, "cat") == 0) {
            token = strtok(NULL, delimiter);
            FILE *fp = fopen(token, "r");
            if (fp == NULL) {
                perror("Error");
            } else {
                while (!feof(fp)) {
                    fputc(fgetc(fp), stdout);
                }
                fclose(fp);
            }
        } else if (strcmp(token, "ls") == 0) {
            system("ls");
        } else {
            pid = fork();

            if (pid == -1) {
                perror("Error");
            } else if (pid == 0) {
                execlp(token, token, NULL);
                perror("Error");
                exit(1);
            } else {
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}