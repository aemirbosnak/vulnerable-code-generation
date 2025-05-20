//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_SIZE 10
#define SEM_ID 0x1234
#define SHM_KEY 0x5678

int shmid;
char *shmaddr;

union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};

int semid;

int main() {
    int i, j;
    int pid;
    int status;

    shmid = shmget(SHM_KEY, MAX_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Error: shmget failed\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        printf("Error: shmat failed\n");
        exit(2);
    }

    semid = semget(SEM_ID, 1, IPC_CREAT | 0666);
    if (semid < 0) {
        printf("Error: semget failed\n");
        exit(3);
    }

    semctl(semid, 0, SETVAL, 1);

    for (i = 0; i < 5; i++) {
        pid = fork();
        if (pid == 0) {
            for (j = 0; j < MAX_SIZE; j++) {
                shmaddr[j] = 'A' + i;
            }
            exit(0);
        } else {
            wait(&status);
        }
    }

    for (i = 0; i < 5; i++) {
        pid = fork();
        if (pid == 0) {
            for (j = 0; j < MAX_SIZE; j++) {
                shmaddr[j] = 'a' + i;
            }
            exit(0);
        } else {
            wait(&status);
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%c", shmaddr[i]);
    }

    return 0;
}