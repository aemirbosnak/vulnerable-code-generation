//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SEM_KEY 0x1234
#define SHM_KEY 0x5678
#define SHM_SIZE 1024

int semid;
int shmid;
char *shm;

void cleanup() {
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
}

int main() {
    int i;
    semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (char*)-1) {
        perror("shmat");
        return 1;
    }

    // Initialize shared memory
    for (i = 0; i < SHM_SIZE; i++) {
        shm[i] = 0;
    }

    atexit(cleanup);

    // Producer process
    int producer_pid = fork();
    if (producer_pid == 0) {
        int count = 0;
        while (count < 10) {
            sem_wait(semid);
            shm[0]++;
            count++;
            sem_post(semid);
            sleep(1);
        }
        exit(0);
    }

    // Consumer process
    int consumer_pid = fork();
    if (consumer_pid == 0) {
        int count = 0;
        while (count < 10) {
            sem_wait(semid);
            printf("Consumer: Shared memory value is %d\n", shm[0]);
            count++;
            sem_post(semid);
            sleep(2);
        }
        exit(0);
    }

    wait(NULL);
    wait(NULL);

    return 0;
}