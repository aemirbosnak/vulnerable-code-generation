//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
} Student;

int main() {
    int shmid, i;
    key_t key;
    Student *shmptr;
    pid_t pid;

    // create shared memory segment
    key = ftok(".",'s');
    shmid = shmget(key, sizeof(Student) * 5, 0666 | IPC_CREAT);
    if (shmid == -1) {
        fprintf(stderr, "shmget failed: %s\n", strerror(errno));
        exit(1);
    }

    // attach to shared memory segment
    shmptr = (Student *) shmat(shmid, NULL, 0);
    if (shmptr == (void *) -1) {
        fprintf(stderr, "shmat failed: %s\n", strerror(errno));
        exit(1);
    }

    // initialize shared memory segment
    for (i = 0; i < 5; i++) {
        shmptr[i].id = i;
        strcpy(shmptr[i].name, "Student ");
        shmptr[i].age = i + 1;
    }

    // fork child process
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        exit(1);
    } else if (pid == 0) {
        // child process
        sleep(2); // wait for parent process to complete initialization

        // access shared memory segment
        for (i = 0; i < 5; i++) {
            printf("Child: ID = %d, Name = %s, Age = %d\n", shmptr[i].id, shmptr[i].name, shmptr[i].age);
        }

        // detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            fprintf(stderr, "shmdt failed: %s\n", strerror(errno));
            exit(1);
        }

        // exit child process
        exit(0);
    } else {
        // parent process
        sleep(1); // wait for child process to access shared memory segment

        // update shared memory segment
        for (i = 0; i < 5; i++) {
            shmptr[i].age++;
        }

        // detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            fprintf(stderr, "shmdt failed: %s\n", strerror(errno));
            exit(1);
        }

        // wait for child process to exit
        wait(NULL);

        // remove shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            fprintf(stderr, "shmctl failed: %s\n", strerror(errno));
            exit(1);
        }
    }

    return 0;
}