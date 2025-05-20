//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY (key_t)1234
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmaddr;
    key_t key;

    key = SHM_KEY;
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    if (shmid == -1) {
        printf("Error creating shared memory.\n");
        exit(1);
    }

    shmaddr = shmat(shmid, NULL, 0);

    if (shmaddr == (char *)-1) {
        printf("Error attaching to shared memory.\n");
        exit(1);
    }

    printf("Shared memory successfully created and attached.\n");

    for (int i = 0; i < SHM_SIZE; i++) {
        shmaddr[i] = i;
    }

    printf("Data written to shared memory.\n");

    sleep(5);

    for (int i = 0; i < SHM_SIZE; i++) {
        if (shmaddr[i]!= i) {
            printf("Error: Data corrupted in shared memory.\n");
            exit(1);
        }
    }

    printf("Data verified in shared memory.\n");

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}