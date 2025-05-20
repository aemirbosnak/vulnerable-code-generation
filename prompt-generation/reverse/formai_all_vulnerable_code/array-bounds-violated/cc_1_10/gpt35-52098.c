//FormAI DATASET v1.0 Category: Interprocess communication ; Style: medieval
/* LORD'S MESSAGE PASSING MESSENGER */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

#define MSGSIZE 256 // message size

int main(void)
{
    int p[2];   // file descriptor array for pipe
    pid_t pid;  // process id
    char msg[MSGSIZE];  // message buffer
    time_t t;   // time variable for timestamps

    if (pipe(p) < 0) { // pipe creation error handling
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) < 0) { // fork error handling
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // parent process
        close(p[0]); // close read pipe

        while (1) {
            printf("Enter thy message: ");
            fgets(msg, MSGSIZE, stdin); // get message from user
            time(&t); // get timestamp
            strcat(msg, asctime(localtime(&t))); // append timestamp to message
            msg[strlen(msg) - 1] = '\0'; // replace \n with \0
            write(p[1], msg, MSGSIZE);  // write message to pipe
        }
        close(p[1]); // close write pipe
    } else { // child process
        close(p[1]); // close write pipe

        while (1) {
            if (read(p[0], msg, MSGSIZE) > 0) { // if message is received
                printf("Messenger: %s\n", msg); // print message
            }
        }
        close(p[0]); // close read pipe
    }
    
    return EXIT_SUCCESS;
}