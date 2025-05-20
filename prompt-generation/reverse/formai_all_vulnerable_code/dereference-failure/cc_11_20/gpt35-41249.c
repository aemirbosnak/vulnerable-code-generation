//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAXLINE 80 // Maximum length of command

int main(void) {
    char inputBuffer[MAXLINE]; // buffer for user input
    char *args[MAXLINE/2+1]; // command line arguments
    int shouldRun = 1; // flag for exiting program
    int childpid; // PID of child process
    int status; // exit status of child process

    while (shouldRun) {
        printf("osh> ");
        fflush(stdout);

        // read command from user input
        fgets(inputBuffer, MAXLINE, stdin);

        // parse command into arguments
        int i = 0, j = 0, numArgs = 0;
        while (inputBuffer[j] != '\n') {
            while (inputBuffer[j] == ' ' || inputBuffer[j] == '\t') {
                inputBuffer[j] = '\0';
                j++;
            }
            args[i] = &inputBuffer[j];
            i++;
            numArgs++;
            while (inputBuffer[j] != '\0' && inputBuffer[j] != ' ' && inputBuffer[j] != '\t' && inputBuffer[j] != '\n') {
                j++;
            }
        }
        args[i] = NULL; // set last argument to NULL

        // exit command
        if (strcmp(args[0], "exit") == 0) {
            shouldRun = 0;
            break;
        }

        childpid = fork(); // create child process
        
        if (childpid < 0) { // fork failed
            printf("Fork failed\n");
            exit(1);
        } else if (childpid == 0) { // child process
            execvp(args[0], args);
            exit(0); // exit child process
        } else { // parent process
            // wait for child to finish
            wait(&status);

            if (WIFEXITED(status)) {
                printf("Child exited with code %d\n", WEXITSTATUS(status));
            } else {
                printf("Child terminated abnormally\n");
            }
        }
    }

    return 0;
}