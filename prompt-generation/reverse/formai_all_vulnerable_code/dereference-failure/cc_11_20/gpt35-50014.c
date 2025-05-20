//FormAI DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>

#define SHM_SIZE 64

int main() {
    pid_t pid;
    key_t key;
    int shmid;
    char *shm_ptr;

    srand(time(NULL));

    // Generate a key for the shared memory segment
    if ((key = ftok(".", 'c')) == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a shared memory segment with the generated key
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT|IPC_EXCL|0666)) == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the parent
    if ((shm_ptr = shmat(shmid, NULL, 0)) == (void *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);

    } else if (pid == 0) {
        // Child Process

        int sum = 0;

        for (int i = 0; i < 5; i++) {
            int num = rand() % 10;
            sum += num;

            sprintf(shm_ptr, "%d", num);

            printf("[Child] Sent number: %d\n", num);

            sleep(1);
        }

        sprintf(shm_ptr, "%d", sum);

        printf("[Child] Sent sum: %d\n", sum);

        exit(EXIT_SUCCESS);

    } else {
        // Parent Process

        int total_sum = 0;

        for (int i = 0; i < 5; i++) {
            printf("[Parent] Waiting for number...\n");

            while (*shm_ptr == '\0') {
                sleep(1);
            }

            int num = atoi(shm_ptr);

            printf("[Parent] Received number: %d\n", num);

            total_sum += num;

            *shm_ptr = '\0';
        }

        printf("[Parent] Waiting for sum...\n");

        while (*shm_ptr == '\0') {
            sleep(1);
        }

        int sum = atoi(shm_ptr);

        printf("[Parent] Received sum: %d\n", sum);

        *shm_ptr = '\0';

        int status;
        wait(&status);

        printf("[Parent] Total sum: %d\n", total_sum);

        // Detach and remove the shared memory segment
        if (shmdt(shm_ptr) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}