//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

int shmid;
char *shmptr;
key_t key;

void init_shared_memory(void) {
    int id = shmget(IPC_PRIVATE, SIZE * sizeof(char), IPC_CREAT | 0666);
    if (id == -1) {
        printf("Error creating shared memory segment!\n");
        exit(1);
    }
    shmid = id;
    shmptr = (char *) shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        printf("Error attaching to shared memory segment!\n");
        exit(1);
    }
    memset(shmptr, 0, SIZE * sizeof(char));
}

void print_shared_memory(void) {
    for (int i = 0; i < SIZE; i++) {
        printf("%c", shmptr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    init_shared_memory();
    int pid = fork();

    if (pid == 0) {
        for (int i = 0; i < SIZE; i++) {
            shmptr[i] = 'A' + i;
        }
        printf("Child wrote to shared memory.\n");
    } else {
        wait(NULL);
        printf("Parent reading from shared memory:\n");
        print_shared_memory();
    }

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}