//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct {
    char name[20];
    int age;
} Person;

#define MAX_PEOPLE 5

int main() {
    int shm_id, shm_size;
    char shm_name[20] = "shared_memory";
    Person *people;

    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, sizeof(Person) * MAX_PEOPLE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    people = (Person *) shmat(shm_id, NULL, 0);
    if ((int) people == -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    memset(people, 0, sizeof(Person) * MAX_PEOPLE);

    // Fill shared memory segment with data
    strcpy(people[0].name, "John");
    people[0].age = 25;

    strcpy(people[1].name, "Jane");
    people[1].age = 30;

    strcpy(people[2].name, "Bob");
    people[2].age = 40;

    strcpy(people[3].name, "Alice");
    people[3].age = 35;

    strcpy(people[4].name, "Charlie");
    people[4].age = 28;

    // Detach shared memory segment from process
    if (shmdt(people) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Delete shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        printf("Error deleting shared memory segment\n");
        exit(1);
    }

    return 0;
}