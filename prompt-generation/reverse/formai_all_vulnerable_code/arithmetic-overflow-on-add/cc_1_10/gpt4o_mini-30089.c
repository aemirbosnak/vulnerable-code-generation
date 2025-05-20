//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define SHM_NAME "/magic_potion"
#define SEM_EMPTY_NAME "/sem_empty"
#define SEM_FULL_NAME "/sem_full"
#define MAX_POTIONS 5

typedef struct {
    int potion;
    int filled;
} PotionBox;

void producer() {
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(PotionBox));
    PotionBox *box = mmap(0, sizeof(PotionBox), PROT_WRITE, MAP_SHARED, shm_fd, 0);

    sem_t *sem_empty = sem_open(SEM_EMPTY_NAME, O_CREAT, 0666, 1);
    sem_t *sem_full = sem_open(SEM_FULL_NAME, O_CREAT, 0666, 0);

    printf("🎩 Producer is preparing magic potions! 🎩\n");
    for (int i = 0; i < MAX_POTIONS; i++) {
        sleep(1); // Simulating potion preparation
        int potion = i + 1; // Potion goes from 1 to MAX_POTIONS

        sem_wait(sem_empty); // Wait until there's space in the box
        printf("🧪 Producer created potion %d! 🧪\n", potion);
        box->potion = potion;
        box->filled = 1; // Mark box as filled
        sem_post(sem_full); // Signal that there's a potion

        printf("🎉 Potion %d is ready to be consumed! 🎉\n", potion);
    }

    // Signal the consumer to finish
    sem_wait(sem_empty);
    box->filled = 0; // Mark box as empty to signal completion
    sem_post(sem_full);

    munmap(box, sizeof(PotionBox));
    close(shm_fd);
    sem_close(sem_empty);
    sem_close(sem_full);
}

void consumer() {
    int shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    PotionBox *box = mmap(0, sizeof(PotionBox), PROT_READ, MAP_SHARED, shm_fd, 0);

    sem_t *sem_empty = sem_open(SEM_EMPTY_NAME, 0);
    sem_t *sem_full = sem_open(SEM_FULL_NAME, 0);

    printf("👩‍🔬 Consumer is ready to taste the potions! 👩‍🔬\n");
    while (1) {
        sem_wait(sem_full); // Wait for a potion to be available
        if (box->filled == 0) {
            printf("🎊 All potions have been consumed! 🎊\n");
            break;
        }
        printf("🍵 Consumer tasted potion %d! 🍵\n", box->potion);
        sem_post(sem_empty); // Signal that potion has been consumed
    }

    munmap(box, sizeof(PotionBox));
    close(shm_fd);
    sem_close(sem_empty);
    sem_close(sem_full);
}

int main() {
    // Forking the process for producer and consumer
    pid_t pid = fork();

    if (pid < 0) {
        perror("Failed to fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process - Consumer
        consumer();
    } else {
        // Parent process - Producer
        producer();
        wait(NULL); // Wait for consumer to finish
    }

    // Cleanup: Unlink shared memory and semaphores
    shm_unlink(SHM_NAME);
    sem_unlink(SEM_EMPTY_NAME);
    sem_unlink(SEM_FULL_NAME);

    printf("🌈 All potions have been shared! 🌈\n");
    return 0;
}