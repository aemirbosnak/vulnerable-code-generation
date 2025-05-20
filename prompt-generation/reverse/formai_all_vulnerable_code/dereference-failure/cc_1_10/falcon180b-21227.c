//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 100

int main() {
    int shmid;
    key_t key = 1234;
    char *shmaddr;
    pid_t pid;

    // create shared memory segment
    shmid = shmget(key, SIZE * sizeof(char), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: shmget() failed\n");
        exit(1);
    }

    // attach to shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char*)-1) {
        printf("Error: shmat() failed\n");
        exit(1);
    }

    // initialize shared memory segment
    strcpy(shmaddr, "Hello World!");

    // create child process
    pid = fork();
    if (pid == -1) {
        printf("Error: fork() failed\n");
        exit(1);
    } else if (pid == 0) {
        // child process
        sleep(1);
        printf("Child: %s\n", shmaddr);
        shmdt(shmaddr);
        exit(0);
    } else {
        // parent process
        wait(NULL);
        printf("Parent: %s\n", shmaddr);
        shmdt(shmaddr);
        exit(0);
    }
}