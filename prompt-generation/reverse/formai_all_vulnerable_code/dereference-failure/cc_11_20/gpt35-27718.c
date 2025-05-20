//FormAI DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMSZ 27

int main(int argc, char *argv[])
{
    int shmid;
    key_t key;
    char *shm, *s;

    // generate key for shared memory segment
    key = 5678;

    // create shared memory segment with given key
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment to process address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // write message to shared memory
    strcpy(shm, "Hello, world!");

    // fork new process
    int pid = fork();

    // error occurred
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    // child process
    else if (pid == 0) {

        // wait for parent process to write message
        while (*shm != '*')
            sleep(1);

        // read message from shared memory segment
        for (s = shm; *s != NULL; s++)
            putchar(*s);
        putchar('\n');

        // update message in shared memory segment
        *shm = '*';

        // detach shared memory segment from process address space
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        exit(0);
    }

    // parent process
    else {

        // wait for child process to read message
        sleep(2);

        // update message in shared memory segment
        for (s = shm; *s != NULL; s++)
            *s = '*';

        // wait for child process to finish
        wait(NULL);

        // detach shared memory segment from process address space
        if (shmdt(shm) == -1) {
            perror("shmdt");
            exit(1);
        }

        // remove shared memory segment
        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}