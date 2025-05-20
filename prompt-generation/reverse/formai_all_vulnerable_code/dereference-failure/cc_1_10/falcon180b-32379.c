//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUF_SIZE 1024
#define SHM_KEY 0x1234
#define MSG_KEY 0x5678

int main() {
    int shmid, msqid;
    char *shmptr;
    struct msqid_ds {
        struct ipc_perm msg_perm;
        unsigned long msg_qnum;
        unsigned long msg_qbytes;
        unsigned long msg_lspid;
        unsigned long msg_lrpid;
        time_t msg_stime;
        time_t msg_rtime;
        time_t msg_ctime;
    } msgq_ds;

    // Create shared memory segment
    if ((shmid = shmget(SHM_KEY, BUF_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    if ((shmptr = shmat(shmid, 0, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Create message queue
    if ((msqid = msgget(MSG_KEY, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(1);
    }

    // Fill shared memory segment with message
    strcpy(shmptr, "Hello, world!");

    // Send message to message queue
    if (msgsnd(msqid, shmptr, BUF_SIZE, 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    // Detach from shared memory segment
    if (shmdt(shmptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Receive message from message queue
    if (msgrcv(msqid, shmptr, BUF_SIZE, 0, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    // Print received message
    printf("Received message: %s\n", shmptr);

    // Remove shared memory segment and message queue
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    if (msgctl(msqid, IPC_RMID, &msgq_ds) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}