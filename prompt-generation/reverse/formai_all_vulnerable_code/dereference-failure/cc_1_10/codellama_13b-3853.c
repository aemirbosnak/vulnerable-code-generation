//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: minimalist
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

int main() {
    int shmid;
    key_t key;
    char *shm, *s;
    int shmflg = 0666 | IPC_CREAT;

    if ((key = ftok(".", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    if ((shmid = shmget(key, SHMSZ, shmflg)) == -1) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    s = shm;

    strcpy(s, "Hello, World!");

    printf("Data written to shared memory: %s\n", s);

    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}