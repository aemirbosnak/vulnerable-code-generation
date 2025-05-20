//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 100
#define MAX_QUEUE_SIZE 10
#define MSG_QUEUE_KEY 12345

typedef struct {
    long mtype;
    char mtext[MAX_MSG_SIZE];
} message_t;

int main() {
    int msgid;
    key_t key = MSG_QUEUE_KEY;
    int msqid;

    // Create the message queue
    if ((msqid = msgget(key, 0666 | IPC_CREAT)) == -1) {
        fprintf(stderr, "Error creating message queue: %s\n", strerror(errno));
        exit(1);
    }

    // Get the message queue ID
    if ((msgid = msgget(key, 0)) == -1) {
        fprintf(stderr, "Error getting message queue ID: %s\n", strerror(errno));
        exit(1);
    }

    // Send a message to the queue
    message_t msg;
    strcpy(msg.mtext, "Hello, world!");
    if (msgsnd(msgid, &msg, MAX_MSG_SIZE, 0) == -1) {
        fprintf(stderr, "Error sending message: %s\n", strerror(errno));
        exit(1);
    }

    // Receive a message from the queue
    message_t received_msg;
    if (msgrcv(msgid, &received_msg, MAX_MSG_SIZE, 0, 0) == -1) {
        fprintf(stderr, "Error receiving message: %s\n", strerror(errno));
        exit(1);
    }

    // Print the received message
    printf("Received message: %s\n", received_msg.mtext);

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        fprintf(stderr, "Error removing message queue: %s\n", strerror(errno));
        exit(1);
    }

    return 0;
}