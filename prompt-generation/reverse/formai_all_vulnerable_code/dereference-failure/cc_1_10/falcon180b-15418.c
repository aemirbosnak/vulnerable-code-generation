//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 100
#define PROJECT_ID 9876
#define MY_ID 1234

typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} message;

int main() {
    int msgid;
    key_t key;
    message msg;

    // Create a message queue
    msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    if (msgid == -1) {
        fprintf(stderr, "Error creating message queue: %s\n", strerror(errno));
        exit(1);
    }

    // Set the key for the message queue
    key = ftok(".", PROJECT_ID);

    // Set the message type
    msg.mtype = MY_ID;

    // Send a message to the queue
    if (msgsnd(msgid, &msg, sizeof(msg), 0) == -1) {
        fprintf(stderr, "Error sending message: %s\n", strerror(errno));
        exit(1);
    }

    // Receive a message from the queue
    if (msgrcv(msgid, &msg, sizeof(msg), MY_ID, 0) == -1) {
        fprintf(stderr, "Error receiving message: %s\n", strerror(errno));
        exit(1);
    }

    printf("Received message: %s\n", msg.mtext);

    return 0;
}