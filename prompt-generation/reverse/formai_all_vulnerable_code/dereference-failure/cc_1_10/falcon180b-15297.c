//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

// Define the semaphore
struct sembuf sem_op;

// Define the shared memory
char *shm_ptr;
int shm_id;

int main() {
    int shmid, semid, i;
    char input_buffer[MAX_SIZE];

    // Create the shared memory segment
    shmid = shmget(IPC_PRIVATE, MAX_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach the shared memory segment to the process
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize the shared memory segment
    for (i = 0; i < MAX_SIZE; i++) {
        shm_ptr[i] = 0;
    }

    // Create the semaphore
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error creating semaphore\n");
        exit(1);
    }

    // Initialize the semaphore
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = SEM_UNDO;
    if (semop(semid, &sem_op, 1) == -1) {
        printf("Error initializing semaphore\n");
        exit(1);
    }

    // Fork a child process
    int pid = fork();
    if (pid < 0) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process writes to the shared memory segment
        sprintf(input_buffer, "Child process writes to shared memory\n");
        strcpy(shm_ptr, input_buffer);

        // Child process signals the semaphore
        sem_op.sem_num = 0;
        sem_op.sem_op = 0;
        sem_op.sem_flg = SEM_UNDO;
        if (semop(semid, &sem_op, 1) == -1) {
            printf("Error signaling semaphore\n");
            exit(1);
        }
        exit(0);
    } else {
        // Parent process reads from the shared memory segment
        sleep(1);
        printf("Parent process reads from shared memory: %s", shm_ptr);

        // Parent process signals the semaphore
        sem_op.sem_num = 0;
        sem_op.sem_op = 0;
        sem_op.sem_flg = SEM_UNDO;
        if (semop(semid, &sem_op, 1) == -1) {
            printf("Error signaling semaphore\n");
            exit(1);
        }
        exit(0);
    }
}