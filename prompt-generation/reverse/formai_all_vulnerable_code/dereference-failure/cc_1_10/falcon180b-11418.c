//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

void *shmat(int shmid, const void *shmaddr, int shmflg);
int shmdt(const void *shmaddr);
int shmget(key_t key, size_t size, int shmflg);

int main() {
    int shmid;
    void *shmaddr;
    char *shmptr;
    int i;

    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    shmptr = (char *) shmaddr;
    for (i = 0; i < SHM_SIZE; i++) {
        shmptr[i] = 'A' + i % 26;
    }

    printf("Shared memory segment created and initialized\n");

    fork();

    if (fork() == 0) {
        shmptr = (char *) shmat(shmid, NULL, 0);
        if (shmptr == (void *) -1) {
            printf("Error attaching to shared memory segment\n");
            exit(1);
        }

        printf("Child process attached to shared memory segment\n");

        for (i = 0; i < SHM_SIZE; i++) {
            if (shmptr[i]!= 'A' + i % 26) {
                printf("Error: Shared memory segment not initialized correctly\n");
                exit(1);
            }
        }

        shmdt(shmptr);
        exit(0);
    } else {
        wait(NULL);
        shmdt(shmaddr);
        exit(0);
    }

    return 0;
}