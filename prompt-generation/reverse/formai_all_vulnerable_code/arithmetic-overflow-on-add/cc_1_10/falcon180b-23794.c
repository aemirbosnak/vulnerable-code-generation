//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

//Shared memory structure
struct shared_memory {
    int message;
    int read_count;
};

int main() {
    int shmid, i;
    struct shared_memory *shmptr;
    char *shmaddr;

    //Create shared memory segment
    shmid = shmget(IPC_PRIVATE, sizeof(struct shared_memory), IPC_CREAT | 0666);
    if (shmid < 0) {
        printf("Error in creating shared memory segment\n");
        exit(1);
    }

    //Attach shared memory segment to process
    shmptr = (struct shared_memory *) shmat(shmid, (void *) 0, 0);
    if ((long) shmptr == -1) {
        printf("Error in attaching shared memory segment\n");
        exit(1);
    }

    //Initialize shared memory
    shmptr->message = "Hello, world!";
    shmptr->read_count = 0;

    //Detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error in detaching shared memory segment\n");
        exit(1);
    }

    //Attach shared memory segment to process again
    shmaddr = (char *) shmat(shmid, (void *) 0, 0);
    if ((long) shmaddr == -1) {
        printf("Error in attaching shared memory segment\n");
        exit(1);
    }

    //Map shared memory to process address space
    shmptr = (struct shared_memory *) shmaddr;

    //Read message from shared memory
    printf("Message from shared memory: %s\n", shmptr->message);

    //Update read count
    shmptr->read_count++;

    //Detach shared memory segment
    if (shmdt(shmptr) == -1) {
        printf("Error in detaching shared memory segment\n");
        exit(1);
    }

    //Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error in deleting shared memory segment\n");
        exit(1);
    }

    return 0;
}