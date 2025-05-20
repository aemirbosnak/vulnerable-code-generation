//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // Get the process ID of the current process.
    pid_t pid = getpid();

    // Create a shared memory segment.
    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return EXIT_FAILURE;
    }

    // Attach the shared memory segment to the current process.
    int *shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (int *)-1) {
        perror("shmat");
        return EXIT_FAILURE;
    }

    // Fork a child process.
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    // The child process increments the shared memory variable.
    if (child_pid == 0) {
        *shmptr += 1;
        printf("Child process (PID %d) incremented the shared memory variable to %d.\n", pid, *shmptr);
        _exit(EXIT_SUCCESS);
    }

    // The parent process waits for the child process to finish.
    int status;
    waitpid(child_pid, &status, 0);

    // The parent process prints the shared memory variable.
    printf("Parent process (PID %d) read the shared memory variable as %d.\n", pid, *shmptr);

    // Detach the shared memory segment from the current process.
    if (shmdt(shmptr) == -1) {
        perror("shmdt");
        return EXIT_FAILURE;
    }

    // Destroy the shared memory segment.
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}