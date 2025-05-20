//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    int i;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *)-1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 0;
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1);

        // Modify shared memory segment
        for (i = 0; i < SIZE; i++) {
            shmptr[i] = i;
        }

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            printf("Error detaching from shared memory segment\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process
        sleep(2);

        // Attach to shared memory segment
        shmptr = shmat(shmid, NULL, 0);
        if (shmptr == (char *)-1) {
            printf("Error attaching to shared memory segment\n");
            exit(1);
        }

        // Display shared memory segment
        printf("Shared memory segment:\n");
        for (i = 0; i < SIZE; i++) {
            printf("%d ", shmptr[i]);
        }
        printf("\n");

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            printf("Error detaching from shared memory segment\n");
            exit(1);
        }

        // Remove shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error removing shared memory segment\n");
            exit(1);
        }

        // Wait for child process to exit
        wait(NULL);
    }

    return 0;
}