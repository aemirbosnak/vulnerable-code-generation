//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#define max 30

struct process
{
    int pid;    //process ID
    int bt;     //burst time
    int art;    //arrival time
    int wt;     //waiting time
    int tt;     //turnaround time
    int rt;     //remaining time
} p[max];

int n;          //number of processes
int q;          //quantum time
int s;          //time slice for Round Robin algorithm

void get_input()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Enter the arrival time, burst time for process %d: ", i+1);
        scanf("%d%d", &p[i].art, &p[i].bt);
        p[i].pid = i+1;
        p[i].rt = p[i].bt;
    }
    printf("Enter the quantum time for Round Robin algorithm: ");
    scanf("%d", &q);
    printf("Enter the time slice for Round Robin algorithm: ");
    scanf("%d", &s);
}

void fcfs()
{
    int t=0;
    float avg_wt=0, avg_tt=0;
    printf("\nFCFS Scheduling Algorithm Result: \n\n");
    printf("Process ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    printf("----------------------------------------------------------------------\n");
    for(int i=0; i<n; i++)
    {
        if(t<p[i].art) t = p[i].art;
        p[i].wt = t - p[i].art;
        p[i].tt = p[i].wt + p[i].bt;
        avg_wt += p[i].wt;
        avg_tt += p[i].tt;
        printf("     %d    |      %d      |     %d     |      %d      |        %d       \n", p[i].pid, p[i].art, p[i].bt, p[i].wt, p[i].tt);
        t += p[i].bt;
    }
    avg_wt /= n;
    avg_tt /= n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tt);
}

void sjf()
{
    int t=0, min_bt, index;
    float avg_wt=0, avg_tt=0;
    printf("\nSJF Scheduling Algorithm Result: \n\n");
    printf("Process ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    printf("----------------------------------------------------------------------\n");
    for(int i=0; i<n; i++)
    {
        min_bt = 999;
        for(int j=0; j<n; j++)
        {
            if(p[j].rt<min_bt && p[j].art<=t)
            {
                min_bt = p[j].rt;
                index = j;
            }
        }
        p[index].wt = t - p[index].art;
        p[index].tt = p[index].wt + p[index].bt;
        avg_wt += p[index].wt;
        avg_tt += p[index].tt;
        printf("     %d    |      %d      |     %d     |      %d      |        %d       \n", p[index].pid, p[index].art, p[index].bt, p[index].wt, p[index].tt);
        t += p[index].bt;
        p[index].rt = 999;
    }
    avg_wt /= n;
    avg_tt /= n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tt);
}

void rr()
{
    int t=0, count=n, flag[max], wt_sum=0, tt_sum=0, min_bt;
    float avg_wt=0, avg_tt=0;
    printf("\nRound Robin Scheduling Algorithm Result: \n\n");
    printf("Process ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    printf("----------------------------------------------------------------------\n");
    for(int i=0; i<n; i++)
    {
        flag[i] = 1;
        p[i].rt = p[i].bt;
    }
    while(count)
    {
        for(int i=0; i<n; i++)
        {
            if(p[i].art<=t && p[i].rt>0)
            {
                if(p[i].rt<=q)
                {
                    wt_sum += t - p[i].art;
                    tt_sum += t - p[i].art + p[i].rt;
                    p[i].rt = 0;
                    flag[i] = 0;
                    count--;
                    printf("     %d    |      %d      |     %d     |      %d      |        %d       \n", p[i].pid, p[i].art, p[i].bt, t - p[i].art, t - p[i].art + p[i].bt);
                    t += p[i].rt;
                }
                else
                {
                    p[i].rt -= q;
                    t += q;
                    printf("     %d    |      %d      |     %d     |              |                 \n", p[i].pid, p[i].art, p[i].bt);
                }
            }
        }
    }
    avg_wt = (float)wt_sum/n;
    avg_tt = (float)tt_sum/n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tt);
}

void round_robin()
{
    int i, total=0, x, counter=0, time_quantum, temp[max];
    float avg_wt, avg_tt;
    printf("\nRound Robin Scheduling Algorithm Result: \n\n");
    printf("Process ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    printf("----------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        temp[i] = p[i].rt;
        total += p[i].bt;
    }
    time_quantum=s;
    printf("\nProcess\t\tWaiting Time	 Turnaround Time\n\n");

    for(total=0,i=0;counter!=n;)
    {
        if(temp[i] <= time_quantum && temp[i] > 0)
        {
            total += temp[i];
            temp[i] = 0;
            counter++;
            printf("\n%2d\t\t%2d\t\t\t%2d", i+1, total-p[i].art-p[i].bt, total-p[i].art);

            p[i].wt = total - p[i].art - p[i].bt;
            p[i].tt = total - p[i].art;
  
        }
        else if(temp[i] > 0)
        {
            temp[i] -= time_quantum;
            total += time_quantum;
            printf("\n%2d\t\t%2d\t\t\t%2d", i+1, total-p[i].art-p[i].bt, total-p[i].art);
        }
        if(i == n-1)
            i = 0;
        else if(p[i+1].art <= total)
            i++;
        else
            i = 0;
    }
    for (int i = 0; i < n; i++) 
    {
        p[i].tt = p[i].wt + p[i].bt;
        avg_wt += p[i].wt;
        avg_tt += p[i].tt;
        printf("\n     %d    |      %d      |     %d     |      %d      |        %d       \n", p[i].pid, p[i].art, p[i].bt, p[i].wt, p[i].tt);
    }
    avg_wt /= n;
    avg_tt /= n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tt);
    printf("\n\n");
}

int main()
{
    int choice;
    get_input();
    printf("\n#############################\n");
    printf("   CPU SCHEDULING ALGORITHM  \n");
    printf("#############################\n");
    printf("Select the algorithm to perform CPU scheduling:\n");
    printf("1. FCFS Scheduling Algorithm\n2. SJF Scheduling algorithm\n3. Round Robin Algorithm\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            fcfs();
            break;
        case 2:
            sjf();
            break;
        case 3:
            round_robin();
            break;
        default:
            printf("\nWrong choice!\n");
            break;
    }
    return 0;
}