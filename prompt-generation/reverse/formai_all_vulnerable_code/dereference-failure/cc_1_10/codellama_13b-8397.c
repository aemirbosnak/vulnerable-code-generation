//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: interoperable
// IPC_example.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// Global variables
int shmid;
char *shm;

// Function to create a shared memory segment
int create_shm() {
    shmid = shmget(IPC_PRIVATE, 4096, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Error creating shared memory");
        exit(1);
    }
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *)-1) {
        perror("Error attaching shared memory");
        exit(1);
    }
    return 0;
}

// Function to write data to shared memory
int write_data(int value) {
    *(int *)shm = value;
    return 0;
}

// Function to read data from shared memory
int read_data() {
    int value = *(int *)shm;
    return value;
}

int main(int argc, char *argv[]) {
    // Create a shared memory segment
    create_shm();

    // Fork a child process
    int pid = fork();

    // Parent process
    if (pid > 0) {
        // Write data to shared memory
        write_data(10);

        // Wait for child process to complete
        wait(NULL);

        // Read data from shared memory
        int value = read_data();
        printf("Value from shared memory: %d\n", value);

        // Detach from shared memory
        shmdt(shm);

        // Delete shared memory segment
        shmctl(shmid, IPC_RMID, NULL);

        return 0;
    }

    // Child process
    else if (pid == 0) {
        // Read data from shared memory
        int value = read_data();
        printf("Value from shared memory: %d\n", value);

        // Write data to shared memory
        write_data(20);

        // Detach from shared memory
        shmdt(shm);

        return 0;
    }

    // Error
    else {
        perror("Error forking process");
        exit(1);
    }
}