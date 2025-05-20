//FormAI DATASET v1.0 Category: Interprocess communication ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main(){
    int shmId;
    char *sharedMemory, *message;
    key_t key = 9876;

    // create a shared memory segment
    shmId = shmget(key, SIZE, IPC_CREAT | 0666);

    if(shmId < 0){
        perror("shmget error");
        exit(1);
    }

    // attach the shared memory to our address space
    sharedMemory = shmat(shmId, NULL, 0);

    if(sharedMemory == (char *) -1){
        perror("shmat error");
        exit(1);
    }

    // read message from user input
    message = malloc(SIZE);
    printf("Type your message: ");
    scanf("%[^\n]", message);

    // write message to the shared memory
    sprintf(sharedMemory, "%s", message);

    // wait for the other process to finish
    printf("Waiting for receiver process...\n");
    sleep(5);

    // read message from the shared memory
    printf("Received message from receiver: %s\n", sharedMemory);

    // detach the shared memory from our address space
    shmdt(sharedMemory);

    // delete the shared memory segment
    shmctl(shmId, IPC_RMID, NULL);

    return 0;
}