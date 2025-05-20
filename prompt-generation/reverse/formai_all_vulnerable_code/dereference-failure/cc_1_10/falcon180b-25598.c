//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define SIZE 100

typedef struct {
    int id;
    char name[20];
} Student;

int main() {
    int shmid;
    key_t key;
    Student *shm;

    // Create a shared memory segment
    key = ftok(".", 65);
    if ((shmid = shmget(key, SIZE * sizeof(Student), IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Initialize the shared memory segment
    if ((shm = (Student *)shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize the shared memory segment
    for (int i = 0; i < SIZE; i++) {
        sprintf(shm[i].name, "Student %d", i + 1);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        for (int i = 0; i < SIZE; i++) {
            shm[i].id = i + 1;
        }
        sleep(2);
    } else {
        // Parent process
        wait(NULL);
        for (int i = 0; i < SIZE; i++) {
            printf("Student %s: ID %d\n", shm[i].name, shm[i].id);
        }
    }

    // Detach the shared memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Delete the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}