//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include<stdio.h>

void FCFS(int n, int Pid[], int BT[], int AT[])  // First Come First Serve Algorithm Function
{
    int WT[n], TAT[n], CT[n], total_wt = 0, total_tat = 0;

    CT[0] = BT[0] + AT[0];

    for (int i = 1; i < n; i++) {
        CT[i] = CT[i-1] + BT[i]; 
    }

    for (int i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        total_tat = total_tat + TAT[i];
        WT[i] = TAT[i] - BT[i];
        total_wt = total_wt + WT[i];
    }

    printf("\n\nPID\tBT\tAT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", Pid[i], BT[i], AT[i], CT[i], TAT[i], WT[i]);
    }

    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
}

void SJF(int n, int Pid[], int BT[], int AT[])  // Shortest Job First Algorithm Function
{
    int WT[n], TAT[n], CT[n], total_wt = 0, total_tat = 0;

    int cursor = 0;

    CT[0] = BT[0] + AT[0];

    for (int i = 1; i < n; i++) {
        int min = 99999999;
        int index = -1;

        for (int j = 0; j < n; j++) {
            if (BT[j] < min && AT[j] <= CT[i-1] && BT[j] > 0) {
                min = BT[j];
                index = j;
            }
        }

        if (index == -1) {
            cursor++;
            continue;
        }

        BT[index]--;
        CT[index] = CT[i-1] + 1;

        if (BT[index] == 0) {
            TAT[index] = CT[index] - AT[index];
            total_tat = total_tat + TAT[index];
            WT[index] = TAT[index] - BT[index];
            total_wt = total_wt + WT[index];
        }
    }

    printf("\n\nPID\tBT\tAT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", Pid[i], BT[i], AT[i], CT[i], TAT[i], WT[i]);
    }

    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
}

int main()
{
    int n, choice;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int Pid[n], BT[n], AT[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time and arrival time of process %d: ", i+1);
        scanf("%d%d", &BT[i], &AT[i]);
        Pid[i] = i+1;
    }

    printf("\nSelect CPU Scheduling Algorithm: ");
    printf("\n1. First Come First Serve (FCFS)");
    printf("\n2. Shortest Job First (SJF)");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            FCFS(n, Pid, BT, AT);
            break;
        case 2:
            SJF(n, Pid, BT, AT);
            break;
        default:
            printf("\nWrong choice entered!");
    }

    return 0;
}