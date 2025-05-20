//FormAI DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

// Define the shared memory size
#define SHMSZ 27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    // Generate the shared memory key
    key = 5678;

    // Create the shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process' address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write to the shared memory segment
    s = shm;
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = '\0';

    // Create a child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process reads from shared memory and prints out the characters in uppercase
        char *shm = NULL;
        char *s = NULL;

        if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
            perror("shmget");
            exit(1);
        }

        if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
            perror("shmat");
            exit(1);
        }

        for (s = shm; *s != '\0'; s++)
            putchar(toupper(*s));
        putchar('\n');

        // Detach the shared memory segment from the process' address space
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }
        
        // Exit child process
        exit(0);
    } else if (pid > 0) {
        // Wait for child process to finish
        wait(NULL);

        // Parent process prints out the shared memory contents
        for (s = shm; *s != '\0'; s++)
            putchar(*s);
        putchar('\n');

        // Detach the shared memory segment from the process' address space and delete it
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }
        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }
    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}