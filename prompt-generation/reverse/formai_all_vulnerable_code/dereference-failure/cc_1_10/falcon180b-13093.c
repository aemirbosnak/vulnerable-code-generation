//Falcon-180B DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE_LENGTH 80

void child_process(char *command);

int main(int argc, char *argv[]) {
    pid_t pid;
    char input_buffer[MAX_LINE_LENGTH];
    char *command;
    int status;

    printf("Enter a command to execute: ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);
    input_buffer[strcspn(input_buffer, "\n")] = '\0';
    command = strdup(input_buffer);

    pid = fork();

    if (pid == -1) {
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        child_process(command);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void child_process(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        execlp(command, command, NULL);
        printf("execlp failed.\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}