//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

typedef struct {
    int id;
    char name[30];
} student;

int main() {
    int shmid, i;
    key_t key;
    student *shm;

    key = ftok("shm_demo.c", 65);
    if ((shmid = shmget(key, sizeof(student) * SIZE, IPC_CREAT | 0666)) == -1) {
        printf("Error in shmget\n");
        exit(1);
    }

    shm = (student *) shmat(shmid, NULL, 0);
    for (i = 0; i < SIZE; i++) {
        sprintf(shm[i].name, "Student %d", i + 1);
        shm[i].id = i + 1;
    }

    printf("Parent process id: %d\n", getpid());
    for (i = 0; i < SIZE; i++) {
        printf("Name of student %d: %s\n", i + 1, shm[i].name);
    }

    if (fork() == 0) {
        for (i = 0; i < SIZE; i++) {
            shm[i].id = -1;
        }
        printf("Child process id: %d\n", getpid());
        for (i = 0; i < SIZE; i++) {
            printf("Name of student %d: %s\n", i + 1, shm[i].name);
        }
    } else {
        wait(NULL);
    }

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}