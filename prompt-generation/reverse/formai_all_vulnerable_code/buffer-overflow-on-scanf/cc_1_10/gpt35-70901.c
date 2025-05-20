//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<limits.h>

#define MAX_PROCESS 20
#define TIME_QUANTUM 4

struct Process{
    int pid;
    int at;
    int bt;
    int rt; //remaining time
    int ct; //completion time
    int tat; //turn around time
    int wt; //waiting time
} process[MAX_PROCESS], tmp[MAX_PROCESS];

void printTable(int n){
    printf("\n");
    printf("+-----+---+---+------+------+-----+----+\n");
    printf("| PID | AT | BT |  CT  | TAT  | WT  | RT |\n"); 
    printf("+-----+---+---+------+------+-----+----+\n");
    for(int i=0; i<n; i++){
        printf("| %2d  | %2d | %2d | %4d | %4d | %3d | %2d |\n",
            process[i].pid, process[i].at, process[i].bt, process[i].ct,
            process[i].tat, process[i].wt, process[i].rt);
    }
    printf("+-----+---+---+------+------+-----+----+\n");
}

int cmp(const void * a, const void * b){
    struct Process * x = (struct Process *) a;
    struct Process * y = (struct Process *) b;
    if(x->at == y->at)
        return x->pid - y->pid;
    return x->at - y->at;
}

void FCFS(int n){
    int time = 0;
    float avgTAT = 0, avgWT = 0;
    for(int i=0; i<n; i++){
        tmp[i] = process[i];
    }
    qsort(tmp, n, sizeof(struct Process), cmp);
    for(int i=0; i<n; i++){
        if(time < tmp[i].at){
            time = tmp[i].at;
        }
        tmp[i].ct = time + tmp[i].bt;
        tmp[i].tat = tmp[i].ct - tmp[i].at;
        tmp[i].wt = tmp[i].tat - tmp[i].bt;
        time = tmp[i].ct;
        avgTAT += tmp[i].tat;
        avgWT += tmp[i].wt;
    }
    printTable(n);
    printf("Average TAT: %.2f\n", avgTAT/n);
    printf("Average WT: %.2f\n", avgWT/n);
}

void roundRobin(int n){
    int time = 0, done = 0;
    float avgTAT = 0, avgWT = 0;
    int tmpRT[MAX_PROCESS];
    for(int i=0; i<n; i++){
        tmp[i] = process[i];
        tmpRT[i] = process[i].bt;
    }
    while(done < n){
        int flag = 0;
        for(int i=0; i<n; i++){
            if(tmp[i].rt == 0) continue;
            flag = 1;
            if(tmp[i].rt <= TIME_QUANTUM){
                time += tmp[i].rt;
                tmp[i].rt = 0;
                done++;
                tmp[i].ct = time;
                tmp[i].tat = tmp[i].ct - tmp[i].at;
                tmp[i].wt = tmp[i].tat - tmp[i].bt;
                avgTAT += tmp[i].tat;
                avgWT += tmp[i].wt;
            }
            else{
                tmp[i].rt -= TIME_QUANTUM;
                time += TIME_QUANTUM;
            }
        }
        if(!flag)
            time++;
    }
    printTable(n);
    printf("Average TAT: %.2f\n", avgTAT/n);
    printf("Average WT: %.2f\n", avgWT/n);
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        process[i].pid = i+1;
        printf("Enter arrival time and burst time for process %d: ", process[i].pid);
        scanf("%d %d", &process[i].at, &process[i].bt);
        process[i].rt = process[i].bt;
    }

    printf("Select the scheduling algorithm: \n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Round Robin (RR)\n");
    int opt;
    printf("Option: ");
    scanf("%d", &opt);

    switch(opt){
        case 1:
            FCFS(n);
            break;
        case 2:
            roundRobin(n);
            break;
        default:
            printf("Invalid Option!\n");
    }
    return 0;
}