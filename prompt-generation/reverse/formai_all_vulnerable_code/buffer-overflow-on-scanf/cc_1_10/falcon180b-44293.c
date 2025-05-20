//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define TRUE   1
#define FALSE  0
#define HEARTBEAT 1
#define PROPOSAL 2
#define ACCEPTANCE 3
#define REJECTION 4

#define MAX_SIZE 100

typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} message;

int main() {
    int msqid;
    key_t key = ftok(".", 65); // use current directory and 'A' as key for IPC identifier

    if((msqid = msgget(key, 0666 | IPC_CREAT)) == -1) {
        printf("Error creating message queue.\n");
        exit(1);
    }

    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    message msg;
    strcpy(msg.mtext, name);
    msg.mtype = HEARTBEAT;

    if(msgsnd(msqid, &msg, sizeof(msg.mtext), 0) == -1) {
        printf("Error sending message.\n");
        exit(1);
    }

    while(TRUE) {
        if(msgrcv(msqid, &msg, sizeof(msg.mtext), HEARTBEAT, 0) == -1) {
            printf("Error receiving message.\n");
            exit(1);
        }

        printf("Message received: %s\n", msg.mtext);

        if(strcmp(msg.mtext, "PROPOSAL") == 0) {
            msg.mtype = ACCEPTANCE;
        } else if(strcmp(msg.mtext, "REJECTION") == 0) {
            msg.mtype = REJECTION;
        }

        if(msgsnd(msqid, &msg, sizeof(msg.mtext), 0) == -1) {
            printf("Error sending message.\n");
            exit(1);
        }
    }

    return 0;
}