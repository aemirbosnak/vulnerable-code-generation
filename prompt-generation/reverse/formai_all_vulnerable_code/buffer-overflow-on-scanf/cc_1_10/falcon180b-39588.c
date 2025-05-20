//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100
#define MAX_CPU_TIME 100
#define MAX_IO_TIME 50

struct process
{
    int id;
    int cpu_time;
    int io_time;
    int waiting_time;
    int turnaround_time;
};

void create_processes(struct process *processes, int num_processes)
{
    int i;
    for (i = 0; i < num_processes; i++)
    {
        processes[i].id = i + 1;
        processes[i].cpu_time = rand() % MAX_CPU_TIME + 1;
        processes[i].io_time = rand() % MAX_IO_TIME + 1;
    }
}

void execute_processes(struct process *processes, int num_processes)
{
    int i, j, current_process = 0, io_counter = 0;
    for (i = 0; i < num_processes; i++)
    {
        current_process = i;
        printf("Executing process %d...\n", current_process);
        for (j = 0; j < processes[current_process].cpu_time; j++)
        {
            printf(".");
            fflush(stdout);
            io_counter++;
            if (io_counter == MAX_IO_TIME)
            {
                printf("\nIO interrupt! Swapping to another process...\n");
                current_process = (current_process + 1) % num_processes;
                io_counter = 0;
            }
        }
        printf("\nProcess %d completed execution!\n", current_process);
    }
}

void calculate_times(struct process *processes, int num_processes)
{
    int i, j, waiting_time = 0, turnaround_time = 0;
    for (i = 0; i < num_processes; i++)
    {
        waiting_time += processes[i].io_time;
        turnaround_time += processes[i].io_time + processes[i].cpu_time;
    }
    printf("\nAverage waiting time: %.2f\n", (float)waiting_time / num_processes);
    printf("Average turnaround time: %.2f\n", (float)turnaround_time / num_processes);
}

int main()
{
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct process *processes = (struct process*)malloc(num_processes * sizeof(struct process));
    if (processes == NULL)
    {
        printf("Error: could not allocate memory for processes!\n");
        exit(1);
    }

    create_processes(processes, num_processes);
    execute_processes(processes, num_processes);
    calculate_times(processes, num_processes);

    free(processes);
    return 0;
}