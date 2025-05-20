//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int id;
    char name[10];
    int age;
} person;

int main() {
    int shmid, i;
    key_t key;
    person *ptr;
    pid_t pid;

    // Get a unique key
    key = ftok("shm.c", 65);

    // Create shared memory segment
    shmid = shmget(key, SIZE * sizeof(person), 0666 | IPC_CREAT);

    if (shmid == -1) {
        printf("Error: Failed to create shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    ptr = shmat(shmid, NULL, 0);

    if (ptr == (void *) -1) {
        printf("Error: Failed to attach to shared memory segment\n");
        exit(2);
    }

    // Initialize shared memory
    for (i = 0; i < SIZE; i++) {
        ptr[i].id = i + 1;
        strcpy(ptr[i].name, "Person ");
        ptr[i].age = 20 + i;
    }

    // Create child process
    pid = fork();

    if (pid == -1) {
        printf("Error: Failed to create child process\n");
        exit(3);
    } else if (pid == 0) {
        // Child process
        sleep(2);

        // Update shared memory
        for (i = 0; i < SIZE; i++) {
            ptr[i].name[6] = 'a' + i;
        }

        // Detach from shared memory segment
        if (shmdt(ptr) == -1) {
            printf("Error: Failed to detach from shared memory segment\n");
            exit(4);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process
        sleep(1);

        // Update shared memory
        for (i = 0; i < SIZE; i++) {
            ptr[i].age = 30 + i;
        }

        // Detach from shared memory segment
        if (shmdt(ptr) == -1) {
            printf("Error: Failed to detach from shared memory segment\n");
            exit(5);
        }

        // Wait for child process to exit
        waitpid(pid, NULL, 0);

        // Print updated shared memory
        ptr = shmat(shmid, NULL, 0);

        if (ptr == (void *) -1) {
            printf("Error: Failed to attach to shared memory segment\n");
            exit(6);
        }

        for (i = 0; i < SIZE; i++) {
            printf("ID: %d, Name: %s, Age: %d\n", ptr[i].id, ptr[i].name, ptr[i].age);
        }

        // Detach from shared memory segment
        if (shmdt(ptr) == -1) {
            printf("Error: Failed to detach from shared memory segment\n");
            exit(7);
        }
    }

    return 0;
}