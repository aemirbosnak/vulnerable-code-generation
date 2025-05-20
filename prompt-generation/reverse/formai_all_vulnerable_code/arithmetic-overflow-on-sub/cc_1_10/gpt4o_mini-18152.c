//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <time.h>

#define SHM_NAME "/my_shm"
#define SEM_FULL_NAME "/sem_full"
#define SEM_EMPTY_NAME "/sem_empty"
#define BUFFER_SIZE 10

typedef struct {
    int buffer[BUFFER_SIZE];
    int in;
    int out;
} shared_data;

void producer(shared_data *data, sem_t *sem_full, sem_t *sem_empty) {
    for (int i = 0; i < 20; i++) {
        sem_wait(sem_empty); // Wait for empty slot
        int num = rand() % 100; // Generate random number
        data->buffer[data->in] = num;
        printf("Produced: %d\n", num);
        data->in = (data->in + 1) % BUFFER_SIZE; // Circular buffer
        sem_post(sem_full); // Signal that data is available
        sleep(1); // Sleep for a short while
    }
}

void consumer(shared_data *data, sem_t *sem_full, sem_t *sem_empty) {
    for (int i = 0; i < 20; i++) {
        sem_wait(sem_full); // Wait for available data
        int num = data->buffer[data->out];
        printf("Consumed: %d\n", num);
        data->out = (data->out + 1) % BUFFER_SIZE; // Circular buffer
        sem_post(sem_empty); // Signal that a slot is empty
        sleep(2); // Sleep for a longer while
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    // Create shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(shared_data));
    shared_data *data = mmap(0, sizeof(shared_data), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // Initialize shared data
    data->in = 0;
    data->out = 0;

    // Create semaphores
    sem_t *sem_full = sem_open(SEM_FULL_NAME, O_CREAT, 0666, 0);
    sem_t *sem_empty = sem_open(SEM_EMPTY_NAME, O_CREAT, 0666, BUFFER_SIZE);

    // Fork the process to create producer and consumer
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process (Consumer)
        consumer(data, sem_full, sem_empty);
        exit(0);
    } else {
        // Parent process (Producer)
        producer(data, sem_full, sem_empty);
        wait(NULL); // Wait for child process to finish

        // Cleanup
        sem_close(sem_full);
        sem_close(sem_empty);
        sem_unlink(SEM_FULL_NAME);
        sem_unlink(SEM_EMPTY_NAME);
        munmap(data, sizeof(shared_data));
        shm_unlink(SHM_NAME);
    }

    return 0;
}