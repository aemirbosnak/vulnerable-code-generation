//FormAI DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSIZE 100 // Define shared memory size

typedef struct {
    int num1; // Integer 1
    int num2; // Integer 2
} numbers;

int main() {
    pid_t pid; // Variable for process ID
    key_t key = 1234; // Shared memory key

    int shmid;
    void *shared_memory = (void *) 0;
    numbers *nums; // Pointer to structure

    shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666); // Create shared memory segment

    if (shmid == -1) { // Error in shared memory creation
        printf("shmget failed\n");
        exit(EXIT_FAILURE);
    }

    shared_memory = shmat(shmid, (void *) 0, 0); // Attach shared memory segment

    if (shared_memory == (void *) -1) { // Error in shared memory attachment
        printf("shmat failed\n");
        exit(EXIT_FAILURE);
    }

    nums = (numbers *) shared_memory; // Cast shared memory to structure pointer

    pid = fork(); // Create child process

    if (pid < 0) { // Error in forking
        printf("fork failed\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        printf("Enter two integers: ");
        scanf("%d %d", &nums->num1, &nums->num2); // Read two integers

        printf("Child process:\n");
        printf("Integer 1: %d\n", nums->num1);
        printf("Integer 2: %d\n", nums->num2);

        shmdt((void *) shared_memory); // Detach shared memory segment
        exit(EXIT_SUCCESS); // Exit child process
    } else { // Parent process
        wait(NULL); // Wait for child process to complete

        printf("Parent process:\n");
        printf("Sum: %d\n", nums->num1 + nums->num2); // Display sum of two integers

        shmdt((void *) shared_memory); // Detach shared memory segment
        shmctl(shmid, IPC_RMID, NULL); // Delete shared memory segment

        exit(EXIT_SUCCESS); // Exit parent process
    }
}