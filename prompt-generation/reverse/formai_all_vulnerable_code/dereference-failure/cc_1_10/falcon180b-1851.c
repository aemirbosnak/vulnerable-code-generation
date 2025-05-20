//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

typedef struct {
    int id;
    char name[20];
} person;

int main() {
    int shmid, i;
    key_t key;
    person *ptr;

    // create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(person) * SIZE, IPC_CREAT | 0600);
    if (shmid == -1) {
        printf("Error creating shared memory segment!\n");
        exit(1);
    }

    // attach shared memory segment to process address space
    ptr = (person*) shmat(shmid, NULL, 0);
    if ((int) ptr == -1) {
        printf("Error attaching shared memory segment!\n");
        exit(1);
    }

    // initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        ptr[i].id = i + 1;
        strcpy(ptr[i].name, "Person ");
        ptr[i].name[7] += i + 1;
    }

    // fork child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking child process!\n");
        exit(1);
    } else if (pid == 0) {
        // child process
        printf("Child process started...\n");

        // access shared memory segment
        ptr = (person*) shmat(shmid, NULL, 0);
        if ((int) ptr == -1) {
            printf("Error attaching shared memory segment!\n");
            exit(1);
        }

        // modify shared memory segment
        for (i = 0; i < SIZE; i++) {
            strcpy(ptr[i].name, "Child ");
            ptr[i].name[6] += i + 1;
        }

        // exit child process
        exit(0);
    } else {
        // parent process
        printf("Parent process started...\n");

        // wait for child process to exit
        wait(NULL);

        // detach shared memory segment from process address space
        if (shmdt(ptr) == -1) {
            printf("Error detaching shared memory segment!\n");
            exit(1);
        }

        // delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment!\n");
            exit(1);
        }
    }

    return 0;
}