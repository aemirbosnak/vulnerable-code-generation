//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define SHM_KEY (1234)
#define SHM_SIZE (1024)
#define MAX_CHILDREN (5)

int main(int argc, char *argv[]) {
    int shm_id;
    int *shm_ptr;
    int i, j, status;
    pid_t child_pid;

    shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);

    if (shm_id == -1) {
        printf("Error: failed to get shared memory segment\n");
        exit(1);
    }

    shm_ptr = (int *) shmat(shm_id, NULL, 0);

    if (shm_ptr == (void *) -1) {
        printf("Error: failed to attach shared memory segment\n");
        exit(1);
    }

    for (i = 0; i < MAX_CHILDREN; i++) {
        child_pid = fork();

        if (child_pid == -1) {
            printf("Error: failed to fork child process\n");
            exit(1);
        }

        if (child_pid == 0) {
            break;
        }
    }

    if (child_pid == 0) {
        // Child process
        shm_ptr[i] = getpid();

        for (j = 0; j < 10; j++) {
            printf("Child %d is writing to shared memory...\n", getpid());
            shm_ptr[i]++;
            sleep(1);
        }

        exit(0);
    }

    for (j = 0; j < 10; j++) {
        printf("Parent is reading from shared memory...\n");
        printf("Child %d wrote value %d\n", shm_ptr[i], shm_ptr[i]);
        sleep(1);
    }

    for (i = 0; i < MAX_CHILDREN; i++) {
        wait(&status);
    }

    shmdt(shm_ptr);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}