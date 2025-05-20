//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_SIZE 100
#define SEM_KEY 1234
#define SHM_KEY 5678

typedef struct {
    int count;
    char buffer[MAX_SIZE];
} shared_buffer;

sem_t sem;
int shmid;
shared_buffer *buffer;

void init_semaphore() {
    sem_init(&sem, 0, 1);
}

void destroy_semaphore() {
    sem_destroy(&sem);
}

int main() {
    int id;

    shmid = shmget(SHM_KEY, sizeof(shared_buffer), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("shmget error\n");
        exit(1);
    }

    buffer = (shared_buffer*) shmat(shmid, NULL, 0);
    if ((int) buffer == -1) {
        printf("shmat error\n");
        exit(1);
    }

    init_semaphore();

    for (int i = 0; i < 5; i++) {
        id = fork();
        if (id == 0) {
            char *message = "Hello, world!";
            strcpy(buffer->buffer, message);
            printf("Child %d wrote %s\n", getpid(), message);
            exit(0);
        }
    }

    for (int i = 0; i < 5; i++) {
        wait(NULL);
    }

    destroy_semaphore();

    shmdt(buffer);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}