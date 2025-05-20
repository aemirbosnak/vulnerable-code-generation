//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
} person_t;

int main(int argc, char *argv[]) {
    int shmid;
    key_t key;
    person_t *shared_memory;
    int i;

    // create shared memory segment
    key = ftok("shared_memory.txt", 65);
    shmid = shmget(key, sizeof(person_t) * 5, IPC_CREAT | 0777);
    if (shmid == -1) {
        printf("Error creating shared memory segment. ");
        exit(1);
    }

    // attach shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *) -1) {
        printf("Error attaching shared memory segment. ");
        exit(1);
    }

    // initialize shared memory
    for (i = 0; i < 5; i++) {
        strcpy(shared_memory[i].name, "John Doe");
        shared_memory[i].id = i + 1;
        shared_memory[i].age = 25;
    }

    // print shared memory
    printf("Shared memory initialized:\n");
    for (i = 0; i < 5; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", shared_memory[i].id, shared_memory[i].name, shared_memory[i].age);
    }

    // detach shared memory segment
    if (shmdt(shared_memory) == -1) {
        printf("Error detaching shared memory segment. ");
        exit(1);
    }

    // destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error destroying shared memory segment. ");
        exit(1);
    }

    return 0;
}