//FormAI DATASET v1.0 Category: Interprocess communication ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main()
{
    pid_t pid;
    key_t key;
    int shmid;
    char *shm, *s;

    // Create a shared memory segment
    key = ftok(".", 's');
    shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the segment to our data space
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // This is the child process

        // Read data from the shared memory segment
        printf("Child process reading data from shared memory:\n");
        for (s = shm; *s != '\0'; s++)
            putchar(*s);
        putchar('\n');

        // Change the data
        printf("Child process changing data in shared memory:\n");
        char *message = "Hello from the child process!";
        strncpy(shm, message, BUFFER_SIZE);

        // Detach the segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit the child process
        exit(0);
    } else {
        // This is the parent process

        // Write data to the shared memory segment
        printf("Parent process writing data to shared memory:\n");
        char *message = "Hello from the parent process!";
        strncpy(shm, message, BUFFER_SIZE);

        // Wait for the child process to complete
        if (waitpid(pid, NULL, 0) == -1) {
            perror("waitpid");
            exit(1);
        }

        // Read data from the shared memory segment
        printf("Parent process reading data from shared memory:\n");
        for (s = shm; *s != '\0'; s++)
            putchar(*s);
        putchar('\n');

        // Detach the segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Delete the shared memory segment
        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}