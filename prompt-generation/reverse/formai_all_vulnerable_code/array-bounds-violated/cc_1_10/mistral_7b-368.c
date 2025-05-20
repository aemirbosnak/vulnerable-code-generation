//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>

#define MAX_CMD_LEN 1024
#define NUM_CMDS 10

int main() {
    pid_t children[NUM_CMDS];
    int status;
    char cmds[NUM_CMDS][MAX_CMD_LEN];
    int i;

    signal(SIGINT, SIG_IGN); // Ignore Ctrl+C

    printf("\n-------------------------------------------------------\n");
    printf("|              Visionary Unix-like Shell v1.0          |\n");
    printf("|                                                     |\n");
    printf("-------------------------------------------------------\n\n");

    for (i = 0; i < NUM_CMDS; i++) {
        printf("Enter command %d: ", i + 1);
        bzero(cmds[i], MAX_CMD_LEN);
        fgets(cmds[i], MAX_CMD_LEN, stdin);
        cmds[i][strlen(cmds[i]) - 1] = '\0'; // Remove newline character

        if (strcmp(cmds[i], "exit") == 0) {
            break;
        }

        children[i] = fork();

        if (children[i] < 0) { // Error occurred
            perror("fork() failed");
            exit(EXIT_FAILURE);
        }

        if (children[i] > 0) { // Parent process
            waitpid(children[i], &status, 0);
        } else { // Child process
            char *args[] = {"/bin/sh", "-c", cmds[i], NULL};
            execvp(args[0], args);
            perror("execvp() failed");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_CMDS; i++) {
        wait(&status);
    }

    printf("\nExiting...\n");

    return EXIT_SUCCESS;
}