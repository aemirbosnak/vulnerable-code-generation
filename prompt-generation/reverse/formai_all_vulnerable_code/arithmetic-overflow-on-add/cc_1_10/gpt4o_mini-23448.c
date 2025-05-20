//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>

#define SHM_NAME "/my_shared_memory"
#define SEM_WRITE "/my_semaphore_write"
#define SEM_READ "/my_semaphore_read"
#define BUFFER_SIZE 256
#define MAX_MESSAGES 10

void producer() {
    int shm_fd;
    char *shm_ptr;
    sem_t *sem_write, *sem_read;
    char message[BUFFER_SIZE];

    // Open shared memory
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, BUFFER_SIZE);
    shm_ptr = mmap(0, BUFFER_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // Open semaphores
    sem_write = sem_open(SEM_WRITE, O_CREAT, 0666, 1);
    sem_read = sem_open(SEM_READ, O_CREAT, 0666, 0);

    for (int i = 0; i < MAX_MESSAGES; i++) {
        printf("Producer: Enter message: ");
        fgets(message, BUFFER_SIZE, stdin);
        
        // Writing to shared memory
        sem_wait(sem_write);
        strcpy(shm_ptr, message);
        sem_post(sem_read);
    }

    // Clean up
    sem_close(sem_write);
    sem_close(sem_read);
    munmap(shm_ptr, BUFFER_SIZE);
    close(shm_fd);
}

void consumer() {
    int shm_fd;
    char *shm_ptr;
    sem_t *sem_write, *sem_read;

    // Open shared memory
    shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    shm_ptr = mmap(0, BUFFER_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    // Open semaphores
    sem_write = sem_open(SEM_WRITE, 0);
    sem_read = sem_open(SEM_READ, 0);

    for (int i = 0; i < MAX_MESSAGES; i++) {
        // Reading from shared memory
        sem_wait(sem_read);
        printf("Consumer: Received message: %s", shm_ptr);
        sem_post(sem_write);
    }

    // Clean up
    sem_close(sem_write);
    sem_close(sem_read);
    munmap(shm_ptr, BUFFER_SIZE);
    close(shm_fd);
}

int main() {
    pid_t pid;

    // Create the processes
    pid = fork();
    if (pid == 0) {
        // Child process (Consumer)
        consumer();
    } else {
        // Parent process (Producer)
        producer();
        wait(NULL);  // Wait for child to complete

        // Clean up shared memory and semaphores
        shm_unlink(SHM_NAME);
        sem_unlink(SEM_WRITE);
        sem_unlink(SEM_READ);
    }

    return 0;
}