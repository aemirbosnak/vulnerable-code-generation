//Falcon-180B DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE_SIZE 1000

char *cmd_line;
char *result_line;
char *cmd_args[MAX_LINE_SIZE];
int num_args;

void split_cmd_line(char *cmd_line) {
    char *token = strtok(cmd_line, " ");
    int i = 0;
    while (token!= NULL) {
        cmd_args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    num_args = i;
}

void execute_cmd(char *cmd_args[]) {
    pid_t child_pid;
    int status;
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    } else if (child_pid == 0) {
        execvp(cmd_args[0], cmd_args);
        perror("execvp");
        exit(1);
    } else {
        waitpid(child_pid, &status, 0);
    }
}

int main() {
    printf("Enter command: ");
    fgets(cmd_line, MAX_LINE_SIZE, stdin);
    cmd_line[strcspn(cmd_line, "\n")] = '\0';
    split_cmd_line(cmd_line);
    if (num_args == 0) {
        printf("No command entered.\n");
        return 1;
    }
    execute_cmd(cmd_args);
    return 0;
}