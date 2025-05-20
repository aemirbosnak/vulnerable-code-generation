//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_ID 0x0001
#define SHM_ID 0x0002
#define SHM_SIZE 1024

int main(int argc, char *argv[]) {
    int shmid, semid;
    char *shm;
    int *sem;
    int i;

    semid = semget(SEM_ID, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("Error in semget()");
        exit(1);
    }

    sem = (int *) semctl(semid, 0, GETVAL);
    if (sem == (int *) -1) {
        perror("Error in semctl()");
        exit(1);
    }

    shmid = shmget(SHM_ID, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("Error in shmget()");
        exit(1);
    }

    shm = (char *) shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("Error in shmat()");
        exit(1);
    }

    for (i = 0; i < SHM_SIZE; i++) {
        shm[i] = 0;
    }

    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("Error in semctl()");
        exit(1);
    }

    while (1) {
        if (semctl(semid, 0, GETVAL) == 0) {
            break;
        }
    }

    for (i = 0; i < SHM_SIZE; i++) {
        printf("%c", shm[i]);
    }

    if (shmdt(shm) == -1) {
        perror("Error in shmdt()");
        exit(1);
    }

    if (semctl(semid, 0, SETVAL, 0) == -1) {
        perror("Error in semctl()");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Error in shmctl()");
        exit(1);
    }

    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("Error in semctl()");
        exit(1);
    }

    return 0;
}