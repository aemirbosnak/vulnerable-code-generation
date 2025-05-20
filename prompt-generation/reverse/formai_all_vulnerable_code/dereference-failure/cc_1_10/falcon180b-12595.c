//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100
#define SHM_KEY 0x12345678

int main() {
    int shmid;
    char *shm;
    pid_t pid;

    shmid = shmget(SHM_KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("shmget failed\n");
        return 1;
    }

    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        printf("shmat failed\n");
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        // child process
        for (int i = 0; i < SIZE; i++) {
            shm[i] = 'A' + i;
        }
        sleep(2);
        for (int i = 0; i < SIZE; i++) {
            shm[i] = 'a' + i;
        }
    } else {
        // parent process
        sleep(1);
        for (int i = 0; i < SIZE; i++) {
            printf("%c", shm[i]);
        }
        printf("\n");
    }

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}