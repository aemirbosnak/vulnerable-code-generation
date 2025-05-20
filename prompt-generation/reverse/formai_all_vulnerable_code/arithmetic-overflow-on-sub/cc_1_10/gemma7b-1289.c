//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS_NUMBER 5
#define MAX_CPU_TIME 10

typedef struct Process
{
    int process_number;
    int cpu_time;
    struct Process* next;
} Process;

Process* createProcess(int process_number, int cpu_time)
{
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_number = process_number;
    process->cpu_time = cpu_time;
    process->next = NULL;
    return process;
}

void insertProcess(Process* head, int process_number, int cpu_time)
{
    Process* newProcess = createProcess(process_number, cpu_time);
    if (head == NULL)
    {
        head = newProcess;
    }
    else
    {
        Process* tempProcess = head;
        while (tempProcess->next != NULL)
        {
            tempProcess = tempProcess->next;
        }
        tempProcess->next = newProcess;
    }
}

void simulateCPU(Process* head)
{
    time_t start_time = time(NULL);
    Process* currentProcess = head;
    while (currentProcess)
    {
        printf("Process %d is running...", currentProcess->process_number);
        sleep(currentProcess->cpu_time);
        currentProcess = currentProcess->next;
    }
    time_t end_time = time(NULL);
    printf("\nTotal time spent on CPU: %ld seconds", end_time - start_time);
}

int main()
{
    Process* head = NULL;
    insertProcess(head, 1, 5);
    insertProcess(head, 2, 3);
    insertProcess(head, 3, 2);
    insertProcess(head, 4, 4);
    insertProcess(head, 5, 3);

    simulateCPU(head);

    return 0;
}