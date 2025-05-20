//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

// Function to create shared memory segment
int create_shm(int shmid, key_t key, int size) {
    int shmfd = shmget(key, size, IPC_CREAT | 0666);
    if (shmfd == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    void *shm = shmat(shmfd, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    memset(shm, 0, size);
    return shmid;
}

// Function to attach to shared memory segment
void *attach_shm(int shmid) {
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    return shm;
}

// Function to detach from shared memory segment
int detach_shm(void *shm) {
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }
    return 0;
}

// Function to destroy shared memory segment
int destroy_shm(int shmid) {
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }
    return 0;
}

// Function to send message to another process
int send_message(int shmid, int pid, char *message) {
    void *shm = attach_shm(shmid);
    strcpy(shm, message);
    detach_shm(shm);
    return 0;
}

// Function to receive message from another process
char *receive_message(int shmid) {
    void *shm = attach_shm(shmid);
    char *message = shm;
    detach_shm(shm);
    return message;
}

// Main function
int main(int argc, char *argv[]) {
    int shmid = create_shm(SHM_KEY, SHM_KEY, SHM_SIZE);
    printf("Shared memory segment created with ID: %d\n", shmid);

    int pid = fork();
    if (pid == 0) {
        char *message = "Hello from child process!";
        send_message(shmid, getppid(), message);
        exit(EXIT_SUCCESS);
    } else {
        char *message = receive_message(shmid);
        printf("Received message from child process: %s\n", message);
        destroy_shm(shmid);
        exit(EXIT_SUCCESS);
    }
    return 0;
}