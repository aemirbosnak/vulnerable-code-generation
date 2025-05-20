//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int n, i, j, k, t, x, y, z, m, f, e, count = 0, flag = 0;
    int wt, tt, avgwt, avgtt;
    int at[30], bt[30], ct[30], ttat[30], wtat[30];
    srand(time(0));
    printf("\n\n Welcome to the Airport Baggage Handling Simulation!!\n\n");
    printf("Enter the number of baggage to be operated: ");
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        at[i] = rand() % 20;    
        bt[i] = rand() % 10;    
    }
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (at[i] > at[j])
            {
                x =  at[i];
                at[i] = at[j];
                at[j] = x;
                y = bt[i];
                bt[i] = bt[j];
                bt[j] = y;
            }
        }
    }
    ct[0] = bt[0];
    ttat[0] = ct[0] - at[0];
    wtat[0] = ttat[0] - bt[0];
    avgwt = wtat[0];
    avgtt = ttat[0];
    for (i = 1; i < n; ++i)
    {
        m = ct[i - 1];
        e = bt[i];
        f = -1;
        for (j = i; j < n; ++j)
        {
            if (at[j] <= m && bt[j] > f)
            {
                t = j;
                f = bt[j];
                flag = 1;
            }
        }
        if (flag == 1)
        {
            ct[t] = m + bt[t];
            ttat[t] = ct[t] - at[t];
            wtat[t] = ttat[t] - bt[t];
            flag = 0;
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
            ttat[i] = ct[i] - at[i];
            wtat[i] = ttat[i] - bt[i];
        }
        avgwt += wtat[i];
        avgtt += ttat[i];   
    }
    printf("\nBaggage\t Arrival Time\t Baggage Time\n");
    for (i = 0; i < n; ++i)
    {
        printf("B%d\t %d\t\t %d\n", i+1, at[i], bt[i]);
    }
    printf("\nBaggage\t Waiting Time\t Turnaround Time\n");
    for (i = 0; i < n; ++i)
    {
        printf("B%d\t %d\t\t %d\n", i+1, wtat[i], ttat[i]);
    }
    printf("\nAverage Waiting Time: %d", avgwt/n);
    printf("\nAverage Turnaround Time: %d\n", avgtt/n);
}