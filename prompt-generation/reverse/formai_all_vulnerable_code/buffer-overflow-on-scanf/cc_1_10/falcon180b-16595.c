//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100
#define SERVER_ID 0
#define CLIENT_ID 1

typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} msgbuf;

int main() {
    int msgid, msqid, msg_size;
    key_t key = ftok("msg_queue", 65);
    int client_id;
    char input[MAX_SIZE];
    msgbuf msg;

    msqid = msgget(key, IPC_CREAT | 0666);
    if (msqid == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }

    msg_size = sizeof(msgbuf) - sizeof(long);
    msg.mtype = CLIENT_ID;
    strcpy(msg.mtext, "Client connected");
    if (msgsnd(msqid, &msg, msg_size, 0) == -1) {
        printf("Error sending message\n");
        exit(1);
    }

    while (1) {
        if (msgrcv(msqid, &msg, msg_size, SERVER_ID, 0) == -1) {
            printf("Error receiving message\n");
            exit(1);
        }
        printf("Message received: %s\n", msg.mtext);

        memset(input, 0, MAX_SIZE);
        scanf("%[^\n]s", input);

        msg.mtype = CLIENT_ID;
        strcpy(msg.mtext, input);
        if (msgsnd(msqid, &msg, msg_size, 0) == -1) {
            printf("Error sending message\n");
            exit(1);
        }
    }

    return 0;
}