//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int main()
{
    int i;
    pid_t pid;
    int status;
    int semid;
    int sem_num;
    struct sembuf sem_op;
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = SEM_UNDO;
    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    if(semid == -1)
    {
        printf("Error in semget()\n");
        exit(1);
    }
    for(i=0; i<3; i++)
    {
        pid = fork();
        if(pid == -1)
        {
            printf("Error in fork()\n");
            exit(1);
        }
        else if(pid == 0)
        {
            break;
        }
        else
        {
            wait(&status);
        }
    }
    if(pid == 0)
    {
        while(1)
        {
            sleep(10);
            sem_op.sem_op = 1;
            semctl(semid, 0, SETVAL, sem_op);
            sleep(5);
            sem_op.sem_op = -1;
            semctl(semid, 0, SETVAL, sem_op);
        }
    }
    else
    {
        while(1)
        {
            printf("Enter the number of vehicles waiting at the traffic light: ");
            scanf("%d", &i);
            if(i > 0)
            {
                sem_op.sem_op = -i;
                semctl(semid, 0, SETVAL, sem_op);
                sleep(5);
                sem_op.sem_op = i;
                semctl(semid, 0, SETVAL, sem_op);
            }
        }
    }
    return 0;
}