//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100
#define SEM_KEY 0x1234
#define SEM_ID 0
#define SHM_KEY 0x5678
#define SHM_ID 0

int semid;
int shmid;
int *shared_memory;

void init_semaphore() {
    semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        printf("Error in creating semaphore\n");
        exit(1);
    }
}

void init_shared_memory() {
    shmid = shmget(SHM_KEY, SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error in creating shared memory\n");
        exit(1);
    }

    shared_memory = (int *) shmat(shmid, NULL, 0);
    if (shared_memory == (int *) -1) {
        printf("Error in attaching shared memory\n");
        exit(1);
    }
}

void write_to_shared_memory(int value) {
    if (sem_wait(semid) == -1) {
        printf("Error in waiting for semaphore\n");
        exit(1);
    }

    *shared_memory = value;

    if (sem_post(semid) == -1) {
        printf("Error in posting semaphore\n");
        exit(1);
    }
}

int read_from_shared_memory() {
    if (sem_wait(semid) == -1) {
        printf("Error in waiting for semaphore\n");
        exit(1);
    }

    int value = *shared_memory;

    if (sem_post(semid) == -1) {
        printf("Error in posting semaphore\n");
        exit(1);
    }

    return value;
}

int main() {
    init_semaphore();
    init_shared_memory();

    pid_t child_pid = fork();

    if (child_pid == -1) {
        printf("Error in forking\n");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        for (int i = 0; i < 5; i++) {
            write_to_shared_memory(i);
            printf("Child wrote %d to shared memory\n", i);
        }
    } else {
        // Parent process
        for (int i = 0; i < 10; i++) {
            int value = read_from_shared_memory();
            printf("Parent read %d from shared memory\n", value);
        }
    }

    return 0;
}