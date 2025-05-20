//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100
#define NUM_PROCESSES 3
#define KEY 1234

int main() {
    int shmid;
    int *shmptr;
    int i;
    pid_t pid;

    if ((shmid = shmget(KEY, SIZE * sizeof(int), IPC_CREAT | 0666)) == -1) {
        printf("Error in shmget()\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);

    if ((shmptr == (int *) -1)) {
        printf("Error in shmat()\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        shmptr[i] = 0;
    }

    for (i = 0; i < NUM_PROCESSES; i++) {
        if ((pid = fork()) == 0) {
            int *ptr;

            if ((ptr = shmat(shmid, NULL, 0)) == (int *) -1) {
                printf("Error in shmat()\n");
                exit(1);
            }

            printf("Child process %d is running\n", i);

            if (i == 0) {
                ptr[0] = 1;
            } else if (i == 1) {
                ptr[2] = 1;
            } else {
                ptr[4] = 1;
            }

            shmdt(ptr);
            exit(0);
        }
    }

    for (i = 0; i < NUM_PROCESSES; i++) {
        wait(NULL);
    }

    printf("All child processes have terminated\n");

    if (shmdt(shmptr) == -1) {
        printf("Error in shmdt()\n");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error in shmctl()\n");
        exit(1);
    }

    return 0;
}