//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/shm.h>

#define SIZE 20

int main()
{
    int fd1[2];
    int fd2[2];
    int shmid;
    pid_t childpid;
    char readbuffer[SIZE];
    char writebuffer[SIZE];
    int i;

    //create pipes
    if(pipe(fd1)==-1 || pipe(fd2)==-1)
    {
        printf("Pipe failed");
        exit(1);
    }

    //create shared memory
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT|0666);
    if(shmid==-1)
    {
        printf("Shared memory failed");
        exit(1);
    }

    //attach shared memory
    if(shmat(shmid, (void*)0, 0)==(void*)-1)
    {
        printf("Shared memory attach failed");
        exit(1);
    }

    //initialize shared memory
    for(i=0; i<SIZE; i++)
    {
        ((char*)shmat(shmid, (void*)0, 0))[i] = 'a';
    }

    //fork process
    childpid = fork();

    if(childpid < 0)
    {
        printf("Fork Failed");
        exit(1);
    }
    else if(childpid > 0)
    {
        //Parent process
        close(fd1[0]);
        close(fd2[1]);
        write(fd1[1], "Hello", 5);
        wait(NULL);
    }
    else
    {
        //Child process
        close(fd1[1]);
        close(fd2[0]);
        read(fd2[1], readbuffer, SIZE);
        printf("Received message: %s", readbuffer);
        exit(0);
    }

    return 0;
}