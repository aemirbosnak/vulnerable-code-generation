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
    char *str = (char*) shmat(shmid, NULL, 0);

    union semun arg;
    int semid = semget(key, 1, IPC_CREAT | 0666);
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);

    struct sembuf operations[2];
    operations[0].sem_num = 0;
    operations[0].sem_op = -1;
    operations[0].sem_flg = SEM_UNDO;
    operations[1].sem_num = 0;
    operations[1].sem_op = 1;
    operations[1].sem_flg = SEM_UNDO;

    semop(semid, operations, 2);

    strcpy(str, "Hello World");

    printf("Data written in memory: %s\n", str);

    shmdt(str);
    semctl(semid, 0, IPC_RMID, NULL);

    return 0;
}
