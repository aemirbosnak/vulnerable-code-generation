//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

#define SIZE 10

int main()
{
    int shmid;
    int *shmptr;
    pid_t pid;
    int status;
    int i;

    shmid = shmget((key_t)1234, SIZE*sizeof(int), IPC_CREAT|0666);

    if(shmid == -1)
    {
        printf("Shared memory creation failed\n");
        exit(0);
    }

    shmptr = (int *)shmat(shmid, 0, 0);

    if((long)shmptr == -1)
    {
        printf("Shared memory attach failed\n");
        exit(0);
    }

    for(i=0;i<SIZE;i++)
    {
        shmptr[i] = i;
    }

    pid = fork();

    if(pid == -1)
    {
        printf("Fork failed\n");
        exit(0);
    }

    if(pid == 0)
    {
        sleep(2);

        for(i=0;i<SIZE;i++)
        {
            shmptr[i] += 10;
        }

        exit(0);
    }

    wait(&status);

    printf("Shared memory values:\n");

    for(i=0;i<SIZE;i++)
    {
        printf("%d ",shmptr[i]);
    }

    shmdt(shmptr);

    shmctl(shmid, IPC_RMID, 0);

    return 0;
}