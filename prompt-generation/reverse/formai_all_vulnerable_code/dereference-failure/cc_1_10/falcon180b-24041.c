//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

int main() {
    int shmid, i;
    key_t key = 1234;
    char *shmaddr;
    pid_t pid;

    // create shared memory segment
    shmid = shmget(key, SIZE * sizeof(int), IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);

    if (shmaddr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmaddr + i) = 0;
    }

    // fork child process
    pid = fork();

    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid > 0) {
        // parent process
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            *(shmaddr + i) = i;
        }
    } else {
        // child process
        sleep(2);
        for (i = 0; i < SIZE; i++) {
            *(shmaddr + i) = SIZE - i - 1;
        }
    }

    // detach shared memory segment
    if (shmdt(shmaddr) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error destroying shared memory segment\n");
        exit(1);
    }

    return 0;
}