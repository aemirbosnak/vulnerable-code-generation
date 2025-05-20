//FormAI DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

// Define the shared memory key and size
#define SHM_KEY 123456
#define SHM_SIZE 8

// Define the signal handler for child process
void childSignalHandler(int sig) {
    printf("Child process received signal %d\n", sig);
}

int main() {
    // Create shared memory segment using shmget() system call
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if(shmid < 0) {
        perror("shmget failed!");
        exit(1);
    }

    // Attach shared memory segment using shmat() system call
    int *shm_addr = (int*) shmat(shmid, NULL, 0);
    if(shm_addr == (int*) -1) {
        perror("shmat failed!");
        exit(1);
    }

    // Initialize shared memory values
    *shm_addr = 0;

    // Create child process using fork() system call
    pid_t pid = fork();
    if(pid < 0) {
        perror("fork failed!");
        exit(1);
    }

    if(pid == 0) {
        // Child Process
        printf("Child process is running...\n");

        // Register signal handler for child process
        signal(SIGUSR1, childSignalHandler);

        // Wait for signal from parent process
        pause();

        // Update shared memory value
        *shm_addr = *shm_addr + 2;

        // Print updated shared memory value
        printf("Child process updated shared memory to %d\n", *shm_addr);

        // Detach shared memory segment using shmdt() system call
        if(shmdt(shm_addr) == -1) {
            perror("shmdt failed!");
            exit(1);
        }

        // Terminate child process
        exit(0);
    } else {
        // Parent Process
        printf("Parent process is running...\n");

        // Wait for a few seconds to allow child process to start
        sleep(3);

        // Send signal to child process
        if(kill(pid, SIGUSR1) == -1) {
            perror("kill failed!");
            exit(1);
        }

        // Wait for child process to terminate
        int status;
        pid_t cpid = waitpid(pid, &status, 0);
        if(cpid == -1) {
            perror("waitpid failed!");
            exit(1);
        }

        // Print final shared memory value
        printf("Parent process received updated shared memory value of %d from child process\n", *shm_addr);

        // Detach and remove shared memory segment
        if(shmdt(shm_addr) == -1) {
            perror("shmdt failed!");
            exit(1);
        }
        if(shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl failed!");
            exit(1);
        }

        // Terminate parent process
        exit(0);
    }
}