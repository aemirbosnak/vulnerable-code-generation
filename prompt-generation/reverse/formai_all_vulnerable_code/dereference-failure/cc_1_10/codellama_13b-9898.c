//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: Alan Turing
/*
 * C Interprocess Communication Example Program
 *
 * Author: Alan Turing
 * Date: 1948
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    // Create a shared memory segment
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0600);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the address space of the process
    void *shm_addr = shmat(shm_id, NULL, 0);
    if (shm_addr == (void *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process
        char *child_msg = "Hello, World!";
        strcpy(shm_addr, child_msg);
        printf("Child: %s\n", child_msg);
    } else {
        // Parent process
        wait(NULL);
        char *parent_msg = (char *)shm_addr;
        printf("Parent: %s\n", parent_msg);
    }

    // Detach the shared memory segment from the address space of the process
    if (shmdt(shm_addr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Destroy the shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}