//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: introspective
// IPC_Example.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Global variables
int shmid;
char *shared_memory;

// Function to create shared memory
int create_shared_memory() {
    // Create shared memory with key "1234" and size 1024
    shmid = shmget(1234, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    return shmid;
}

// Function to attach shared memory
int attach_shared_memory() {
    // Attach shared memory to the process
    shared_memory = shmat(shmid, 0, 0);
    if (shared_memory == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    return 0;
}

// Function to detach shared memory
int detach_shared_memory() {
    // Detach shared memory from the process
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(1);
    }
    return 0;
}

// Function to delete shared memory
int delete_shared_memory() {
    // Delete shared memory
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }
    return 0;
}

int main() {
    // Create shared memory
    create_shared_memory();

    // Attach shared memory
    attach_shared_memory();

    // Write data to shared memory
    strcpy(shared_memory, "Hello, world!");

    // Detach shared memory
    detach_shared_memory();

    // Delete shared memory
    delete_shared_memory();

    return 0;
}