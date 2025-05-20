//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return EXIT_FAILURE;
    }

    // Attach the shared memory segment to the current process
    void *shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *)-1) {
        perror("shmat");
        return EXIT_FAILURE;
    }

    // Write to the shared memory segment
    char *message = "Hello, world!";
    memcpy(shmptr, message, strlen(message) + 1);

    // Detach the shared memory segment from the current process
    if (shmdt(shmptr) == -1) {
        perror("shmdt");
        return EXIT_FAILURE;
    }

    // Create a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    // Read from the shared memory segment in the child process
    if (child_pid == 0) {
        // Attach the shared memory segment to the child process
        void *child_shmptr = shmat(shmid, NULL, 0);
        if (child_shmptr == (void *)-1) {
            perror("shmat");
            return EXIT_FAILURE;
        }

        // Read from the shared memory segment
        char *child_message = (char *)child_shmptr;
        printf("Child process: %s\n", child_message);

        // Detach the shared memory segment from the child process
        if (shmdt(child_shmptr) == -1) {
            perror("shmdt");
            return EXIT_FAILURE;
        }
    }

    // Wait for the child process to complete
    if (child_pid != 0) {
        int status;
        if (waitpid(child_pid, &status, 0) == -1) {
            perror("waitpid");
            return EXIT_FAILURE;
        }
    }

    // Destroy the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}