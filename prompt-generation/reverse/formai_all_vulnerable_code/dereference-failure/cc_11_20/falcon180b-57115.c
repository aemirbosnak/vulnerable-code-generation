//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shm;
    int i;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, 0666);
    if (shmid < 0) {
        printf("Error: could not create shared memory segment\n");
        exit(1);
    }

    // attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (char*)-1) {
        printf("Error: could not attach to shared memory segment\n");
        exit(1);
    }

    // initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shm + i) = 0;
    }

    // fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // child process
        for (i = 0; i < SIZE; i++) {
            *(shm + i) = i + 1;
        }
        printf("Child process: shared memory segment initialized\n");
    } else if (pid > 0) {
        // parent process
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            if (*(shm + i)!= i + 1) {
                printf("Error: shared memory segment not initialized correctly\n");
                exit(1);
            }
        }
        printf("Parent process: shared memory segment initialized correctly\n");
    } else {
        // error forking process
        printf("Error: could not fork process\n");
        exit(1);
    }

    // detach from shared memory segment
    if (shmdt(shm) < 0) {
        printf("Error: could not detach from shared memory segment\n");
        exit(1);
    }

    // delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        printf("Error: could not delete shared memory segment\n");
        exit(1);
    }

    return 0;
}