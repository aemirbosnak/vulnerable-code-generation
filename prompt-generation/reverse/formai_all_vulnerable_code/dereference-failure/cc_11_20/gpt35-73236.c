//FormAI DATASET v1.0 Category: Interprocess communication ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <errno.h>

#define SHM_SIZE 1024 // Size of shared memory segment

int main(int argc, char *argv[]) {

    int pid; // process id
    int shmid; // shared memory id
    key_t key; // shared memory key
    char *s; // pointer to shared memory segment
    int status; // wait status
    
    // Generate a shared memory key
    if ((key = ftok(".", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the process's address space
    if ((s = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    strcpy(s, "Hello world!"); // Write to the shared memory segment

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    else if (pid == 0) { // Child process

        printf("Child process:\n");
        printf("Message in shared memory: %s\n", s);

        char *c = s;

        // Upper case the message in the shared memory segment
        while (*c != '\0') {
            if (*c >= 'a' && *c <= 'z') {
                *c = *c - 32;
            }
            c++;
        }

        printf("Modified message in shared memory: %s\n", s);

        _exit(0); // Exit the child process
    }
    else { // Parent process

        printf("Parent process:\n");
        wait(&status); // Wait for child process to finish

        printf("Message in shared memory: %s\n", s);

        // Detach the shared memory segment from the process's address space
        if (shmdt(s) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Destroy the shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(1);
        }
    }

    return 0;
}