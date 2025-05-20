//Falcon-180B DATASET v1.0 Category: System administration ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void system_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execlp(command, command, NULL) == -1) {
            perror(command);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void display_process_info(int pid) {
    char buff[BUFFER_SIZE];
    sprintf(buff, "/proc/%d/cmdline", pid);
    FILE *fp = fopen(buff, "r");

    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    char command[BUFFER_SIZE];
    if (fgets(command, BUFFER_SIZE, fp) == NULL) {
        perror("fgets");
        exit(1);
    }

    fclose(fp);
    printf("Process ID: %d\nCommand: %s\n", pid, command);
}

void kill_process(int pid) {
    if (kill(pid, SIGKILL) == -1) {
        perror("kill");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <process_id> <command>\n", argv[0]);
        exit(1);
    }

    int pid = atoi(argv[1]);
    char *command = argv[2];

    display_process_info(pid);

    printf("Do you want to kill this process? (y/n): ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        kill_process(pid);
        printf("Process %d killed successfully.\n", pid);
    } else {
        printf("Process %d not killed.\n", pid);
    }

    return 0;
}