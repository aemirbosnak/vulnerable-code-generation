//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/msg.h>
#include<fcntl.h>
#define SIZE 10

struct msgbuf
{
    long mtype;
    char mtext[SIZE];
};

int main()
{
    int shmid,msqid;
    key_t key;
    char *shmaddr;
    int i,j,n;
    pid_t pid;
    struct msgbuf *msqptr;
    char readbuffer[20];

    key=(key_t)1234;
    shmid=shmget(key,sizeof(struct msgbuf),IPC_CREAT|0666);

    if(shmid<0)
    {
        printf("\n Error in shared memory get");
        exit(1);
    }
    else
    {
        printf("\n Shared memory get success");
    }

    shmaddr=(char *)shmat(shmid,NULL,0);

    if(shmaddr==(char *)-1)
    {
        printf("\n Error in attaching shared memory");
        exit(1);
    }
    else
    {
        printf("\n Shared memory attached");
    }

    for(i=0;i<SIZE;i++)
    {
        shmaddr[i]='a';
    }

    msqid=msgget(IPC_PRIVATE,0666|IPC_CREAT);

    if(msqid<0)
    {
        printf("\n Error in message queue");
        exit(1);
    }
    else
    {
        printf("\n Message queue created");
    }

    for(i=0;i<5;i++)
    {
        msgsnd(msqid,&shmaddr[i*2],2,0);
    }

    for(i=0;i<5;i++)
    {
        msgrcv(msqid,&msqptr,2,0,0);
        printf("\n Received message : %s",msqptr->mtext);
    }

    exit(0);
}