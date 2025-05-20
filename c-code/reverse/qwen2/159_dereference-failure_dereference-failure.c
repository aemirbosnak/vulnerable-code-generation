#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
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

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        sleep(2);
        strcpy(str, "Hello from child!");
        semop(semid, &(struct sembuf){0, -1, 0}, 1);
        printf("%s\n", str);
        semop(semid, &(struct sembuf){0, +1, 0}, 1);
        shmdt(str);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        semop(semid, &(struct sembuf){0, -1, 0}, 1);
        printf("%s\n", str);
        semop(semid, &(struct sembuf){0, +1, 0}, 1);
        shmdt(str);
        wait(NULL);
        shmctl(shmid, IPC_RMID, NULL);
        semctl(semid, 0, IPC_RMID, NULL);
        exit(EXIT_SUCCESS);
    }
}
