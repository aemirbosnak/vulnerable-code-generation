//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 1024

struct msg_buf {
    long mtype;
    char mtext[MSG_SIZE];
};

int main(int argc, char *argv[]) {
    key_t key;
    int msqid;
    struct msg_buf msg;
    pid_t pid;

    if (argc != 2) {
        printf("Usage: %s <key>\n", argv[0]);
        return 1;
    }

    key = atoi(argv[1]);

    // create message queue
    if ((msqid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        return 1;
    }

    // parent process
    if ((pid = fork()) == 0) {
        // child process
        printf("Child process started\n");

        // send message to message queue
        msg.mtype = 1;
        strcpy(msg.mtext, "Hello, world!");
        if (msgsnd(msqid, &msg, sizeof(msg), 0) == -1) {
            perror("msgsnd");
            return 1;
        }

        printf("Message sent\n");

        // wait for message to be received
        if (msgrcv(msqid, &msg, sizeof(msg), 0, 0) == -1) {
            perror("msgrcv");
            return 1;
        }

        printf("Message received: %s\n", msg.mtext);

        // exit child process
        return 0;
    }

    // parent process
    printf("Parent process started\n");

    // wait for child process to send message
    if (msgrcv(msqid, &msg, sizeof(msg), 0, 0) == -1) {
        perror("msgrcv");
        return 1;
    }

    printf("Message received: %s\n", msg.mtext);

    // send response to child process
    msg.mtype = 2;
    strcpy(msg.mtext, "Hello, child process!");
    if (msgsnd(msqid, &msg, sizeof(msg), 0) == -1) {
        perror("msgsnd");
        return 1;
    }

    printf("Response sent\n");

    // wait for child process to exit
    if (wait(NULL) == -1) {
        perror("wait");
        return 1;
    }

    // remove message queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return 1;
    }

    return 0;
}