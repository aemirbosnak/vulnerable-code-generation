//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SIZE 10
#define PATH "/tmp/my_shm"

int main() {
    int shmid, fd, i;
    char *shm;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE*sizeof(int), IPC_CREAT|0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = shmat(shmid, 0, 0);
    if (shm == (void*)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory with values
    for (i = 0; i < SIZE; i++) {
        *(shm+i) = i;
    }

    // Fork child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(2);

        // Access shared memory segment
        for (i = 0; i < SIZE; i++) {
            *(shm+i) += 10;
        }

        // Detach shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process
        sleep(1);

        // Access shared memory segment
        for (i = 0; i < SIZE; i++) {
            printf("%d ", *(shm+i));
        }
        printf("\n");

        // Detach shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Wait for child process to exit
        waitpid(pid, NULL, 0);

        // Remove shared memory segment
        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}