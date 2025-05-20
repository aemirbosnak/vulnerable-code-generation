//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to create pipe
int createPipe(int pipefd[2]) {
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    return 0;
}

// Function to fork child process
pid_t forkChild(int pipefd[2]) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return pid;
}

// Function to send message to child process
int sendMessageToChild(int pipefd[2]) {
    char msg[100];
    printf("Enter message to be sent to child process: ");
    scanf("%s", msg);
    if (write(pipefd[1], msg, strlen(msg)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    return 0;
}

// Function to receive message from child process
int receiveMessageFromChild(int pipefd[2]) {
    char msg[100];
    if (read(pipefd[0], msg, 100) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Message from child process: %s\n", msg);
    return 0;
}

int main() {
    int pipefd[2];
    if (createPipe(pipefd)!= 0) {
        perror("createPipe");
        exit(EXIT_FAILURE);
    }
    pid_t pid = forkChild(pipefd);
    if (pid < 0) {
        perror("forkChild");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        sendMessageToChild(pipefd);
        exit(EXIT_SUCCESS);
    }
    else {
        receiveMessageFromChild(pipefd);
        exit(EXIT_SUCCESS);
    }
    return 0;
}