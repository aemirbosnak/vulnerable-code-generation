//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to the CPU Scheduling Algorithm Puzzler!\n");
    printf("In this game, you will be given a set of processes and their burst times.\n");
    printf("You need to use a scheduling algorithm to determine the order in which the processes will be executed.\n");
    printf("Ready? Let's begin!\n\n");

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int *burst_time = (int*) malloc(n * sizeof(int));
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    printf("\nChoose a scheduling algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Priority Scheduling\n");
    printf("4. Round Robin (RR)\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nYou have chosen FCFS scheduling algorithm!\n");
            printf("The order of process execution will be:\n");
            for(i = 0; i < n; i++)
                printf("P%d ", i+1);
            printf("\n");
            break;

        case 2:
            printf("\nYou have chosen SJF scheduling algorithm!\n");
            printf("The order of process execution will be:\n");
            int j;
            int *burst_copy = (int*) malloc(n * sizeof(int));
            int *visited = (int*) malloc(n * sizeof(int));
            for(i = 0; i < n; i++)
            {
                burst_copy[i] = burst_time[i];
                visited[i] = 0;
            }

            for(i = 0; i < n; i++)
            {
                int min_index;
                for(j = 0; j < n; j++)
                {
                    if(!visited[j])
                    {
                        min_index = j;
                        break;
                    }
                }
                for(j = 0; j < n; j++)
                {
                    if(burst_copy[j] < burst_copy[min_index] && !visited[j])
                        min_index = j;
                }
                printf("P%d ", min_index+1);
                visited[min_index] = 1;
            }
            printf("\n");
            free(burst_copy);
            free(visited);
            break;

        case 3:
            printf("\nYou have chosen Priority Scheduling algorithm!\n");
            printf("Enter the priorities for the processes:\n");
            int *priority = (int*) malloc(n * sizeof(int));
            for(i = 0; i < n; i++)
            {
                printf("Enter the priority for process %d: ", i+1);
                scanf("%d", &priority[i]);
            }

            printf("The order of process execution will be:\n");
            int *priority_copy = (int*) malloc(n * sizeof(int));
            visited = (int*) malloc(n * sizeof(int));
            for(i = 0; i < n; i++)
            {
                priority_copy[i] = priority[i];
                visited[i] = 0;
            }

            for(i = 0; i < n; i++)
            {
                int max_index;
                for(j = 0; j < n; j++)
                {
                    if(!visited[j])
                    {
                        max_index = j;
                        break;
                    }
                }
                for(j = 0; j < n; j++)
                {
                    if(priority_copy[j] > priority_copy[max_index] && !visited[j])
                        max_index = j;
                }
                printf("P%d ", max_index+1);
                visited[max_index] = 1;
            }
            printf("\n");
            free(priority_copy);
            free(visited);
            break;

        case 4:
            printf("\nYou have chosen Round Robin scheduling algorithm!\n");
            printf("Enter the time quantum: ");
            int quantum;
            scanf("%d", &quantum);

            printf("The order of process execution will be:\n");
            int *burst_copy2 = (int*) malloc(n * sizeof(int));
            for(i = 0; i < n; i++)
                burst_copy2[i] = burst_time[i];

            int done = 0;
            int t = 0;
            int *visited2 = (int*) malloc(n * sizeof(int));
            while(!done)
            {
                done = 1;
                for(i = 0; i < n; i++)
                {
                    if(burst_copy2[i] > 0)
                    {
                        done = 0;
                        if(burst_copy2[i] > quantum)
                        {
                            t += quantum;
                            burst_copy2[i] -= quantum;
                            printf("P%d ", i+1);
                        }
                        else
                        {
                            t += burst_copy2[i];
                            visited2[i] = 1;
                            burst_copy2[i] = 0;
                            printf("P%d ", i+1);
                        }
                    }
                }
            }
            printf("\n");
            free(burst_copy2);
            free(visited2);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    free(burst_time);

    return 0;
}