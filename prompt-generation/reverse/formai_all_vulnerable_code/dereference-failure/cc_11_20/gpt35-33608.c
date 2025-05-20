//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 27

int main(int argc, char *argv[])
{
    int shmid, pid1, pid2, i;
    char c;
    key_t key;
    char *shm, *s;

    // create a shared memory segment
    key = 5678;
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment to the process's address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // fork the first child process
    if ((pid1 = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    else if (pid1 == 0) {  // child process 1
        s = shm;
        for (c = 'a'; c <= 'z'; c++)  // write to shared memory
            *s++ = c;
        *s = '\0';
        exit(0);
    }

    // fork the second child process
    if ((pid2 = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    else if (pid2 == 0) {  // child process 2
        s = shm;
        while (*s == '\0')  // wait for a character to be written to the shared memory
            ;
        putchar(*s);
        putchar('\n');
        exit(0);
    }

    // wait for both child processes to finish
    for (i = 0; i < 2; i++) {
        wait(NULL);
    }

    // detach the shared memory segment from the process's address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}