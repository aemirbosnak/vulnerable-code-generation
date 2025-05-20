//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>

int main() {
    int n, i, j, bt[10], wt[10], tat[10], p[10], temp;
    float wt_avg, tat_avg;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Get burst time and process numbers to execute
    printf("Enter burst time for each process:\n");
    for(i=0; i<n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    // Sort burst time in ascending order
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    wt[0] = 0;
    tat[0] = bt[0];
    for(i=1; i<n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
    }

    // Calculate average waiting time and average turnaround time
    wt_avg = 0;
    tat_avg = 0;
    for(i=0; i<n; i++) {
        wt_avg += wt[i];
        tat_avg += tat[i];
    }
    wt_avg /= n;
    tat_avg /= n;

    // Display results
    printf("\nProcess   Burst Time   Waiting Time   Turnaround Time\n");
    for(i=0; i<n; i++) {
        printf("   P[%d]         %d           %d              %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", wt_avg);
    printf("Average Turnaround Time = %.2f\n", tat_avg);

    return 0;
}