//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define MAX_SIZE 100
#define KEY 12345

int main() {
    int shmid, semid;
    char *shmptr;
    int i, n, semval;

    // Create shared memory segment
    shmid = shmget(KEY, MAX_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("shmget failed: %s\n", strerror(errno));
        exit(1);
    }

    // Attach shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void*) -1) {
        printf("shmat failed: %s\n", strerror(errno));
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < MAX_SIZE; i++) {
        *(shmptr + i) = 0;
    }

    // Create semaphore set
    semid = semget(KEY, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        printf("semget failed: %s\n", strerror(errno));
        exit(1);
    }

    // Initialize semaphore value
    semval = 0;
    if (semctl(semid, 0, SETVAL, semval) == -1) {
        printf("semctl failed: %s\n", strerror(errno));
        exit(1);
    }

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("fork failed: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        // Child process
        for (n = 0; n < 10; n++) {
            // Wait for semaphore to be available
            if (semop(semid, &(struct sembuf) {.sem_op = -1,.sem_flg = SEM_UNDO }, 1) == -1) {
                printf("semop failed: %s\n", strerror(errno));
                exit(1);
            }

            // Increment shared memory value
            *(shmptr + n) = n;

            // Release semaphore
            if (semop(semid, &(struct sembuf) {.sem_op = 1,.sem_flg = SEM_UNDO }, 1) == -1) {
                printf("semop failed: %s\n", strerror(errno));
                exit(1);
            }
        }
        exit(0);
    } else {
        // Parent process
        wait(NULL);

        // Verify shared memory value
        for (i = 0; i < MAX_SIZE; i++) {
            if (*(shmptr + i)!= i) {
                printf("Incorrect shared memory value\n");
                exit(1);
            }
        }
        printf("Shared memory value is correct\n");
    }

    return 0;
}