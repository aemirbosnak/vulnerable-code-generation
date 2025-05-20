#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    union semun arg;
    int semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);

    char *str = (char*) shmat(shmid, NULL, 0);
    if (str == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    strcpy(str, "Hello World");

    struct sembuf sops[2];
    sops[0].sem_num = 0;
    sops[0].sem_op = -1;
    sops[0].sem_flg = SEM_UNDO;
    sops[1].sem_num = 0;
    sops[1].sem_op = 1;
    sops[1].sem_flg = SEM_UNDO;

    if (semop(semid, sops, 2) == -1) {
        perror("semop");
        exit(1);
    }

    printf("%s\n", str);

    shmdt(str);
    return 0;
}
