//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

int main() {
    int shmid, shm_fd, i;
    char *shm_ptr;
    pid_t child_pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Shared memory creation failed\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void *) -1) {
        printf("Shared memory attachment failed\n");
        exit(2);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shm_ptr + i) = 0;
    }

    // Fork a child process
    child_pid = fork();
    if (child_pid == -1) {
        printf("Fork failed\n");
        exit(3);
    } else if (child_pid == 0) {
        // Child process
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            *(shm_ptr + i) = i + 1;
        }
        printf("Child process completed\n");
        exit(0);
    } else {
        // Parent process
        sleep(2);
        for (i = 0; i < SIZE; i++) {
            if (*(shm_ptr + i)!= i + 1) {
                printf("Interprocess communication failed\n");
                exit(4);
            }
        }
        printf("Interprocess communication succeeded\n");
        exit(0);
    }
}