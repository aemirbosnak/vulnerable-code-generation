//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    pid_t childpid;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // initialize shared memory segment
    memset(shmptr, 0, SIZE);

    // fork child process
    childpid = fork();
    if (childpid == -1) {
        printf("Error forking child process\n");
        exit(1);
    }

    // child process writes to shared memory segment
    if (childpid == 0) {
        char *childptr = shmptr;
        strcpy(childptr, "Hello from child process!");
    }

    // parent process reads from shared memory segment
    else {
        wait(NULL);
        char *parentptr = shmptr;
        printf("Message from child process: %s\n", parentptr);
    }

    // detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error deleting shared memory segment\n");
        exit(1);
    }

    return 0;
}