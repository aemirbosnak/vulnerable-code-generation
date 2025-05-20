//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define TRUE 1
#define FALSE 0
#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 100

typedef struct {
    long mtype;
    char mtext[MAX_MSG_SIZE];
} message;

int main() {
    int shmid, semid, semnum = 0, i;
    key_t key;
    char *shmaddr;
    struct sembuf sembuf;
    struct semid_ds semid_ds;
    message *msg;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(message) * MAX_CLIENTS, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    // Attach shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error attaching shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    // Initialize shared memory
    msg = (message *) shmaddr;
    for (i = 0; i < MAX_CLIENTS; i++) {
        msg[i].mtype = 0;
        strcpy(msg[i].mtext, "");
    }

    // Create semaphore set
    key = ftok(".",'s');
    semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore set: %s\n", strerror(errno));
        exit(1);
    }

    // Initialize semaphore
    sembuf.sem_num = semnum;
    sembuf.sem_op = 1;
    sembuf.sem_flg = SEM_UNDO;
    if (semop(semid, &sembuf, 1) == -1) {
        printf("Error initializing semaphore: %s\n", strerror(errno));
        exit(1);
    }

    // Accept connections from clients
    while (TRUE) {
        if (semop(semid, &sembuf, 1) == -1) {
            printf("Error decrementing semaphore: %s\n", strerror(errno));
            exit(1);
        }

        if (msg[0].mtype == 0) {
            printf("Waiting for client connection...\n");
            sleep(1);
        } else {
            printf("Client connected.\n");

            // Receive message from client
            strcpy(msg[0].mtext, "Welcome to the Sherlock Holmes Interprocess Communication System!");

            // Send message to client
            if (msgsnd(shmid, msg, strlen(msg[0].mtext) + 1, 0) == -1) {
                printf("Error sending message: %s\n", strerror(errno));
                exit(1);
            }

            // Increment semaphore
            sembuf.sem_op = 1;
            if (semop(semid, &sembuf, 1) == -1) {
                printf("Error incrementing semaphore: %s\n", strerror(errno));
                exit(1);
            }
        }
    }

    return 0;
}