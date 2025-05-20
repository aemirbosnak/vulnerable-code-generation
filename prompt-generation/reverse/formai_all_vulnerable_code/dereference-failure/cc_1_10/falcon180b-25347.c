//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 100

// Structure for shared memory
struct shm_struct {
    int count;
    char buffer[SIZE];
};

int main() {
    int shmid, i;
    pid_t pid;
    key_t key = ftok("shm_file", 65);

    // Create shared memory segment
    shmid = shmget(key, sizeof(struct shm_struct), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    struct shm_struct *shm = (struct shm_struct *)shmat(shmid, NULL, 0);
    if (shm == (void *)-1) {
        printf("Error attaching shared memory segment\n");
        exit(2);
    }

    // Initialize shared memory
    shm->count = 0;
    for (i = 0; i < SIZE; i++) {
        shm->buffer[i] = '\0';
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(3);
    } else if (pid == 0) {
        // Child process writes to shared memory
        sleep(1);
        shm->count++;
        strcpy(shm->buffer, "Hello from child process!");
    } else {
        // Parent process reads from shared memory
        sleep(2);
        printf("Shared memory count: %d\n", shm->count);
        printf("Shared memory buffer: %s\n", shm->buffer);
    }

    // Detach shared memory segment from process
    if (shmdt(shm) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(4);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment\n");
        exit(5);
    }

    return 0;
}