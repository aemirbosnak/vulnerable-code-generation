//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_SCHEDULE_SIZE 5

typedef struct Process
{
    int process_id;
    int arrival_time;
    int service_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int serviceTime)
{
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = id;
    process->arrival_time = arrivalTime;
    process->service_time = serviceTime;
    process->remaining_time = serviceTime;
    process->next = NULL;

    return process;
}

void addProcess(Process** head, int id, int arrivalTime, int serviceTime)
{
    Process* process = createProcess(id, arrivalTime, serviceTime);
    if (*head == NULL)
    {
        *head = process;
    }
    else
    {
        (*head)->next = process;
        *head = process;
    }
}

void simulate(Process* head)
{
    time_t start = time(NULL);

    while (head)
    {
        int remainingTime = head->remaining_time;
        head->remaining_time--;

        if (remainingTime == 0)
        {
            printf("Process %d completed at time %ld\n", head->process_id, time(NULL) - start);
            free(head);
            head = NULL;
        }
        else
        {
            printf("Process %d waiting at time %ld\n", head->process_id, time(NULL) - start);
        }

        sleep(1);
    }

    printf("All processes completed\n");
}

int main()
{
    Process* head = NULL;

    addProcess(&head, 1, 0, 5);
    addProcess(&head, 2, 2, 4);
    addProcess(&head, 3, 4, 3);
    addProcess(&head, 4, 6, 2);
    addProcess(&head, 5, 8, 1);

    simulate(head);

    return 0;
}