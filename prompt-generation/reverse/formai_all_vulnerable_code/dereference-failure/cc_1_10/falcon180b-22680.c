//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 100

typedef struct {
    int id;
    char name[20];
} student;

int main() {
    int shmid, i;
    key_t key;
    student *s;

    // Generate a unique key
    key = ftok("shm.c", 65);

    // Attach to the shared memory segment
    shmid = shmget(key, SIZE*sizeof(student), IPC_CREAT|0666);

    // Check if the segment was successfully created
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to the shared memory segment
    s = (student*) shmat(shmid, NULL, 0);

    // Initialize the shared memory segment
    for (i = 0; i < SIZE; i++) {
        s[i].id = -1;
        strcpy(s[i].name, " ");
    }

    // Fork a child process
    switch(fork()) {
        case -1: // Error forking
            printf("Error forking\n");
            exit(1);
        case 0: // Child process
            printf("Child process running\n");
            break;
        default: // Parent process
            printf("Parent process running\n");
            wait(NULL);
            break;
    }

    return 0;
}