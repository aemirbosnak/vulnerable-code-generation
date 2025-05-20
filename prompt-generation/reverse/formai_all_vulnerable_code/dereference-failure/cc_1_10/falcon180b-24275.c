//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 100
#define SEM_KEY 0x1234
#define SHM_KEY 0x5678
#define MSG_KEY 0x9ABC

typedef struct {
    long mtype;
    char mtext[MAX_MSG_SIZE];
} message;

int main() {
    int shmid, semid, msqid;
    key_t shm_key, sem_key, msg_key;
    int i, count;
    char *shm_ptr;
    message msg_buffer;

    // Create shared memory segment
    shm_key = SHM_KEY;
    shmid = shmget(shm_key, sizeof(message), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    strcpy(shm_ptr, "Hello World!");

    // Create semaphore set
    sem_key = SEM_KEY;
    semid = semget(sem_key, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphore
    semctl(semid, 0, SETVAL, 0);

    // Create message queue
    msg_key = MSG_KEY;
    msqid = msgget(msg_key, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    // Send message
    strcpy(msg_buffer.mtext, "Hello World!");
    msg_buffer.mtype = 1;
    msgsnd(msqid, &msg_buffer, MAX_MSG_SIZE, 0);

    // Receive message
    msgrcv(msqid, &msg_buffer, MAX_MSG_SIZE, 1, 0);
    printf("Received message: %s\n", msg_buffer.mtext);

    // Clean up
    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
    msgctl(msqid, IPC_RMID, NULL);

    return 0;
}