//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SEM_KEY 1234
#define SEM_NAME "/my_semaphore"
#define SHM_KEY 5678
#define SHM_NAME "/my_shared_memory"
#define BUFFER_SIZE 100

int main(int argc, char *argv[]) {
    int shmid, semid;
    char *shmaddr;
    int i;
    pid_t pid;

    // Create shared memory
    shmid = shmget(SHM_KEY, BUFFER_SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: cannot create shared memory\n");
        exit(1);
    }
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error: cannot attach shared memory\n");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < BUFFER_SIZE; i++) {
        *(shmaddr + i) = 0;
    }

    // Create semaphore
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("Error: cannot create semaphore\n");
        exit(1);
    }
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        printf("Error: cannot set semaphore value\n");
        exit(1);
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error: cannot fork\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1);
        for (i = 0; i < BUFFER_SIZE; i++) {
            *(shmaddr + i) = i + 1;
        }
        sleep(2);
    } else {
        // Parent process
        sleep(3);
        for (i = 0; i < BUFFER_SIZE; i++) {
            if (*(shmaddr + i)!= i + 1) {
                printf("Error: shared memory corrupted\n");
                exit(1);
            }
        }
    }

    return 0;
}