//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

// Define the number of processes and the key for the shared memory segment
#define NUM_PROCESSES 3
#define KEY 1234

// Define the structure of the shared memory segment
typedef struct {
    int value;
    int turn;
} shared_memory;

// Define the semaphore operations
union semun {
    int val;               /* Value for SETVAL */
    struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
    struct seminfo *__buf; /* Buffer for IPC_INFO */
};

// Main function
int main() {
    // Create the shared memory segment
    int shmid = shmget(KEY, sizeof(shared_memory), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the current process
    shared_memory *shared_mem = (shared_memory *)shmat(shmid, NULL, 0);
    if (shared_mem == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create the semaphore set
    int semid = semget(KEY, 2, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Initialize the semaphores
    union semun semun;
    semun.val = 1;
    if (semctl(semid, 0, SETVAL, semun) == -1) {
        perror("semctl");
        exit(1);
    }
    semun.val = 0;
    if (semctl(semid, 1, SETVAL, semun) == -1) {
        perror("semctl");
        exit(1);
    }

    // Create the child processes
    for (int i = 0; i < NUM_PROCESSES; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Child process
            while (1) {
                // Wait for turn
                struct sembuf sembuf;
                sembuf.sem_num = 0;
                sembuf.sem_op = -1;
                sembuf.sem_flg = 0;
                if (semop(semid, &sembuf, 1) == -1) {
                    perror("semop");
                    exit(1);
                }

                // Critical section
                shared_mem->value++;
                printf("Process %d: %d\n", i, shared_mem->value);

                // Signal turn
                sembuf.sem_num = 1;
                sembuf.sem_op = 1;
                sembuf.sem_flg = 0;
                if (semop(semid, &sembuf, 1) == -1) {
                    perror("semop");
                    exit(1);
                }
            }
        }
    }

    // Parent process
    while (1) {
        sleep(1);
    }

    // Detach the shared memory segment from the current process
    if (shmdt(shared_mem) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    // Remove the semaphore set
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(1);
    }

    return 0;
}