//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define TRUE 1
#define FALSE 0

#define MAX_SIZE 1000

#define SEM_KEY 1234
#define SHM_KEY 5678

#define SEM_NAME "my_semaphore"
#define SHM_NAME "my_shared_memory"

typedef struct {
    int count;
    char buffer[MAX_SIZE];
} shared_memory_t;

int main() {
    int shmid, semid;
    shared_memory_t *shared_memory;
    char *shm_ptr;

    // Initialize shared memory segment
    shmid = shmget(SHM_KEY, sizeof(shared_memory_t), IPC_CREAT | 0666);
    if (shmid == -1) {
        fprintf(stderr, "Error: could not create shared memory segment\n");
        return 1;
    }

    shared_memory = shmat(shmid, NULL, 0);
    if ((int) shared_memory == -1) {
        fprintf(stderr, "Error: could not attach to shared memory segment\n");
        return 1;
    }

    // Initialize semaphore
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        fprintf(stderr, "Error: could not create semaphore\n");
        return 1;
    }

    shared_memory->count = 0;
    shm_ptr = shared_memory->buffer;

    printf("Enter a string: ");
    scanf("%s", shm_ptr);

    // Increment semaphore
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        fprintf(stderr, "Error: could not set semaphore value\n");
        return 1;
    }

    return 0;
}