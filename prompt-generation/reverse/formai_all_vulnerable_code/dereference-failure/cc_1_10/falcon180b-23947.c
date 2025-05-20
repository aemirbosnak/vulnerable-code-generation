//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    pid_t pid;

    shmid = shmget(IPC_PRIVATE, SIZE, 0644 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    pid = fork();

    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        for (int i = 0; i < SIZE; i++) {
            shmptr[i] = 'A' + i;
        }
        printf("Child: Shared memory updated\n");
    } else {
        // Parent process
        sleep(2);
        for (int i = 0; i < SIZE; i++) {
            if (shmptr[i]!= 'A' + i) {
                printf("Parent: Shared memory not updated correctly\n");
                exit(1);
            }
        }
        printf("Parent: Shared memory updated correctly\n");
    }

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}