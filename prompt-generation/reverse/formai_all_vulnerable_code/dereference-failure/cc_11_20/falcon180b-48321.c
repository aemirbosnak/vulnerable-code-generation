//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define SIZE 10
#define SEM_ID 010
#define MSG_QID 011
#define SHM_ID 012

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    int semid, shmid, msqid;
    char *shmaddr;
    key_t key = 12345;

    // creating shared memory
    if ((shmid = shmget(key, SIZE, 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    if ((shmaddr = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // initializing shared memory
    memset(shmaddr, 0, SIZE);

    // creating semaphore
    if ((semid = semget(key, 1, 0666)) == -1) {
        perror("semget");
        exit(1);
    }

    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl");
        exit(1);
    }

    // creating message queue
    if ((msqid = msgget(key, 0666)) == -1) {
        perror("msgget");
        exit(1);
    }

    // send message
    struct msgbuf {
        long mtype;
        char mtext[SIZE];
    } msg;

    msg.mtype = 1;
    strcpy(msg.mtext, "Hello, world!");

    if (msgsnd(msqid, &msg, SIZE, 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    // receive message
    struct msgbuf msg_received;

    if (msgrcv(msqid, &msg_received, SIZE, 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    printf("Received message: %s\n", msg_received.mtext);

    // cleanup
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(1);
    }

    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}