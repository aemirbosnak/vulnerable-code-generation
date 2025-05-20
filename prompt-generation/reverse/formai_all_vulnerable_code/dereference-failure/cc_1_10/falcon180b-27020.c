//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 100

// Structure for shared memory segment
struct shm_struct {
    int count;
    char buffer[SIZE];
};

// Function to initialize shared memory segment
void init_shm(int shmid, char *message) {
    struct shm_struct *shmptr = (struct shm_struct *)shmat(shmid, NULL, 0);
    strcpy(shmptr->buffer, message);
    shmptr->count = 0;
}

// Function to increment count in shared memory segment
void increment_count(int shmid) {
    struct shm_struct *shmptr = (struct shm_struct *)shmat(shmid, NULL, 0);
    shmptr->count++;
}

// Function to print count in shared memory segment
void print_count(int shmid) {
    struct shm_struct *shmptr = (struct shm_struct *)shmat(shmid, NULL, 0);
    printf("Count: %d\n", shmptr->count);
}

// Function to exit and delete shared memory segment
void exit_shm(int shmid) {
    shmctl(shmid, IPC_RMID, NULL);
    exit(0);
}

int main() {
    int shmid;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(struct shm_struct), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Initialize shared memory segment
    init_shm(shmid, "Hello, world!");

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        // Increment count in shared memory segment
        increment_count(shmid);
        // Print count in shared memory segment
        print_count(shmid);
        // Exit and delete shared memory segment
        exit_shm(shmid);
    } else {
        // Parent process
        // Wait for child process to finish
        wait(NULL);
        // Print count in shared memory segment
        print_count(shmid);
        // Exit and delete shared memory segment
        exit_shm(shmid);
    }

    return 0;
}