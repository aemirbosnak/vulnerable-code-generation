//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024
#define SHM_KEY 0x12345678

int main() {
    int shmid;
    void *shmptr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Sherlock Holmes: Error creating shared memory segment.\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *)-1) {
        printf("Sherlock Holmes: Error attaching to shared memory segment.\n");
        exit(1);
    }

    // Initialize shared data
    char *message = (char *)shmptr;
    strcpy(message, "The game is afoot!");

    // Fork a child process
    pid = fork();
    if (pid == 0) {
        // Child process
        sleep(1);
        strcpy(message, "Elementary, my dear Watson!");
        exit(0);
    } else if (pid < 0) {
        // Error forking
        printf("Sherlock Holmes: Error forking.\n");
        exit(1);
    } else {
        // Parent process
        wait(NULL);

        // Print updated message from shared memory
        printf("Sherlock Holmes: Message from shared memory: %s\n", message);
    }

    return 0;
}