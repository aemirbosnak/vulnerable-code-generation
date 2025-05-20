//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main(int argc, char *argv[]) {
    int shmid;
    void *shm;
    char *shm_str;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    shm_str = shm;
    strcpy(shm_str, "Hello, world!");

    // Fork child process
    pid = fork();
    if (pid == 0) {
        // Child process writes to shared memory
        sleep(1);
        shm_str[0] = 'C';
        printf("Child wrote to shared memory.\n");
    } else {
        // Parent process reads from shared memory
        sleep(2);
        printf("Parent read from shared memory: %s\n", shm_str);
    }

    return 0;
}