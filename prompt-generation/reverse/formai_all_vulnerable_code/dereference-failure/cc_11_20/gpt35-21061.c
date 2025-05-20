//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
    int shmid;
    pid_t pid;
    key_t key;
    char *shm, *s;

    key = 567; // defining key for shared memory

    // Creating shared memory segment
    shmid = shmget(key, 1024, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Attaching shared memory segment
    shm = shmat(shmid, NULL, 0);

    if (shm == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Writing into shared memory
    s = shm;
    for (char c = 'a'; c <= 'z'; c++)
        *s++ = c;

    *s = '\0';

    // Forking a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {  /* Child Process */
        printf("Child process read: ");

        // Reading from shared memory in child process
        s = shm;
        while (*s != '\0')
            putchar(*s++);

        putchar('\n');

        // Detaching shared memory segment from child process
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        exit(0);
    }
    else { /* Parent Process */
        printf("Parent process waiting for child process to complete...\n");
        wait(NULL);

        // Reading from shared memory in parent process
        printf("Parent process read: ");
        s = shm;
        while (*s != '\0')
            putchar(*s++);

        putchar('\n');

        // Detaching and removing shared memory
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }

    }

    return 0;
}