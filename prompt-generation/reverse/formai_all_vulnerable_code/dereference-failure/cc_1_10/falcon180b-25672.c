//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define TRUE 1
#define FALSE 0
#define SHM_KEY 0x1234567
#define SHM_SIZE 1024

typedef struct {
    int id;
    char name[32];
} person_t;

void read_from_shm(int shmid) {
    person_t *person = (person_t *)shmat(shmid, NULL, 0);

    if (person == (void *)-1) {
        printf("Error attaching to shared memory.\n");
        exit(1);
    }

    printf("Name: %s\n", person->name);
    printf("ID: %d\n", person->id);

    if (shmdt(person) == -1) {
        printf("Error detaching from shared memory.\n");
        exit(1);
    }
}

void write_to_shm(int shmid) {
    person_t *person = (person_t *)shmat(shmid, NULL, 0);

    if (person == (void *)-1) {
        printf("Error attaching to shared memory.\n");
        exit(1);
    }

    strcpy(person->name, "John Doe");
    person->id = 12345;

    if (shmdt(person) == -1) {
        printf("Error detaching from shared memory.\n");
        exit(1);
    }
}

int main() {
    int shmid, pid;
    int status;

    if ((shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    if ((pid = fork()) == -1) {
        printf("Error forking process.\n");
        exit(1);
    } else if (pid == 0) {
        write_to_shm(shmid);
        exit(0);
    } else {
        waitpid(pid, &status, 0);
        read_from_shm(shmid);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment.\n");
        exit(1);
    }

    return 0;
}