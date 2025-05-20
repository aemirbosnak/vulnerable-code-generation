//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

#define MAX 10

struct task
{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void *runner(void *param);

int main()
{
    int i,j,sum=0;
    struct task process[MAX];

    printf("\nEnter the number of processes: ");
    scanf("%d",&i);

    for(j=0;j<i;j++)
    {
        printf("\nEnter process id: ");
        scanf("%d",&process[j].id);

        printf("Enter arrival time: ");
        scanf("%d",&process[j].arrival_time);

        printf("Enter burst time: ");
        scanf("%d",&process[j].burst_time);
    }

    pthread_t thread_id[MAX];

    for(j=0;j<i;j++)
    {
        pthread_create(&thread_id[j],NULL,runner,&process[j]);
    }

    for(j=0;j<i;j++)
    {
        pthread_join(thread_id[j],NULL);
    }

    return 0;
}

void *runner(void *param)
{
    struct task *process;
    int i,sum=0;

    process=(struct task*)param;

    printf("\nProcess %d arrived at time %d",process->id,process->arrival_time);

    sleep(process->arrival_time-0);

    printf("\nProcess %d started execution at time %d",process->id,process->arrival_time);

    sleep(process->burst_time);

    printf("\nProcess %d completed execution at time %d",process->id,process->arrival_time+process->burst_time);

    for(i=process->arrival_time;i<process->arrival_time+process->burst_time;i++)
    {
        sum+=i;
    }

    process->waiting_time=process->arrival_time-0;
    process->turnaround_time=process->arrival_time+process->burst_time-process->arrival_time;

    printf("\nWaiting time of process %d is %d",process->id,process->waiting_time);
    printf("\nTurnaround time of process %d is %d",process->id,process->turnaround_time);

    pthread_exit(0);
}