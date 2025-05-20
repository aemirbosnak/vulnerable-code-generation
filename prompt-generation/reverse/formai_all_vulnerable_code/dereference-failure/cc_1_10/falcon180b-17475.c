//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define MAX_SIZE 100

typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} msgbuf;

int main() {
    int shmid;
    int semid;
    int msqid;
    int i;
    char *shmaddr;
    key_t key;

    // Create shared memory segment
    key = ftok("shared_memory.txt", 65);
    shmid = shmget(key, MAX_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void*)-1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < MAX_SIZE; i++) {
        *(shmaddr + i) = 0;
    }

    // Create semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    // Initialize semaphore
    semctl(semid, 0, SETVAL, 1);

    // Create message queue
    msqid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (msqid == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }

    // Send message
    msgbuf msg;
    strcpy(msg.mtext, "Hello, World!");
    msg.mtype = 1;
    msgsnd(msqid, &msg, strlen(msg.mtext), 0);

    // Receive message
    msgbuf received_msg;
    msgrcv(msqid, &received_msg, MAX_SIZE, 1, 0);
    printf("Received message: %s\n", received_msg.mtext);

    // Clean up
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
    msgctl(msqid, IPC_RMID, NULL);

    return 0;
}