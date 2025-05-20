//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    int shmfd;
    char *shmptr;

    shmfd = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0777);
    if (shmfd == -1) {
        printf("Error in shmget\n");
        exit(1);
    }

    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0777);
    if (shmid == -1) {
        printf("Error in shmget\n");
        exit(1);
    }

    shmptr = (char *) shmat(shmid, NULL, 0);
    if ((int) shmptr == -1) {
        printf("Error in shmat\n");
        exit(1);
    }

    printf("Enter values for shared memory:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", shmptr + i * sizeof(int));
    }

    int pid = fork();

    if (pid == 0) {
        for (int i = 0; i < SIZE; i++) {
            printf("Child: %d\n", *(shmptr + i * sizeof(int)));
        }
    } else {
        wait(NULL);
    }

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);
    close(shmfd);

    return 0;
}