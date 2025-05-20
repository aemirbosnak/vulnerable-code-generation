//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100
#define KEY 1234

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

int main() {
    int shmid;
    key_t key = KEY;
    int i;
    Person *ptr;

    // Create shared memory segment
    shmid = shmget(key, SIZE * sizeof(Person), IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Failed to create shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment to process
    ptr = (Person *) shmat(shmid, NULL, 0);

    if (ptr == (void *) -1) {
        printf("Failed to attach shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        ptr[i].id = i;
        sprintf(ptr[i].name, "Person %d", i);
        ptr[i].age = i * 10;
    }

    // Fork child process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        sleep(1);

        // Modify shared memory segment
        for (i = 0; i < SIZE; i++) {
            ptr[i].age += 5;
        }

        printf("Child process modified shared memory segment.\n");
    } else {
        // Parent process
        sleep(2);

        // Display shared memory segment
        printf("Shared memory segment:\n");
        for (i = 0; i < SIZE; i++) {
            printf("ID: %d, Name: %s, Age: %d\n", ptr[i].id, ptr[i].name, ptr[i].age);
        }
    }

    return 0;
}