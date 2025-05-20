//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>

#define SHM_NAME "/my_shared_memory"
#define SEM_WRITE "/sem_write"
#define SEM_READ "/sem_read"
#define SIZE 256

void* writer(void* arg) {
    sem_t *sem_write = sem_open(SEM_WRITE, O_CREAT, 0644, 1);
    sem_t *sem_read = sem_open(SEM_READ, O_CREAT, 0644, 0);
    
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);
    char *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    char input[SIZE];
    while (1) {
        printf("Writer: Enter a message (type 'exit' to quit): ");
        fgets(input, SIZE, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        
        sem_wait(sem_write);
        snprintf(ptr, SIZE, "%s", input);
        sem_post(sem_read);

        if (strcmp(input, "exit") == 0) {
            break;
        }
    }

    munmap(ptr, SIZE);
    close(shm_fd);
    return NULL;
}

void* reader(void* arg) {
    sem_t *sem_write = sem_open(SEM_WRITE, 0);
    sem_t *sem_read = sem_open(SEM_READ, 0);
    
    int shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    char *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    while (1) {
        sem_wait(sem_read);
        printf("Reader: Received Message: %s\n", ptr);
        sem_post(sem_write);

        if (strcmp(ptr, "exit") == 0) {
            break;
        }
    }

    munmap(ptr, SIZE);
    close(shm_fd);
    return NULL;
}

int main() {
    pthread_t writer_thread, reader_thread;

    sem_unlink(SEM_WRITE);
    sem_unlink(SEM_READ);

    if (pthread_create(&writer_thread, NULL, writer, NULL) != 0) {
        perror("Failed to create writer thread");
        return 1;
    }

    if (pthread_create(&reader_thread, NULL, reader, NULL) != 0) {
        perror("Failed to create reader thread");
        return 1;
    }

    pthread_join(writer_thread, NULL);
    pthread_join(reader_thread, NULL);

    sem_unlink(SEM_WRITE);
    sem_unlink(SEM_READ);
    shm_unlink(SHM_NAME);
    
    return 0;
}