//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100
#define KEY 0x12345678

int main() {
    int shmid;
    char *shmaddr;
    int *shmptr;

    // Create shared memory segment
    shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    shmptr = (int *) shmaddr;
    for (int i = 0; i < SIZE; i++) {
        *shmptr++ = 0;
    }

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1);
        for (int i = 0; i < SIZE; i++) {
            *shmptr++ = i;
        }
        printf("Child process finished\n");
        exit(0);
    } else {
        // Parent process
        sleep(2);
        for (int i = 0; i < SIZE; i++) {
            if (*shmptr++!= i) {
                printf("Error: shared memory not updated correctly\n");
                exit(1);
            }
        }
        printf("Interprocess communication successful\n");
        exit(0);
    }

    return 0;
}