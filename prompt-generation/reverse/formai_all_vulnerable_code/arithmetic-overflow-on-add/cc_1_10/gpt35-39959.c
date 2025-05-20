//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

// Function prototypes
void handle_sigint(int);
void child_process(int, int);
void parent_process(int, int);

// Shared memory key
#define KEY 1234

// Struct to store data in shared memory
struct shared_data {
    int counter;
    char message[50];
};

int main() {

    // Declare variables for process IDs and shared memory ID
    pid_t pid_child, pid_parent;
    int shmid;
    struct shared_data *data;

    // Create shared memory segment
    shmid = shmget(KEY, sizeof(struct shared_data), IPC_CREAT | 0666);

    // Attach shared memory segment to process
    data = (struct shared_data*) shmat(shmid, NULL, 0);

    // Initialize counter and message in shared memory
    data->counter = 0;
    sprintf(data->message, "");

    // Initialize signal handlers
    signal(SIGINT, handle_sigint);

    // Create child process
    pid_child = fork();
    if (pid_child == 0) {
        // Child process
        child_process(shmid, getpid());
    }

    // Create parent process
    pid_parent = fork();
    if (pid_parent == 0) {
        // Parent process
        parent_process(shmid, getpid());
    }

    // Wait for child and parent processes to finish
    waitpid(pid_child, NULL, 0);
    waitpid(pid_parent, NULL, 0);

    // Detach and remove shared memory segment
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

void handle_sigint(int sig) {
    printf("Received SIGINT signal\n");
}

void child_process(int shmid, int pid) {
    struct shared_data *data;
    // Attach shared memory segment to child process
    data = (struct shared_data*) shmat(shmid, NULL, 0);
    printf("[Child PID %d] Started\n", pid);
    while (1) {
        // Increment counter and add message to shared memory
        data->counter++;
        sprintf(data->message, "This is message %d from child process", data->counter);
        printf("[Child PID %d] Counter: %d\n", pid, data->counter);
        // Wait for 1 second
        sleep(1);
    }
    // Detach shared memory segment from child process
    shmdt(data);

}

void parent_process(int shmid, int pid) {
    struct shared_data *data;
    // Attach shared memory segment to parent process
    data = (struct shared_data*) shmat(shmid, NULL, 0);
    printf("[Parent PID %d] Started\n", pid);
    while (1) {
        // Print message from shared memory
        printf("[Parent PID %d] Message: %s\n", pid, data->message);
        // Wait for 2 seconds
        sleep(2);
    }
    // Detach shared memory segment from parent process
    shmdt(data);

}