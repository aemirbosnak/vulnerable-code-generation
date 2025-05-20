//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process
{
    int pid;
    int arrival_time;
    int service_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int pid, int arrival_time, int service_time)
{
    Process* process = (Process*)malloc(sizeof(Process));
    process->pid = pid;
    process->arrival_time = arrival_time;
    process->service_time = service_time;
    process->remaining_time = service_time;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int pid, int arrival_time, int service_time)
{
    Process* process = createProcess(pid, arrival_time, service_time);
    if (head == NULL)
    {
        head = process;
    }
    else
    {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head)
{
    time_t start_time = time(NULL);
    int current_time = 0;
    int completed = 0;

    while (!completed)
    {
        current_time = time(NULL) - start_time;

        if (head)
        {
            if (current_time >= head->arrival_time && head->remaining_time > 0)
            {
                head->remaining_time--;
                printf("Process %d completed.\n", head->pid);
                completed++;
            }
            else
            {
                head = head->next;
            }
        }
        else
        {
            completed = 1;
        }

        sleep(1);
    }
}

int main()
{
    Process* head = NULL;
    addProcess(head, 1, 0, 5);
    addProcess(head, 2, 2, 4);
    addProcess(head, 3, 4, 3);
    addProcess(head, 4, 6, 2);
    addProcess(head, 5, 8, 1);

    roundRobin(head);

    return 0;
}