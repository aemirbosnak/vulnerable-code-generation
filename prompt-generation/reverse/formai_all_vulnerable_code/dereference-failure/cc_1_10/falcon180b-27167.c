//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 100

void create_shared_memory(int shmid, char *shmaddr)
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        *(shmaddr+i) = 'a' + i;
    }
}

void read_shared_memory(int shmid, char *shmaddr)
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        printf("%c", *(shmaddr+i));
    }
}

int main()
{
    int shmid;
    key_t key;
    char *shmaddr;
    pid_t pid;

    // create shared memory
    key = ftok("shmfile", 65);
    shmid = shmget(key, SIZE*sizeof(char), IPC_CREAT|0666);
    if(shmid == -1)
    {
        printf("Error in shmget()\n");
        exit(1);
    }

    // attach shared memory
    shmaddr = shmat(shmid, NULL, 0);
    if(shmaddr == (char *)-1)
    {
        printf("Error in shmat()\n");
        exit(2);
    }

    // create child process
    pid = fork();
    if(pid < 0)
    {
        printf("Error in fork()\n");
        exit(3);
    }
    else if(pid == 0)
    {
        // child process
        sleep(1);
        create_shared_memory(shmid, shmaddr);
        exit(0);
    }
    else
    {
        // parent process
        sleep(2);
        read_shared_memory(shmid, shmaddr);
        wait(NULL);
        shmdt(shmaddr);
        shmctl(shmid, IPC_RMID, NULL);
        exit(0);
    }

    return 0;
}