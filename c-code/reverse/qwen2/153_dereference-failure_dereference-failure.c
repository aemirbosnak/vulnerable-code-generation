#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    char *str = (char*)shmat(shmid, NULL, 0);

    union semun arg;
    int semid = semget(key, 1, IPC_CREAT | 0666);
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);

    struct sembuf sops[2];
    sops[0].sem_num = 0;
    sops[0].sem_op = -1;
    sops[0].sem_flg = SEM_UNDO;
    sops[1].sem_num = 0;
    sops[1].sem_op = 1;
    sops[1].sem_flg = SEM_UNDO;

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        sleep(2);
        strcpy(str, "Hello from child!");
        printf("Child: %s\n", str);
        semop(semid, sops, 2);
        shmdt(str);
        exit(EXIT_SUCCESS);
    } else {
        semop(semid, sops, 2);
        printf("Parent: %s\n", str);
        shmdt(str);
        semctl(semid, 0, IPC_RMID, NULL);
        shmctl(shmid, IPC_RMID, NULL);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}
