//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>

#define SIZE 10
#define SHM_KEY 1234
#define SEM_KEY 5678
#define MSG_KEY 9012

int main() {
    int shmid, semid, msqid;
    char *shmaddr;
    int *shmptr;
    int semval = 0;
    struct msgbuf {
        long mtype;
        char mtext[SIZE];
    } msg;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        return 1;
    }
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void*)-1) {
        printf("Error attaching to shared memory segment\n");
        return 1;
    }
    shmptr = (int*)shmaddr;

    // Initialize shared memory with random values
    for (int i = 0; i < SIZE; i++) {
        *shmptr++ = rand();
    }

    // Create semaphore
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore\n");
        return 1;
    }
    if (semctl(semid, 0, SETVAL, semval) == -1) {
        printf("Error setting semaphore value\n");
        return 1;
    }

    // Create message queue
    msqid = msgget(MSG_KEY, IPC_CREAT | 0666);
    if (msqid == -1) {
        printf("Error creating message queue\n");
        return 1;
    }

    // Send message to message queue
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello, world!");
    if (msgsnd(msqid, &msg, SIZE, 0) == -1) {
        printf("Error sending message\n");
        return 1;
    }

    // Receive message from message queue
    if (msgrcv(msqid, &msg, SIZE, 1, 0) == -1) {
        printf("Error receiving message\n");
        return 1;
    }
    printf("Received message: %s\n", msg.mtext);

    // Clean up
    shmdt(shmaddr);
    semctl(semid, 0, IPC_RMID);
    msgctl(msqid, IPC_RMID, NULL);

    return 0;
}