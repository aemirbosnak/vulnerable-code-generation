//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/wait.h>

#define SHM_SIZE 128  // Size of shared memory
#define SEM_FULL "/sem_full"
#define SEM_EMPTY "/sem_empty"
#define SEM_MUTEX "/sem_mutex"

// Structure to hold data in shared memory
typedef struct {
    int buffer[10];  // Buffer for storing integers
    int count;       // Number of items in the buffer
} shared_data;

void producer(shared_data *data, sem_t *sem_full, sem_t *sem_empty, sem_t *sem_mutex) {
    for (int i = 0; i < 20; ++i) {
        sem_wait(sem_empty);  // Wait for an empty slot
        sem_wait(sem_mutex);  // Lock the buffer
        
        // Produce data
        data->buffer[data->count] = i;
        printf("Produced: %d\n", i);
        data->count++;
        
        sem_post(sem_mutex);   // Unlock the buffer
        sem_post(sem_full);    // Signal that an item has been produced
        
        sleep(rand() % 2);     // Sleep for a random time
    }
}

void consumer(shared_data *data, sem_t *sem_full, sem_t *sem_empty, sem_t *sem_mutex) {
    for (int i = 0; i < 20; ++i) {
        sem_wait(sem_full);   // Wait for an item to be produced
        sem_wait(sem_mutex);  // Lock the buffer
        
        // Consume data
        data->count--;
        int value = data->buffer[data->count];
        printf("Consumed: %d\n", value);
        
        sem_post(sem_mutex);   // Unlock the buffer
        sem_post(sem_empty);   // Signal that an item has been consumed
        
        sleep(rand() % 2);     // Sleep for a random time
    }
}

int main() {
    // Create shared memory
    int shm_fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);  // Set the size of the shared memory
    
    // Map shared memory
    shared_data *data = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    
    // Initialize shared data
    data->count = 0;
    
    // Create semaphores
    sem_t *sem_full = sem_open(SEM_FULL, O_CREAT, 0666, 0);
    sem_t *sem_empty = sem_open(SEM_EMPTY, O_CREAT, 0666, 10);
    sem_t *sem_mutex = sem_open(SEM_MUTEX, O_CREAT, 0666, 1);
    
    // Fork the process
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0) {
        // Child process: Consumer
        consumer(data, sem_full, sem_empty, sem_mutex);
    } else {
        // Parent process: Producer
        producer(data, sem_full, sem_empty, sem_mutex);
        
        // Wait for the child process to finish
        wait(NULL);
        
        // Clean up
        sem_close(sem_full);
        sem_close(sem_empty);
        sem_close(sem_mutex);
        shm_unlink("/my_shm");
        sem_unlink(SEM_FULL);
        sem_unlink(SEM_EMPTY);
        sem_unlink(SEM_MUTEX);
        
        printf("Producer finished.\n");
    }
    
    // Unmap shared memory
    munmap(data, SHM_SIZE);
    
    return 0;
}