//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmptr;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE*sizeof(int), IPC_CREAT|0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void*)-1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        ((int*)shmptr)[i] = 0;
    }

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        for (i = 0; i < SIZE; i++) {
            ((int*)shmptr)[i] = i;
        }
        printf("Child process completed\n");
    } else {
        // Parent process
        sleep(2);
        for (i = 0; i < SIZE; i++) {
            printf("Parent process reading from shared memory: %d\n", ((int*)shmptr)[i]);
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

    return 0;
}