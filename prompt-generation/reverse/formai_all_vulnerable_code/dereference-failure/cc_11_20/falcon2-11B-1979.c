//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_BUF_SIZE 100

int main(int argc, char *argv[]) {
    int shmid;
    char *shared_buf;

    if (argc!= 2) {
        printf("Usage: %s <key>\n", argv[0]);
        return 1;
    }

    key_t key = atoi(argv[1]);

    if ((shmid = shmget(key, MAX_BUF_SIZE, 0666 | IPC_CREAT)) < 0) {
        perror("shmget");
        return 1;
    }

    shared_buf = (char *)shmat(shmid, NULL, 0);
    if (shared_buf == (char *)-1) {
        perror("shmat");
        return 1;
    }

    printf("Shared buffer address: %p\n", shared_buf);

    if (fork() == 0) {
        // Child process
        for (int i = 0; i < MAX_BUF_SIZE; i++) {
            shared_buf[i] = 'C';
        }

        if (shmdt(shared_buf) < 0) {
            perror("shmdt");
            return 1;
        }

        printf("Child process finished.\n");

        return 0;
    }

    if (fork() == 0) {
        // Child process
        for (int i = 0; i < MAX_BUF_SIZE; i++) {
            shared_buf[i] = 'C';
        }

        if (shmdt(shared_buf) < 0) {
            perror("shmdt");
            return 1;
        }

        printf("Child process finished.\n");

        return 0;
    }

    if (shmdt(shared_buf) < 0) {
        perror("shmdt");
        return 1;
    }

    printf("Parent process finished.\n");

    return 0;
}