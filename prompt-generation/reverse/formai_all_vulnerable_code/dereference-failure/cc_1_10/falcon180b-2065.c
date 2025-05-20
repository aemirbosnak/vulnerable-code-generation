//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SIZE 10

int shmid;
char *shmaddr;

struct {
    int count;
    char buffer[SIZE];
} *ptr;

int main() {

    //Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);

    //Check if shared memory segment is successfully created
    if(shmid == -1) {
        printf("Shared memory segment creation failed\n");
        exit(1);
    }

    //Attach shared memory segment
    shmaddr = shmat(shmid, NULL, 0);

    //Check if shared memory segment is attached successfully
    if(shmaddr == (void *) -1) {
        printf("Shared memory segment attachment failed\n");
        exit(1);
    }

    //Initialize shared memory segment
    ptr = shmaddr;
    ptr->count = 0;
    strcpy(ptr->buffer, "Hello World!");

    //Create child process
    int pid = fork();

    //Check if child process is successfully created
    if(pid < 0) {
        printf("Child process creation failed\n");
        exit(1);
    }

    //If child process is created
    if(pid == 0) {

        //Detach shared memory segment
        shmdt(shmaddr);

        //Attach shared memory segment
        shmaddr = shmat(shmid, NULL, 0);

        //Check if shared memory segment is attached successfully
        if(shmaddr == (void *) -1) {
            printf("Shared memory segment attachment failed\n");
            exit(1);
        }

        //Increment count and modify buffer
        ptr->count++;
        strcpy(ptr->buffer, "Welcome to the world of shapeshifting!");

        //Detach shared memory segment
        shmdt(shmaddr);

        //Exit child process
        exit(0);

    }

    //If parent process
    else {

        //Wait for child process to exit
        wait(NULL);

        //Detach shared memory segment
        shmdt(shmaddr);

        //Attach shared memory segment
        shmaddr = shmat(shmid, NULL, 0);

        //Check if shared memory segment is attached successfully
        if(shmaddr == (void *) -1) {
            printf("Shared memory segment attachment failed\n");
            exit(1);
        }

        //Print updated count and buffer
        printf("Count: %d\n", ptr->count);
        printf("Buffer: %s\n", ptr->buffer);

        //Detach shared memory segment
        shmdt(shmaddr);

    }

    return 0;
}