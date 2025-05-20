//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/mman.h>

#define SIZE 10

int main()
{
    int shm_id = shmget(IPC_PRIVATE, SIZE*sizeof(int), 0777|IPC_CREAT);
    if(shm_id < 0)
    {
        printf("Failed to create shared memory\n");
        exit(1);
    }
    int* shared_mem = (int*)shmat(shm_id, NULL, 0);
    if(shared_mem == (int*)-1)
    {
        printf("Failed to attach shared memory\n");
        exit(1);
    }
    int pid = fork();
    if(pid == 0)
    {
        for(int i=0; i<SIZE; i++)
        {
            shared_mem[i] = i;
        }
        printf("Child process wrote to shared memory\n");
        exit(0);
    }
    else
    {
        wait(NULL);
        for(int i=0; i<SIZE; i++)
        {
            printf("Parent process read from shared memory: %d\n", shared_mem[i]);
        }
        exit(0);
    }
    return 0;
}