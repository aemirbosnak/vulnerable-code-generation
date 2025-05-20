//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
} person_t;

person_t* shared_memory;
int shmid;
key_t key;

void init_shared_memory() {
    shmid = shmget(IPC_PRIVATE, sizeof(person_t) * 10, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: could not create shared memory segment\n");
        exit(1);
    }

    shared_memory = (person_t*) shmat(shmid, NULL, 0);
    if (shared_memory == (void*) -1) {
        printf("Error: could not attach to shared memory segment\n");
        exit(1);
    }

    bzero(shared_memory, sizeof(person_t) * 10);

    key = ftok(".", 'a');
}

void add_person(person_t* person) {
    int i;
    for (i = 0; i < 10; i++) {
        if (shared_memory[i].id == -1) {
            shared_memory[i] = *person;
            return;
        }
    }

    printf("Error: shared memory is full\n");
}

void get_person(int id, person_t* person) {
    int i;
    for (i = 0; i < 10; i++) {
        if (shared_memory[i].id == id) {
            *person = shared_memory[i];
            return;
        }
    }

    printf("Error: person not found\n");
}

void delete_person(int id) {
    int i;
    for (i = 0; i < 10; i++) {
        if (shared_memory[i].id == id) {
            shared_memory[i].id = -1;
            return;
        }
    }

    printf("Error: person not found\n");
}

int main() {
    init_shared_memory();

    person_t new_person = {0, "John Doe", 25};
    add_person(&new_person);

    person_t retrieved_person;
    get_person(0, &retrieved_person);
    printf("Name: %s\nAge: %d\n", retrieved_person.name, retrieved_person.age);

    delete_person(0);

    return 0;
}