//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define MAX_SIZE 100

int main() {
    int shmid;
    char *shmptr;
    pid_t pid;
    int status;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, MAX_SIZE, IPC_CREAT | 0777);
    if (shmid < 0) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    memset(shmptr, 0, MAX_SIZE);

    // Fork process
    pid = fork();
    if (pid < 0) {
        printf("Error forking process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        for (int i = 0; i < MAX_SIZE; i++) {
            shmptr[i] = 'a' + i;
        }
        printf("Child process finished\n");
        exit(0);
    } else {
        // Parent process
        waitpid(pid, &status, 0);

        // Check if shared memory was modified by child process
        for (int i = 0; i < MAX_SIZE; i++) {
            if (shmptr[i]!= 'a' + i) {
                printf("Shared memory was modified by child process\n");
            }
        }

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            printf("Error detaching from shared memory segment\n");
            exit(1);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment\n");
            exit(1);
        }
    }

    return 0;
}