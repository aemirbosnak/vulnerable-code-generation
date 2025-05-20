//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main() {
    // Create a shared memory segment for communication
    int shmid;
    char *shm_ptr;
    key_t key = ftok("ipc_example", 42);
    shmid = shmget(key, sizeof(char), 0666 | IPC_CREAT);
    shm_ptr = shmat(shmid, NULL, 0);
    
    // Create a semaphore to ensure synchronization
    int semid;
    semid = semget(key, 1, 0666 | IPC_CREAT);
    
    // Initialize semaphore
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        fprintf(stderr, "Failed to initialize semaphore\n");
        return 1;
    }
    
    // Process 1
    pid_t pid1 = fork();
    if (pid1 < 0) {
        fprintf(stderr, "Failed to fork process\n");
        return 1;
    }
    else if (pid1 == 0) {
        // Process 1: send message
        printf("Process 1 sending message: Hello from process 1\n");
        write(1, "Hello from process 1", 18);
        
        // Wait for semaphore
        if (semctl(semid, 0, IPC_RMID) == -1) {
            fprintf(stderr, "Failed to delete semaphore\n");
            return 1;
        }
        
        // Exit process 1
        exit(0);
    }
    
    // Process 2
    pid_t pid2 = fork();
    if (pid2 < 0) {
        fprintf(stderr, "Failed to fork process\n");
        return 1;
    }
    else if (pid2 == 0) {
        // Process 2: receive message
        printf("Process 2 receiving message: ");
        read(0, shm_ptr, sizeof(char));
        printf("Process 2 received message: %s\n", shm_ptr);
        
        // Wait for semaphore
        if (semctl(semid, 0, IPC_RMID) == -1) {
            fprintf(stderr, "Failed to delete semaphore\n");
            return 1;
        }
        
        // Exit process 2
        exit(0);
    }
    
    // Wait for process 2 to finish
    int status;
    if (wait(&status) == -1) {
        fprintf(stderr, "Failed to wait for process 2\n");
        return 1;
    }
    
    // Cleanup shared memory and semaphore
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        fprintf(stderr, "Failed to delete shared memory segment\n");
        return 1;
    }
    if (semctl(semid, 0, IPC_RMID) == -1) {
        fprintf(stderr, "Failed to delete semaphore\n");
        return 1;
    }
    
    return 0;
}