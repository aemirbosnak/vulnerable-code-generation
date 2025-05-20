//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>

#define TRUE 1
#define FALSE 0
#define MAX_CLIENTS 5

int main() {
    int semid, shmid, msqid;
    struct sembuf sem_op;
    char *shm_ptr;
    struct msgbuf {
        long mtype;
        char mtext[80];
    } msg;

    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error: Failed to create semaphore\n");
        exit(1);
    }

    sem_op.sem_num = 0;
    sem_op.sem_op = 0;
    sem_op.sem_flg = SEM_UNDO;

    if (semop(semid, &sem_op, 1) == -1) {
        printf("Error: Failed to initialize semaphore\n");
        exit(1);
    }

    shmid = shmget(IPC_PRIVATE, sizeof(char) * MAX_CLIENTS, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: Failed to create shared memory\n");
        exit(1);
    }

    shm_ptr = (char *) shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        printf("Error: Failed to attach shared memory\n");
        exit(1);
    }

    msqid = msgget(IPC_PRIVATE, 0666);
    if (msqid == -1) {
        printf("Error: Failed to create message queue\n");
        exit(1);
    }

    while (TRUE) {
        sem_op.sem_num = 0;
        sem_op.sem_op = -1;
        sem_op.sem_flg = SEM_UNDO;

        if (semop(semid, &sem_op, 1) == -1) {
            printf("Error: Failed to lock semaphore\n");
            exit(1);
        }

        strcpy(shm_ptr, "Hello, world!");
        printf("Message sent: %s\n", shm_ptr);

        msg.mtype = 1;
        strcpy(msg.mtext, shm_ptr);
        if (msgsnd(msqid, &msg, sizeof(msg.mtext), 0) == -1) {
            printf("Error: Failed to send message\n");
            exit(1);
        }
    }

    return 0;
}