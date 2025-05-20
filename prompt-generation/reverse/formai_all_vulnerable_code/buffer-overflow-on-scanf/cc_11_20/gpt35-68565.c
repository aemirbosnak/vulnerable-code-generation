//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include<stdio.h>

int main()
{
    int i, j, n, time, temp, avg_turnaround = 0, avg_waiting = 0;
    int arr_time[20], bur_time[20], priority[20], turnaround_t[20], waiting_t[20], rem[20];
    char p_name[20][50], temp_name[50];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Process %d Name: ", i + 1);
        scanf("%s", &p_name[i]);
        printf("Enter Arrival Time of Process %d: ", i + 1);
        scanf("%d", &arr_time[i]);
        printf("Enter Burst Time of Process %d: ", i + 1);
        scanf("%d", &bur_time[i]);
        printf("Enter Priority of Process %d: ", i + 1);
        scanf("%d", &priority[i]);
        rem[i] = bur_time[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr_time[i] > arr_time[j])
            {
                temp = arr_time[i];
                arr_time[i] = arr_time[j];
                arr_time[j] = temp;

                temp = bur_time[i];
                bur_time[i] = bur_time[j];
                bur_time[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                strcpy(temp_name, p_name[i]);
                strcpy(p_name[i], p_name[j]);
                strcpy(p_name[j], temp_name);
            }
        }
    }

    printf("\nGantt Chart:\n");
    printf("  ");
    for (time = arr_time[0]; time < arr_time[n-1];)
    {
        int max_priority = -1, next_proc = -1;
        for (i = 0; i < n; i++)
        {
            if (arr_time[i] <= time && rem[i] > 0 && priority[i] > max_priority)
            {
                max_priority = priority[i];
                next_proc = i;
            }
        }
        if (next_proc == -1)
        {
            printf("--Idle--");
            time++;
            continue;
        }
        printf("|%s|", p_name[next_proc]);
        rem[next_proc]--;
        time++;
        if (rem[next_proc] == 0)
        {
            turnaround_t[next_proc] = time - arr_time[next_proc];
            waiting_t[next_proc] = turnaround_t[next_proc] - bur_time[next_proc];
            avg_turnaround += turnaround_t[next_proc];
            avg_waiting += waiting_t[next_proc];
        }
    }
    printf("\n");

    printf("\nProcess Details:");
    printf("\n| Process Name | Arrival Time | Burst Time | Priority |Turnaround Time| Waiting Time |\n");
    for (i = 0; i < n; i++)
    {
        printf("|     %s\t   |      %d\t   |     %d\t  |     %d\t |      %d\t     |     %d\t      |\n", p_name[i], arr_time[i], bur_time[i], priority[i], turnaround_t[i], waiting_t[i]);
    }
    printf("\nAverage Turnaround Time is: %f", (float)avg_turnaround / n);
    printf("\nAverage Waiting Time is: %f\n", (float)avg_waiting / n);

    return 0;
}