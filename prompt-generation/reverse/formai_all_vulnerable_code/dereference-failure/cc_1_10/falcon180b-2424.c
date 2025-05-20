//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100
#define KEY 0x12345

int main() {
    int shmid;
    char *shm;

    // create shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void*) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // initialize shared memory
    for (int i = 0; i < SIZE; i++) {
        *(shm + i) = 0;
    }

    // fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    }

    // parent process
    if (pid > 0) {
        printf("Parent process started\n");

        // wait for child process to finish
        int status;
        waitpid(pid, &status, 0);

        // detach from shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching from shared memory segment\n");
            exit(1);
        }

        // delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment\n");
            exit(1);
        }
    }
    // child process
    else {
        printf("Child process started\n");

        // modify shared memory
        for (int i = 0; i < SIZE; i++) {
            *(shm + i) = i;
        }

        // detach from shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching from shared memory segment\n");
            exit(1);
        }

        // exit child process
        exit(0);
    }

    return 0;
}