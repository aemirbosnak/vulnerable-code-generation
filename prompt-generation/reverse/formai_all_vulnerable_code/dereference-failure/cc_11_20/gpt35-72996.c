//FormAI DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

int main(void) {
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    // create shared memory segment
    key = 5678;
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment to address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write to shared memory segment
    s = shm;
    for (c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    // fork process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // child process reads from shared memory segment
        for (s = shm; *s != '\0'; s++) {
            putchar(*s);
        }
        putchar('\n');

        // detach from shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // destroy shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    } else {
        // parent process waits for child to finish
        int status;
        waitpid(pid, &status, 0);

        // detach from shared memory segment
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // destroy shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}