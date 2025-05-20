//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int num_processes, i, j, t_quantum;
    int *process_ids, *burst_times, *waiting_times, *turn_around_times;
    bool *completed_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    process_ids = malloc(num_processes * sizeof(int));
    burst_times = malloc(num_processes * sizeof(int));
    waiting_times = malloc(num_processes * sizeof(int));
    turn_around_times = malloc(num_processes * sizeof(int));
    completed_processes = malloc(num_processes * sizeof(bool));

    for (i = 0; i < num_processes; i++)
    {
        process_ids[i] = i + 1;
        printf("Enter the burst time for process %d: ", process_ids[i]);
        scanf("%d", &burst_times[i]);
        completed_processes[i] = false;
        waiting_times[i] = 0;
        turn_around_times[i] = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &t_quantum);

    // Round Robin Scheduling Algorithm
    int current_time = 0, current_pid = 0;
    while (true)
    {
        for (i = 0; i < num_processes; i++)
        {
            if (completed_processes[i] == false)
            {
                current_pid = i;
                break;
            }
        }

        // If all processes have been completed
        if (i == num_processes)
        {
            break;
        }

        while (true)
        {
            if (burst_times[current_pid] > t_quantum)
            {
                current_time += t_quantum;
                burst_times[current_pid] -= t_quantum;
            }
            else
            {
                current_time += burst_times[current_pid];
                turn_around_times[current_pid] = current_time;
                burst_times[current_pid] = 0;
                completed_processes[current_pid] = true;
                break;
            }

            for (j = 0; j < num_processes; j++)
            {
                if (completed_processes[j] == false && j != current_pid && current_time >= turn_around_times[j])
                {
                    waiting_times[j] += t_quantum;
                }
            }
        }
    }

    // Calculate and print average waiting and turn around times
    float avg_waiting_time = 0, avg_turn_around_time = 0;
    for (i = 0; i < num_processes; i++)
    {
        avg_waiting_time += waiting_times[i];
        avg_turn_around_time += turn_around_times[i] - burst_times[i];
    }
    avg_waiting_time /= num_processes;
    avg_turn_around_time /= num_processes;

    printf("\n\nPROCESS\t   BURST TIME\t   WAITING TIME\t   TURN AROUND TIME\n");
    for (i = 0; i < num_processes; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", process_ids[i], burst_times[i], waiting_times[i], turn_around_times[i] - burst_times[i]);
    }

    printf("\nAverage Waiting Time: %.2f ms\n", avg_waiting_time);
    printf("Average Turn Around Time: %.2f ms\n", avg_turn_around_time);

    return 0;
}