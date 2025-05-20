//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100
#define SEM_ID 0
#define SHM_ID 1
#define SEM_KEY 1234
#define SHM_KEY 5678

typedef struct {
    int count;
    char message[MAX_SIZE];
} shared_data_t;

int main() {
    int shm_id, sem_id;
    key_t shm_key = SHM_KEY, sem_key = SEM_KEY;
    shared_data_t *shm_ptr;
    int sem_value = 0;

    // Create shared memory segment
    shm_id = shmget(shm_key, sizeof(shared_data_t), IPC_CREAT | 0666);
    if (shm_id == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment
    shm_ptr = (shared_data_t *) shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(2);
    }

    // Initialize shared data
    shm_ptr->count = 0;
    strcpy(shm_ptr->message, "Romeo, wherefore art thou?");

    // Create semaphore
    sem_id = semget(sem_key, 1, IPC_CREAT | 0666);
    if (sem_id == -1) {
        printf("Error creating semaphore\n");
        exit(3);
    }

    // Initialize semaphore value
    semctl(sem_id, SEM_ID, SETVAL, sem_value);

    // Fork child process
    int pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(4);
    } else if (pid == 0) {
        // Child process
        sleep(2);
        shm_ptr->count++;
        strcpy(shm_ptr->message, "Juliet, I am here.");
        printf("Child: Message sent\n");
        exit(0);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent: Message received\n");
        exit(0);
    }

    return 0;
}