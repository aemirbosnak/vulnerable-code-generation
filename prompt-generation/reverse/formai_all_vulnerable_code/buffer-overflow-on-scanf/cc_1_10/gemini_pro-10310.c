//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

typedef struct proc{
    int pid,bt,wt,tat;
}proc;

void pr_bt(proc *p, int n){
    int i;
    for(i=0;i<n;i++){
        p[i].bt=rand()%100;
    }
}

void pr_wt(proc *p, int n){
    int i,j;
    for(i=0;i<n;i++){
        p[i].wt=0;
        for(j=0;j<i;j++){
            p[i].wt+=p[j].bt;
        }
    }
}

void pr_tat(proc *p, int n){
    int i;
    for(i=0;i<n;i++){
        p[i].tat=p[i].bt+p[i].wt;
    }
}

void pr_avg(proc *p,int n){
    int i;
    float awt=0,atat=0;
    for(i=0;i<n;i++){
        awt+=p[i].wt;
        atat+=p[i].tat;
    }
    awt/=n;
    atat/=n;
    printf("Average waiting time = %f\n",awt);
    printf("Average turn around time = %f\n",atat);
}

void pr_gantt(proc *p,int n){
    int i,j;
    printf("Gantt Chart\n");
    printf("--------------------\n");
    for(i=0;i<n;i++){
        printf("| P%d |",p[i].pid);
    }
    printf("\n");
    printf("--------------------\n");
    for(i=0;i<p[n-1].tat;i++){
        for(j=0;j<n;j++){
            if(i>=p[j].wt && i<(p[j].wt+p[j].bt)){
                printf("    %d    ",p[j].pid);
            }
            else{
                printf("        ");
            }
        }
        printf("\n");
    }
    printf("--------------------\n");
}

int main(){
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    proc p[n];
    pr_bt(p,n);
    pr_wt(p,n);
    pr_tat(p,n);
    pr_avg(p,n);
    pr_gantt(p,n);
    return 0;
}