//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SHM_KEY 0x12345678
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmaddr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: shmget() failed\n");
        exit(1);
    }

    // Attach shared memory segment to process address space
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        printf("Error: shmat() failed\n");
        exit(1);
    }

    // Write data to shared memory segment
    strcpy(shmaddr, "Hello, world!");

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        printf("Error: fork() failed\n");
        exit(1);
    }

    // Parent process writes to shared memory segment
    if (pid > 0) {
        sleep(2);
        strcpy(shmaddr, "Hello again, world!");
    }

    // Child process reads from shared memory segment
    else {
        sleep(1);
        printf("Shared memory: %s\n", shmaddr);
    }

    // Detach shared memory segment from process address space
    if (shmdt(shmaddr) == -1) {
        printf("Error: shmdt() failed\n");
        exit(1);
    }

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error: shmctl() failed\n");
        exit(1);
    }

    return 0;
}