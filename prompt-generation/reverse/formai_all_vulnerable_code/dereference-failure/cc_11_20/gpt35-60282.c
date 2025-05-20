//FormAI DATASET v1.0 Category: Interprocess communication ; Style: careful
// This program demonstrates Interprocess communication between a parent process 
// and its child process through shared memory and a semaphore.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_SIZE 1024

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main(void) {
    int shmid, semid;
    key_t shmkey, semkey;
    char *shm, *s; 
    struct sembuf sembuf_present = { 0, -1, SEM_UNDO };
    struct sembuf sembuf_reset = { 0, 1, SEM_UNDO  };
    union semun semun;

    // Generate unique keys for shared memory and semaphore
    if ((shmkey = ftok(".", 'A')) == -1 || (semkey = ftok(".", 'B')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Allocate shared memory
    if ((shmid = shmget(shmkey, SHM_SIZE, IPC_CREAT | 0644)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Allocate semaphore
    if ((semid = semget(semkey, 1, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphore
    semun.val = 1;
    if (semctl(semid, 0, SETVAL, semun) == -1) {
        perror("semctl");
        exit(1);
    }

    // Perform Interprocess communication
    if (fork()) { // Parent process
        printf("Parent process is waiting for input from child process...\n");
        semop(semid, &sembuf_present, 1); // Wait until child process signals semaphore
        printf("Parent process received the following message:\n%s", shm); // Print message from child process
        semop(semid, &sembuf_reset, 1); // Reset semaphore
    }
    else { // Child process
        sleep(1); // Wait for parent process to start waiting for message before sending it
        strcpy(shm, "Hello, parent process! This is your child process speaking.\n");
        semop(semid, &sembuf_present, 1); // Signal semaphore to notify parent process of new message
    }

    // Detach and destroy shared memory
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    // Destroy semaphore
    if (semctl(semid, 0, IPC_RMID, semun) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}