//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100

// Structure for shared memory
struct data {
    int count;
    char message[SIZE];
};

// Function to initialize shared memory
void init_shm(key_t key, int shmid) {
    struct data *shmptr;

    // Attach to shared memory segment
    shmptr = (struct data *) shmat(shmid, NULL, 0);

    // Initialize shared memory
    shmptr->count = 0;
    strcpy(shmptr->message, "Hello, World!");

    // Detach from shared memory segment
    shmdt(shmptr);
}

// Function to write to shared memory
void write_to_shm(key_t key, int shmid) {
    struct data *shmptr;

    // Attach to shared memory segment
    shmptr = (struct data *) shmat(shmid, NULL, 0);

    // Increment count and write message
    shmptr->count++;
    sprintf(shmptr->message, "Hello, World! Count: %d", shmptr->count);

    // Detach from shared memory segment
    shmdt(shmptr);
}

// Function to read from shared memory
void read_from_shm(key_t key, int shmid) {
    struct data *shmptr;

    // Attach to shared memory segment
    shmptr = (struct data *) shmat(shmid, NULL, 0);

    // Print message and count
    printf("Message: %s\nCount: %d\n", shmptr->message, shmptr->count);

    // Detach from shared memory segment
    shmdt(shmptr);
}

int main() {
    key_t key;
    int shmid;

    // Generate unique key
    key = ftok("shm_example.c", 65);

    // Create shared memory segment
    shmid = shmget(key, sizeof(struct data), IPC_CREAT | 0666);

    // Initialize shared memory
    init_shm(key, shmid);

    // Fork child process
    int pid = fork();

    if (pid == 0) {
        // Child process
        write_to_shm(key, shmid);
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        read_from_shm(key, shmid);
    }

    return 0;
}