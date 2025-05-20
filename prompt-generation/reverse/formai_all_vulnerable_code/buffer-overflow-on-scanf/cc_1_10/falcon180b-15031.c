//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    char *shmaddr;
    int i;

    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("shmget failed\n");
        exit(1);
    }

    shmaddr = shmat(shmid, 0, 0);
    if (shmaddr == (char *) -1) {
        printf("shmat failed\n");
        exit(2);
    }

    printf("Enter %d integers:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", shmaddr + i * sizeof(int));
    }

    sleep(5);

    printf("Process 1 is summing...\n");
    for (i = 0; i < SIZE; i++) {
        shmaddr[i] = shmaddr[i] * 2;
    }

    printf("Process 1 finished summing.\n");

    sleep(5);

    printf("Process 1 is printing:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", shmaddr[i]);
    }
    printf("\n");

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}