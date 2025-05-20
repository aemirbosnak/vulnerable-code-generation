//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SIZE 10
#define SEM_ID 0x1234
#define SHM_ID 0x5678

int main() {
    int shmid, semid;
    char *shm;
    int *sem;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE*sizeof(int), IPC_CREAT|0666);
    if(shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = shmat(shmid, NULL, 0);
    if(shm == (void*)-1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    for(int i=0; i<SIZE; i++) {
        *(shm+i) = i;
    }

    // Create semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT|0666);
    if(semid == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    // Initialize semaphore
    sem = (int*)semctl(semid, 0, GETVAL);
    *sem = 0;

    // Fork child process
    pid = fork();
    if(pid == -1) {
        printf("Error forking process\n");
        exit(1);
    } else if(pid == 0) {
        // Child process

        // Wait for semaphore
        sem_wait(semid);

        // Modify shared memory
        for(int i=0; i<SIZE; i++) {
            *(shm+i) += 10;
        }

        // Signal semaphore
        sem_post(semid);

        // Exit child process
        exit(0);
    } else {
        // Parent process

        // Wait for child process
        wait(NULL);

        // Print modified shared memory
        for(int i=0; i<SIZE; i++) {
            printf("%d ", *(shm+i));
        }
        printf("\n");

        // Remove shared memory and semaphore
        shmdt(shm);
        semctl(semid, 0, IPC_RMID);
    }

    return 0;
}