//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define ARRIVAL_TIME 0
#define BURST_TIME 1
#define WAITING_TIME 2
#define TURN_AROUND_TIME 3
#define COMPLETION_TIME 4

int queue[MAX], front = -1, rear = -1;
int size, i;
int waiting_time[MAX], turnaround_time[MAX];
int shortest_remaining_time = 0;

void add_process(int process_id, int burst_time)
{
    rear++;
    queue[rear] = burst_time;
    waiting_time[rear] = 0;
    turnaround_time[rear] = 0;
}

void execute_processes()
{
    int current_time = 0;
    while (front <= rear)
    {
        if (queue[front] <= current_time)
        {
            current_time += queue[front];
            shortest_remaining_time += queue[front];
            front++;
        }
        else
        {
            break;
        }
    }

    if (front > rear)
    {
        rear = -1;
        front = -1;
    }
}

void print_queue()
{
    printf("\nQueue:\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void print_waiting_time()
{
    printf("\nWaiting Time:\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", waiting_time[i]);
    }
    printf("\n");
}

void print_turnaround_time()
{
    printf("\nTurnaround Time:\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", turnaround_time[i]);
    }
    printf("\n");
}

int main()
{
    int i, j, n, min_burst_time = 999, index;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
        if (queue[i] < min_burst_time)
        {
            min_burst_time = queue[i];
        }
    }

    for (j = 0; j < n; j++)
    {
        add_process(j + 1, queue[j]);
    }

    execute_processes();

    printf("\nGantt Chart:\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    avg_waiting_time = (float)waiting_time[rear] / n;
    avg_turnaround_time = (float)turnaround_time[rear] / n;

    printf("\n\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);

    return 0;
}