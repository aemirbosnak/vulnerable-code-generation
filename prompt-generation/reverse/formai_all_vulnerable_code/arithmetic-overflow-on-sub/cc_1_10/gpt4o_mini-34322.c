//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <time.h>

#define SHM_SIZE 1024
#define MAX_NUM 100

struct shared_area {
    int buffer[MAX_NUM];
    int count;
};

void P(int semid) {
    struct sembuf p = {0, -1, 0};
    semop(semid, &p, 1);
}

void V(int semid) {
    struct sembuf v = {0, 1, 0};
    semop(semid, &v, 1);
}

int main() {
    int shmid, semid, i;
    struct shared_area *shm;
    key_t key = ftok("shmfile", 65);
    key_t semkey = ftok("semfile", 75);

    // Create shared memory segment
    shmid = shmget(key, sizeof(struct shared_area), 0666 | IPC_CREAT);
    shm = (struct shared_area *)shmat(shmid, NULL, 0);
    shm->count = 0;

    // Create a semaphore for synchronization
    semid = semget(semkey, 1, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 1); // set semaphore to 1

    srand(time(NULL)); // Seed for random number generation

    // Forking to create producer and consumer processes
    pid_t pid = fork();

    if (pid == 0) { // Child process (Producer)
        while (1) {
            P(semid); // acquire semaphore

            if (shm->count < MAX_NUM) {
                int num = rand() % 100; // produce random number
                shm->buffer[shm->count++] = num;
                printf("Produced: %d\n", num);
            } else {
                printf("Buffer full, waiting...\n");
            }

            V(semid); // release semaphore
            sleep(1); // sleep for a while
        }
    } else { // Parent process (Consumer)
        while (1) {
            P(semid); // acquire semaphore

            if (shm->count > 0) {
                int num = shm->buffer[--shm->count];
                printf("Consumed: %d\n", num);
            } else {
                printf("Buffer empty, waiting...\n");
            }

            V(semid); // release semaphore
            sleep(1); // sleep for a while
        }

        // Cleanup (Not reachable in this infinite loop, but important for practical scenarios)
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
        semctl(semid, 0, IPC_RMID);
    }

    return 0;
}