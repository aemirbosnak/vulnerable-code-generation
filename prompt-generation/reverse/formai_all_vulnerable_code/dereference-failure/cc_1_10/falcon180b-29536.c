//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main() {
    int shmid, i;
    char *shmptr;
    key_t key = 1234;

    // Create shared memory segment
    if ((shmid = shmget(key, SIZE, IPC_CREAT | 0666)) < 0) {
        fprintf(stderr, "Error creating shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    // Attach to shared memory segment
    if ((shmptr = shmat(shmid, NULL, 0)) == (char *)-1) {
        fprintf(stderr, "Error attaching to shared memory segment: %s\n", strerror(errno));
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i) = '\0';
    }

    // Print initial state of shared memory segment
    printf("Initial state of shared memory segment:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%c", *(shmptr + i));
    }
    printf("\n");

    // Launch child process to modify shared memory segment
    if (fork() == 0) {
        // Child process
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            *(shmptr + i) = 'A';
        }
        printf("Child process completed modification of shared memory segment.\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);

        // Print final state of shared memory segment
        printf("Final state of shared memory segment:\n");
        for (i = 0; i < SIZE; i++) {
            printf("%c", *(shmptr + i));
        }
        printf("\n");

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            fprintf(stderr, "Error detaching from shared memory segment: %s\n", strerror(errno));
            exit(1);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            fprintf(stderr, "Error deleting shared memory segment: %s\n", strerror(errno));
            exit(1);
        }
    }

    return 0;
}