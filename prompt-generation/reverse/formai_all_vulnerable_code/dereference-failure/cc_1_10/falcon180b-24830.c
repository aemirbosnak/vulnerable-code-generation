//Falcon-180B DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Error: fork() failed\n");
        exit(1);
    } else if (pid == 0) {
        execlp(command, command, NULL);
        printf("Error: execlp() failed\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void list_processes() {
    FILE *fp;
    char line[1024];
    char *token;

    fp = fopen("/proc/self/status", "r");

    if (fp == NULL) {
        printf("Error: could not open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");

        if (strcmp(token, "Name") == 0) {
            printf("Process name: %s\n", strtok(NULL, ":"));
        } else if (strcmp(token, "State") == 0) {
            printf("Process state: %s\n", strtok(NULL, ":"));
        } else if (strcmp(token, "PPid") == 0) {
            printf("Parent process ID: %s\n", strtok(NULL, ":"));
        }
    }

    fclose(fp);
}

void create_file(char *filename) {
    int fd;

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1) {
        printf("Error: could not create file %s\n", filename);
        exit(1);
    }

    close(fd);
}

int main() {
    char command[1024];

    printf("Enter a command to execute: ");
    fgets(command, sizeof(command), stdin);

    execute_command(command);

    printf("Enter a command to list processes: ");
    fgets(command, sizeof(command), stdin);

    list_processes();

    printf("Enter a filename to create: ");
    fgets(command, sizeof(command), stdin);

    create_file(command);

    return 0;
}