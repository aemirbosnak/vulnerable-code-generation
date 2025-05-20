//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} message_t;

int main() {
    int shmid;
    key_t key;
    int shared_fd;
    char *shm_ptr;
    pid_t pid;
    int status;
    message_t msg;

    // Create a shared memory segment
    key = ftok("shared_memory.c", 65);
    shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Shared memory create failed\n");
        exit(1);
    }

    // Attach to the shared memory segment
    shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void *) -1) {
        printf("Shared memory attach failed\n");
        exit(1);
    }

    // Initialize the shared data
    memset(shm_ptr, 0, sizeof(int));

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1);
        shm_ptr[0] = 42;
        printf("Child wrote %d to shared memory\n", shm_ptr[0]);
        exit(0);
    } else {
        // Parent process
        wait(&status);
        printf("Child exited with status %d\n", status);
    }

    return 0;
}