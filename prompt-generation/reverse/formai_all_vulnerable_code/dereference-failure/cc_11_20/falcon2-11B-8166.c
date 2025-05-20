//Falcon2-11B DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    // Initialize variables
    int pid, i, j, k, num_children, status;
    char input[100], output[100], buffer[100], command[100];
    char **argv_list;

    // Initialize arrays
    argv_list = (char **)malloc(argc * sizeof(char *));
    for (i = 0; i < argc; i++) {
        argv_list[i] = (char *)malloc(strlen(argv[i]) + 1);
        strcpy(argv_list[i], argv[i]);
    }

    // Create and execute child processes
    for (i = 0; i < argc; i++) {
        if (argv[i][0]!= '-') {
            printf("Executing command: %s\n", argv[i]);
            pid = fork();

            if (pid == 0) {
                // Child process
                printf("Child process created with PID %d\n", getpid());
                execl(argv[i], argv[i], NULL);
            } else if (pid > 0) {
                // Parent process
                wait(&status);
                printf("Child process finished with status %d\n", WEXITSTATUS(status));
            } else {
                printf("Fork failed\n");
            }
        }
    }

    // Print the output of the child processes
    printf("Printing output of child processes:\n");
    for (i = 0; i < argc; i++) {
        if (argv[i][0]!= '-') {
            printf("Output of command: %s\n", argv[i]);
            if (access(argv[i], F_OK) == 0) {
                FILE *file = fopen(argv[i], "r");
                while (fgets(buffer, sizeof(buffer), file)!= NULL) {
                    printf("%s", buffer);
                }
                fclose(file);
            } else {
                printf("No such file or directory\n");
            }
        }
    }

    // Clean up memory
    for (i = 0; i < argc; i++) {
        free(argv_list[i]);
    }
    free(argv_list);

    return 0;
}