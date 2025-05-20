//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main() {
    int shm_id;
    char* shm_addr;

    // Create shared memory segment
    shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT|0666);
    if (shm_id == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shm_addr = (char*)shmat(shm_id, NULL, 0);
    if (shm_addr == (void*)-1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    memset(shm_addr, 0, SHM_SIZE);

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1);

        // Increment counter in shared memory segment
        int* counter = (int*)shm_addr;
        (*counter)++;

        // Detach from shared memory segment
        if (shmdt(shm_addr) == -1) {
            printf("Error detaching from shared memory segment\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process
        sleep(2);

        // Check counter in shared memory segment
        int* counter = (int*)shm_addr;
        printf("Counter: %d\n", *counter);

        // Detach from shared memory segment
        if (shmdt(shm_addr) == -1) {
            printf("Error detaching from shared memory segment\n");
            exit(1);
        }

        // Wait for child process to exit
        wait(NULL);
    }

    return 0;
}