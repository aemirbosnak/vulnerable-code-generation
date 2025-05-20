//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SIZE 10
#define SEM_ID 0x0001
#define SHM_ID 0x0002

int main() {
    int shmid, semid;
    int *shm;
    int *sem;
    int counter = 0;

    semid = semget(SEM_ID, 1, 0666 | IPC_CREAT);
    if(semid < 0) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    sem = (int *) semctl(semid, 0, GETVAL, 0);
    if(sem == (int *) -1) {
        printf("Error getting semaphore value\n");
        exit(1);
    }
    sem[0] = 1;
    semctl(semid, 0, SETVAL, sem);

    shmid = shmget(SHM_ID, SIZE * sizeof(int), 0666 | IPC_CREAT);
    if(shmid < 0) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    shm = (int *) shmat(shmid, NULL, 0);
    if(shm == (int *) -1) {
        printf("Error attaching to shared memory\n");
        exit(1);
    }

    for(int i = 0; i < SIZE; i++) {
        shm[i] = 0;
    }

    int pid = fork();
    if(pid < 0) {
        printf("Error forking\n");
        exit(1);
    } else if(pid == 0) {
        while(counter < SIZE) {
            semop(semid, &sem, 2);
            shm[counter] = counter;
            counter++;
            sleep(1);
        }
    } else {
        while(counter < SIZE) {
            sleep(1);
        }
        printf("All values have been written to shared memory\n");
    }

    semctl(semid, 0, IPC_RMID);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}