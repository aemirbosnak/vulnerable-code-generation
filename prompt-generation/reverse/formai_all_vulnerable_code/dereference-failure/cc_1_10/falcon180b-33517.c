//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 1024

typedef struct {
    int id;
    char name[MAX_SIZE];
} Person;

int main() {
    int shmid;
    Person *shm;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(Person), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = (Person *) shmat(shmid, NULL, 0);
    if ((int) shm == -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    shm->id = 1;
    strcpy(shm->name, "John Doe");

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        // Increment id and change name
        shm->id++;
        strcpy(shm->name, "Jane Doe");

        // Detach shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process
        // Wait for child process to exit
        wait(NULL);

        // Print updated shared memory segment
        printf("ID: %d\n", shm->id);
        printf("Name: %s\n", shm->name);

        // Detach shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment\n");
            exit(1);
        }
    }

    return 0;
}