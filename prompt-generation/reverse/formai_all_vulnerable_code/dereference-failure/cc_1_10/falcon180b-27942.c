//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 10

struct data {
    int id;
    char name[20];
};

int main() {
    int shmid, shmaddr;
    struct data *shmptr;

    if ((shmid = shmget(IPC_PRIVATE, SIZE * sizeof(struct data), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shmaddr = shmat(shmid, NULL, 0)) == (int) -1) {
        perror("shmat");
        exit(1);
    }

    shmptr = (struct data *) shmaddr;

    for (int i = 0; i < SIZE; i++) {
        shmptr[i].id = i + 1;
        strcpy(shmptr[i].name, "Student");
    }

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        for (int i = 0; i < SIZE; i++) {
            shmptr[i].id += 10;
            strcpy(shmptr[i].name, "Teacher");
        }
        printf("Child process completed\n");
        exit(0);
    } else {
        wait(NULL);
        for (int i = 0; i < SIZE; i++) {
            printf("ID = %d, Name = %s\n", shmptr[i].id, shmptr[i].name);
        }
    }

    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}