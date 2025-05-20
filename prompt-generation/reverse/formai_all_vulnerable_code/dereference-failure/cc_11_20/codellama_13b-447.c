//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main() {
    // Create a shared memory segment
    int shmid = shmget(IPC_PRIVATE, BUFFER_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process's address space
    char *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create a message queue
    int msqid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    // Fork a child process
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process
        // Read from shared memory
        char *buffer = shmaddr;
        while (1) {
            // Read a message from the shared memory
            int bytes_read = read(shmid, buffer, BUFFER_SIZE);
            if (bytes_read == -1) {
                perror("read");
                exit(1);
            }

            // Print the message
            printf("%s", buffer);

            // Wait for a signal from the parent process
            sigset_t sigmask;
            sigemptyset(&sigmask);
            sigaddset(&sigmask, SIGUSR1);
            sigwait(&sigmask, NULL);
        }
    } else if (child_pid > 0) {
        // Parent process
        // Write to shared memory
        char *buffer = shmaddr;
        while (1) {
            // Read a message from the standard input
            char message[BUFFER_SIZE];
            if (fgets(message, BUFFER_SIZE, stdin) == NULL) {
                perror("fgets");
                exit(1);
            }

            // Write the message to the shared memory
            int bytes_written = write(shmid, message, strlen(message));
            if (bytes_written == -1) {
                perror("write");
                exit(1);
            }

            // Send a signal to the child process
            kill(child_pid, SIGUSR1);
        }
    } else {
        perror("fork");
        exit(1);
    }

    // Clean up
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
    msgctl(msqid, IPC_RMID, NULL);

    return 0;
}