//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    key_t key;
    void *shmaddr;
    int i;

    // generate unique key
    key = ftok("shared_memory.c", 65);

    // create shared memory segment
    shmid = shmget(key, SIZE * sizeof(int), IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // attach shared memory segment to process address space
    shmaddr = shmat(shmid, NULL, 0);

    if (shmaddr == (void*)-1) {
        printf("Error attaching shared memory segment.\n");
        exit(1);
    }

    // initialize shared memory with random values
    for (i = 0; i < SIZE; i++) {
        ((int*)shmaddr)[i] = rand() % 100;
    }

    // fork child process
    pid_t child_pid = fork();

    if (child_pid == -1) {
        printf("Error forking child process.\n");
        exit(1);
    }

    if (child_pid == 0) {
        // child process

        // wait for parent process to update shared memory
        sleep(1);

        // print updated shared memory values
        for (i = 0; i < SIZE; i++) {
            printf("%d ", ((int*)shmaddr)[i]);
        }

    } else {
        // parent process

        // update shared memory values
        for (i = 0; i < SIZE; i++) {
            ((int*)shmaddr)[i] = rand() % 100;
        }

        // wait for child process to print shared memory values
        wait(NULL);
    }

    return 0;
}