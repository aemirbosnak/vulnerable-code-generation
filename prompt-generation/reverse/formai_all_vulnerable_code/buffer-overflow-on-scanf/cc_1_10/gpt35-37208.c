//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

#define MSG_SIZE 100

struct message {
    long int mtype;
    char mtext[MSG_SIZE];
};

int main() {
    int msqid;
    key_t key = ftok("ipc_program", 'a');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msqid = msgget(key, 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // child process
        struct message msg;
        memset(msg.mtext, 0, MSG_SIZE);

        if (msgrcv(msqid, &msg, MSG_SIZE, 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("Child process: message received: %s\n", msg.mtext);

        // send back the message
        msg.mtype = 2;
        strncpy(msg.mtext, "Thanks for your message", MSG_SIZE);

        if (msgsnd(msqid, &msg, strlen(msg.mtext) + 1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        printf("Child process: message sent\n");
        exit(0);
    } else {
        // parent process
        struct message msg;
        memset(msg.mtext, 0, MSG_SIZE);

        printf("Parent process: enter message to send to child: ");
        scanf("%[^\n]", msg.mtext);

        msg.mtype = 1;

        if (msgsnd(msqid, &msg, strlen(msg.mtext) + 1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        printf("Parent process: message sent\n");

        if (msgrcv(msqid, &msg, MSG_SIZE, 2, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }

        printf("Parent process: message received: %s\n", msg.mtext);
    }

    return 0;
}