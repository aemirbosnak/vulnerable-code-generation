//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include<stdio.h>

int main()
{
int i,j,n, arrival_time[10], burst_time[10], temp1[10], temp2[10], ct[10], wt[10], tat[10], min_ct, min_index, flag[10] = {0}, sum1 = 0, sum2 = 0;
float avg_wt = 0, avg_tat = 0;

printf("Enter the number of processes: ");
scanf("%d", &n);

for(i = 0; i < n; i++)
{
	printf("Enter Arrival Time and Burst Time for Process %d: ", i+1);
	scanf("%d %d", &arrival_time[i], &burst_time[i]);
	temp1[i] = burst_time[i];
}

//sjf scheduling
ct[0] = arrival_time[0] + burst_time[0];
temp2[0] = ct[0] - arrival_time[0];
flag[0] = 1;

for(i = 1; i < n; i++)
{
	min_ct = 9999;
	for(j = 1; j < n; j++)
	{
		if(flag[j] == 0 && burst_time[j] < min_ct && arrival_time[j] <= ct[i-1])
		{
			min_ct = burst_time[j];
			min_index = j;
		}
	}
	flag[min_index] = 1;
	temp2[min_index] = ct[i-1] - arrival_time[min_index];
	ct[i] = ct[i-1] + burst_time[min_index];
}

//tat and wt
for(i = 0; i < n; i++)
{
	tat[i] = ct[i] - arrival_time[i];
	wt[i] = tat[i] - temp1[i];
	sum1 += wt[i];
	sum2 += tat[i];
}

avg_wt = (float)sum1/n;
avg_tat = (float)sum2/n;

//displaying results
printf("\nProcess  |  Arrival Time  |  Burst Time  |  Completion Time  |  Turnaround Time  |  Waiting Time");
for(i = 0; i < n; i++)
{
	printf("\n   %d     |       %d        |       %d      |         %d        |         %d         |        %d", i+1, arrival_time[i], temp1[i], ct[i], tat[i], wt[i]);
}

printf("\n\nAverage Waiting Time: %.2fms", avg_wt);
printf("\nAverage Turnaround Time: %.2fms", avg_tat);

return 0; 
}