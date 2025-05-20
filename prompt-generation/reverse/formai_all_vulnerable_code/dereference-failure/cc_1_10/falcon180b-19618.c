//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_KEY 1234
#define SEM_ID 1
#define BUFFER_SIZE 1024

int main() {
    int semid;
    key_t key;
    int shmid;
    char *shmaddr;
    int i;
    char *buffer;

    semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    key = ftok("sem.c",'s');
    shmid = shmget(key, BUFFER_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    buffer = (char *) shmaddr;

    for (i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = '\0';
    }

    printf("Write a message: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    printf("Message: %s\n", buffer);

    semctl(semid, SEM_ID, IPC_RMID);
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}