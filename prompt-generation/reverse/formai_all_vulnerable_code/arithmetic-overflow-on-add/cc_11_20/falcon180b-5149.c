//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define MAX_PROCESSES 10
#define SEM_KEY 0x1234
#define SHM_KEY 0x5678

int main(int argc, char *argv[]) {
    int sem_id, shm_id;
    int i;
    char *shm_ptr;

    if (argc < 2) {
        printf("Usage: %s [process_id]\n", argv[0]);
        exit(1);
    }

    int process_id = atoi(argv[1]);

    if (process_id < 0 || process_id >= MAX_PROCESSES) {
        printf("Invalid process id: %d\n", process_id);
        exit(1);
    }

    sem_id = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (sem_id == -1) {
        printf("Failed to create semaphore\n");
        exit(1);
    }

    shm_id = shmget(SHM_KEY, sizeof(char) * 100, 0666 | IPC_CREAT);
    if (shm_id == -1) {
        printf("Failed to create shared memory\n");
        exit(1);
    }

    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *) -1) {
        printf("Failed to attach shared memory\n");
        exit(1);
    }

    sprintf(shm_ptr, "Process %d started", process_id);

    for (i = 0; i < 5; i++) {
        sem_wait(sem_id);
        sprintf(shm_ptr, "Process %d is waiting", process_id);
        sem_post(sem_id);
        usleep(100000); // Sleep for 100ms
    }

    if (shmdt(shm_ptr) == -1) {
        printf("Failed to detach shared memory\n");
        exit(1);
    }

    if (semctl(sem_id, 0, IPC_RMID) == -1) {
        printf("Failed to remove semaphore\n");
        exit(1);
    }

    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        printf("Failed to remove shared memory\n");
        exit(1);
    }

    return 0;
}