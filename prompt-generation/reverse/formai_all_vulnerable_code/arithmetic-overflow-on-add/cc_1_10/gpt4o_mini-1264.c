//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <string.h>

#define SHM_SIZE 1024
#define SEM_KEY 1234
#define SHM_KEY 5678

void sem_wait(int semid) {
    struct sembuf p = {0, -1, 0};
    semop(semid, &p, 1);
}

void sem_signal(int semid) {
    struct sembuf v = {0, 1, 0};
    semop(semid, &v, 1);
}

int main() {
    int shmid;
    int semid;

    // Create shared memory
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Create semaphore
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid < 0) {
        perror("semget");
        exit(1);
    }

    // Initialize semaphore
    semctl(semid, 0, SETVAL, 1);

    // Attach shared memory
    int *counter = (int *)shmat(shmid, NULL, 0);
    if (counter == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    
    *counter = 0; // Initialize counter

    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { // Child process (Producer)
        for (int i = 0; i < 10; i++) {
            sem_wait(semid); // Wait on semaphore
            (*counter)++;     // Increment counter
            printf("Producer: Counter incremented to %d\n", *counter);
            sem_signal(semid); // Signal semaphore
            sleep(1); // Sleep to simulate processing time
        }
    } else { // Parent process (Consumer)
        for (int i = 0; i < 10; i++) {
            sem_wait(semid); // Wait on semaphore
            printf("Consumer: Current counter is %d\n", *counter);
            sem_signal(semid); // Signal semaphore
            sleep(2); // Sleep to simulate processing delay
        }
        wait(NULL); // Wait for child process to finish

        // Cleanup
        shmdt(counter);
        shmctl(shmid, IPC_RMID, NULL);
        semctl(semid, 0, IPC_RMID); // Remove semaphore
    }

    return 0;
}