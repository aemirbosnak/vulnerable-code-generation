//FormAI DATASET v1.0 Category: Interprocess communication ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
    int shmid;
    key_t key = 1234;
    int *data;

    shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    data = (int*) shmat(shmid, NULL, 0);
    if (data == (int*) -1) {
        perror("shmat");
        exit(1);
    }

    *data = 0;

    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process: waiting for data...\n");
        while (*data == 0) {}
        printf("Child process received: %d\n", *data);
        *data *= 2;
        _exit(0);
    } else if (pid > 0) {
        printf("Parent process: sharing data...\n");
        sleep(1);
        *data = 42;
        printf("Parent process sent: %d\n", *data);
        wait(NULL);
        printf("Parent process received: %d\n", *data);
    } else {
        perror("fork");
        exit(1);
    }

    if (shmdt(data) < 0) {
        perror("shmdt");
        exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}