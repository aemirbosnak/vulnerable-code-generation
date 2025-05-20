//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1024

typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
} Person;

int main(int argc, char *argv[]) {
    int shmid;
    Person *ptr;
    int i, n;
    char input[MAX_SIZE];

    // Get the shared memory identifier
    shmid = shmget(IPC_PRIVATE, sizeof(Person) * 5, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error: Unable to create shared memory.\n");
        exit(1);
    }

    // Attach the shared memory segment to the process
    ptr = (Person *) shmat(shmid, NULL, 0);
    if (ptr == (void *) -1) {
        printf("Error: Unable to attach shared memory.\n");
        exit(2);
    }

    // Initialize the shared memory segment
    for (i = 0; i < 5; i++) {
        sprintf(input, "Enter name for person %d: ", i+1);
        scanf("%s", ptr[i].name);
        ptr[i].id = i+1;
        ptr[i].age = 0;
    }

    // Print the shared memory segment
    for (i = 0; i < 5; i++) {
        printf("Person %d: %s, age %d\n", ptr[i].id, ptr[i].name, ptr[i].age);
    }

    // Detach the shared memory segment
    if (shmdt(ptr) == -1) {
        printf("Error: Unable to detach shared memory.\n");
        exit(3);
    }

    // Remove the shared memory identifier
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error: Unable to remove shared memory.\n");
        exit(4);
    }

    return 0;
}