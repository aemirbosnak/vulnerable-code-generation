//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>

#define SHM_NAME "/my_shared_memory"
#define SEM_PROD "/sem_prod"
#define SEM_CONS "/sem_cons"
#define BUFFER_SIZE 10

typedef struct {
    char buffer[BUFFER_SIZE];
    int in;
    int out;
} SharedData;

int main() {
    // Create shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(SharedData));
    SharedData* data = mmap(0, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    
    // Initialize shared data
    data->in = 0;
    data->out = 0;

    // Create semaphores
    sem_t* sem_prod = sem_open(SEM_PROD, O_CREAT, 0644, BUFFER_SIZE);
    sem_t* sem_cons = sem_open(SEM_CONS, O_CREAT, 0644, 0);

    // Fork a process
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    
    if (pid == 0) { // Child Process (Consumer)
        for (int i = 0; i < 10; i++) {
            sem_wait(sem_cons); // Wait for data
            char item = data->buffer[data->out];
            data->out = (data->out + 1) % BUFFER_SIZE;
            printf("Consumed: %c\n", item);
            sem_post(sem_prod); // Signal producer
        }
    } else { // Parent Process (Producer)
        for (char item = 'A'; item < 'K'; item++) {
            sem_wait(sem_prod); // Wait for free space
            data->buffer[data->in] = item;
            data->in = (data->in + 1) % BUFFER_SIZE;
            printf("Produced: %c\n", item);
            sem_post(sem_cons); // Signal consumer
        }
        wait(NULL); // Wait for child to finish
    }

    // Cleanup
    sem_close(sem_prod);
    sem_close(sem_cons);
    munmap(data, sizeof(SharedData));
    shm_unlink(SHM_NAME);
    sem_unlink(SEM_PROD);
    sem_unlink(SEM_CONS);
    
    return 0;
}