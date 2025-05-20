//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

// Shared memory segment
#define SHM_SIZE 1024
int shm_id;
char* shm;

// Semaphore set
#define SEM_SET 1
int sem_id;

// Process IDs
int p1_id, p2_id;

int main() {
    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }
    shm = shmat(shm_id, NULL, 0);
    if (shm == (char*)-1) {
        perror("shmat");
        exit(1);
    }

    // Create semaphore set
    sem_id = semget(IPC_PRIVATE, SEM_SET, IPC_CREAT | 0666);
    if (sem_id == -1) {
        perror("semget");
        exit(1);
    }

    // Create processes
    p1_id = fork();
    if (p1_id == -1) {
        perror("fork");
        exit(1);
    }
    if (p1_id == 0) {
        // Child process
        char* msg = "Hello, world!";
        strcpy(shm, msg);
        printf("Child: %s\n", msg);
        sleep(1);
        exit(0);
    } else {
        // Parent process
        p2_id = fork();
        if (p2_id == -1) {
            perror("fork");
            exit(1);
        }
        if (p2_id == 0) {
            // Child process
            char* msg = "Hello, world!";
            strcpy(shm, msg);
            printf("Child: %s\n", msg);
            sleep(1);
            exit(0);
        } else {
            // Parent process
            wait(NULL);
            wait(NULL);
            printf("Parent: %s\n", shm);
            shmdt(shm);
            semctl(sem_id, 0, IPC_RMID, NULL);
            exit(0);
        }
    }
}