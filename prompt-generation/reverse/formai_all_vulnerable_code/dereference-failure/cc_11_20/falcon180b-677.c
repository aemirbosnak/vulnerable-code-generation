//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define SIZE 10

int shmid;
int semid;
int *shm;

struct sembuf sb;

void main() {
    int i, j, pid;
    char *str = "Hello, World!";
    int fd[2];
    pid_t childpid;

    if (pipe(fd) == -1) {
        printf("Pipe Failed");
        exit(1);
    }

    if ((pid = fork()) == 0) {
        close(fd[0]);
        write(fd[1], str, strlen(str) + 1);
        close(fd[1]);
        exit(0);
    }

    close(fd[1]);
    read(fd[0], shm, SIZE);
    close(fd[0]);

    for (i = 0; i < SIZE; i++) {
        printf("%c", shm[i]);
    }

    printf("\n");

    if ((childpid = fork()) == 0) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < SIZE; j++) {
                shm[j] = shm[j] + 1;
            }
            sleep(1);
        }
        exit(0);
    }

    wait(NULL);

    for (i = 0; i < SIZE; i++) {
        printf("%c", shm[i]);
    }

    printf("\n");

    if (shmdt(shm) == -1) {
        printf("shmdt Failed");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("shmctl Failed");
        exit(1);
    }

    if (semctl(semid, 0, IPC_RMID) == -1) {
        printf("semctl Failed");
        exit(1);
    }

    exit(0);
}