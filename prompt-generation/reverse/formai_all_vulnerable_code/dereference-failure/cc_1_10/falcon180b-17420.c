//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shm = shmat(shmid, 0, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    for (int i = 0; i < SHM_SIZE; i++) {
        shm[i] = 0;
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process writes to shared memory
        for (int i = 0; i < SHM_SIZE; i++) {
            shm[i] = i;
        }
    } else {
        // Parent process reads from shared memory
        int sum = 0;
        for (int i = 0; i < SHM_SIZE; i++) {
            sum += shm[i];
        }
        printf("Sum: %d\n", sum);
    }

    // Detach shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}