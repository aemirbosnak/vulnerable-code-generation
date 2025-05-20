//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define KEY 0x12345
#define SIZE 100

int main() {
    int shmid, fd;
    char *shmptr;
    pid_t childpid;

    // Create shared memory segment
    if ((shmid = shmget(KEY, SIZE, IPC_CREAT | IPC_EXCL | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    if ((shmptr = shmat(shmid, NULL, 0)) == (char*)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory segment
    memset(shmptr, 0, SIZE);

    // Create child process
    if ((childpid = fork()) == 0) {
        // Child process writes to shared memory segment
        sprintf(shmptr, "Hello from child process!");
        exit(0);
    } else {
        // Parent process reads from shared memory segment
        waitpid(childpid, NULL, 0);
        printf("Message from child process: %s\n", shmptr);
    }

    // Detach shared memory segment from process
    if (shmdt(shmptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}