//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 5678
#define SHM_SIZE 1024

// Structure for shared memory
struct shared_data {
    int pid;
    char message[SHM_SIZE];
};

int main(int argc, char *argv[]) {
    int shmid, pid;
    struct shared_data *shm_ptr;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shm_ptr = (struct shared_data *)shmat(shmid, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        shm_ptr->pid = getpid();
        sprintf(shm_ptr->message, "Hello, world! (PID %d)", shm_ptr->pid);
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        printf("Message from child: %s\n", shm_ptr->message);
    }

    // Detach shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}