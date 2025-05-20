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

void init_semaphore(int sem_id) {
    union semun arg;
    arg.val = 1;
    semctl(sem_id, 0, SETVAL, arg);
}

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    char *str = (char*)shmat(shmid, NULL, 0);

    int sem_id = semget(key, 1, IPC_CREAT | 0666);
    init_semaphore(sem_id);

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        sleep(1);
        sem_wait(sem_id);
        strcpy(str, "Hello from child!");
        sem_post(sem_id);
    } else {
        sem_wait(sem_id);
        printf("%s\n", str);
        sem_post(sem_id);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
        semctl(sem_id, 0, IPC_RMID, NULL);
    }

    return 0;
}
