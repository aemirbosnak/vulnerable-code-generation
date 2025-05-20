//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include<stdio.h>

void fcfs(){ //First Come First Serve Algorithm

    int n,b[20],w[20],t[20],i,avgw=0,avgt=0,time=0;

    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\nEnter the burst time of the processes:\n");

    for(i=0;i<n;i++){
        printf("P[%d]:",i+1);
        scanf("%d",&b[i]);
    }

    w[0]=0;
    for(i=1;i<n;i++){
        time+=b[i-1];
        w[i]=time;
        avgw+=w[i];
    }

    for(i=0;i<n;i++){
        t[i]=b[i]+w[i];
        avgt+=t[i];
    }

    printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time\n");

    for(i=0;i<n;i++){
        printf("P[%d]\t %d\t\t %d\t\t %d\n",i+1,b[i],w[i],t[i]);
    }

    avgw/=n;
    avgt/=n;

    printf("\nAverage Waiting Time: %d\nAverage Turnaround Time: %d",avgw,avgt);

}

void sjf(){ //Shortest Job First Algorithm

    int n,b[20],w[20],t[20],a[20],i,pos,temp,j,avgw=0,avgt=0;

    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\nEnter the burst time and arrival time of the processes:\n");

    for(i=0;i<n;i++){
        printf("P[%d] Arrival Time :",i+1);
        scanf("%d",&a[i]);
        printf("P[%d] Burst Time   :",i+1);
        scanf("%d",&b[i]);
    }

    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(b[j]<b[pos]){
                pos=j;
            }
        }
        temp=b[i];
        b[i]=b[pos];
        b[pos]=temp;
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }

    w[0]=0;
    for(i=1;i<n;i++){
        w[i]=0;
        for(j=0;j<i;j++){
            w[i]+=b[j];
        }
        avgw+=w[i];
    }

    for(i=0;i<n;i++){
        t[i]=b[i]+w[i];
        avgt+=t[i];
    }

    printf("\nProcess\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");

    for(i=0;i<n;i++){
        printf("P[%d]\t %d\t\t %d\t\t %d\t\t %d\n",i+1,a[i],b[i],w[i],t[i]);
    }

    avgw/=n;
    avgt/=n;

    printf("\nAverage Waiting Time: %d\nAverage Turnaround Time: %d",avgw,avgt);

}

void priority(){ //Priority Scheduling Algorithm

    int n,b[20],w[20],t[20],p[20],i,pos,temp,j,avgw=0,avgt=0;

    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("\nEnter the burst time and priority of the processes:\n");

    for(i=0;i<n;i++){
        printf("P[%d] Priority :",i+1);
        scanf("%d",&p[i]);
        printf("P[%d] Burst Time:",i+1);
        scanf("%d",&b[i]);
    }

    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(p[j]<p[pos]){
                pos=j;
            }
        }
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
        temp=b[i];
        b[i]=b[pos];
        b[pos]=temp;
    }

    w[0]=0;
    for(i=1;i<n;i++){
        w[i]=0;
        for(j=0;j<i;j++){
            w[i]+=b[j];
        }
        avgw+=w[i];
    }

    for(i=0;i<n;i++){
        t[i]=b[i]+w[i];
        avgt+=t[i];
    }

    printf("\nProcess\t Burst Time\t Priority\t Waiting Time\t Turnaround Time\n");

    for(i=0;i<n;i++){
        printf("P[%d]\t %d\t\t %d\t\t %d\t\t %d\n",i+1,b[i],p[i],w[i],t[i]);
    }

    avgw/=n;
    avgt/=n;

    printf("\nAverage Waiting Time: %d\nAverage Turnaround Time: %d",avgw,avgt);

}

int main(){

    int choice;

    printf("Choose a scheduling algorithm:\n");
    printf("1. FCFS (First Come First Serve)\n");
    printf("2. SJF (Shortest Job First)\n");
    printf("3. Priority Scheduling\n");

    scanf("%d",&choice);

    switch(choice){
        case 1: fcfs();
                break;
        case 2: sjf();
                break;
        case 3: priority();
                break;
        default: printf("Invalid choice!");
    }

    return 0;
}