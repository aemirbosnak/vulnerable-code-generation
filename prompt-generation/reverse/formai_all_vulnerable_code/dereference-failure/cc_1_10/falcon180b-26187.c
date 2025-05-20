//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define MAX_SIZE 1024

typedef struct {
    long type;
    char data[MAX_SIZE];
} Message;

int main() {
    int shmid, msqid;
    Message *msg;
    char *shmaddr;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, MAX_SIZE, 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }
    // Initialize shared memory
    for (int i = 0; i < MAX_SIZE; i++) {
        shmaddr[i] = 'a';
    }

    // Create message queue
    msqid = msgget(IPC_PRIVATE, 0666);
    if (msqid == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }

    // Send message
    msg = (Message *) malloc(sizeof(Message));
    msg->type = 1;
    strcpy(msg->data, "Hello, world!");
    if (msgsnd(msqid, msg, sizeof(Message), 0) == -1) {
        printf("Error sending message\n");
        exit(1);
    }
    printf("Message sent\n");

    // Receive message
    msg = (Message *) malloc(sizeof(Message));
    if (msgrcv(msqid, msg, MAX_SIZE, 1, 0) == -1) {
        printf("Error receiving message\n");
        exit(1);
    }
    printf("Received message: %s\n", msg->data);

    // Detach from shared memory and destroy message queue
    if (shmdt(shmaddr) == -1) {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        printf("Error removing message queue\n");
        exit(1);
    }

    return 0;
}