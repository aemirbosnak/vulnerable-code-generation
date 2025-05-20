//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100

// structure for shared memory
typedef struct {
    int count;
    char message[100];
} shared_data;

int main() {
    int shmid;
    key_t key;
    shared_data *data;
    pid_t pid;

    // generate key
    key = 1234;

    // create shared memory segment
    shmid = shmget(key, SIZE, IPC_CREAT|0666);
    if (shmid == -1) {
        printf("Failed to create shared memory segment\n");
        exit(1);
    }

    // attach to shared memory segment
    data = (shared_data *) shmat(shmid, NULL, 0);
    if (data == (void *) -1) {
        printf("Failed to attach to shared memory segment\n");
        exit(1);
    }

    // initialize shared data
    data->count = 0;
    strcpy(data->message, "Hello, world!");

    // fork child process
    pid = fork();
    if (pid == -1) {
        printf("Failed to fork child process\n");
        exit(1);
    }

    // parent process
    if (pid > 0) {
        waitpid(pid, NULL, 0);
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
        exit(0);
    }

    // child process
    else {
        printf("Child process starting...\n");

        // modify shared data
        data->count++;
        strcpy(data->message, "Hello, child!");

        // detach from shared memory segment
        shmdt(data);

        // exit child process
        exit(0);
    }

    return 0;
}