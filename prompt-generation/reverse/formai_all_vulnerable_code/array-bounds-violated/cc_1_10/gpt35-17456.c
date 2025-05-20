//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include<stdio.h> 
  
int main(){ 
    int n, i, j, temp, wt=0, tat=0; 
    float avg_wt, avg_tat; 
    printf("Enter the number of processes: "); 
    scanf("%d",&n); 
  
    int burstTime[n], processID[n], waitingTime[n], turnaroundTime[n]; 
    printf("\nEnter Burst Time of Processes:\n"); 
    for(i=0; i<n; i++){ 
        printf("Process[%d]: ", i+1); 
        scanf("%d",&burstTime[i]); 
        processID[i] = i+1; 
    } 
  
    //Sorting the Burst Time of Processes
    for(i=0; i<n-1; i++){  
        for(j=0; j<n-i-1; j++){ 
            if(burstTime[j] > burstTime[j+1]){ 
                temp = burstTime[j]; 
                burstTime[j] = burstTime[j+1]; 
                burstTime[j+1] = temp; 
                temp = processID[j]; 
                processID[j] = processID[j+1]; 
                processID[j+1] = temp; 
            } 
        } 
    } 
  
    //Finding Waiting Time of Processes
    for(i=0; i<n; i++){ 
        waitingTime[i] = 0; 
        for(j=0; j<i; j++){
            waitingTime[i] += burstTime[j]; 
        } 
        wt += waitingTime[i]; 
    } 
  
    //Finding Turnaround Time of Processes
    for(i=0; i<n; i++){ 
        turnaroundTime[i] = burstTime[i] + waitingTime[i]; 
        tat += turnaroundTime[i]; 
    } 
  
    //Printing the Results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
    for(i=0; i<n; i++){ 
        printf("P[%d]\t%d\t\t%d\t\t%d\n", processID[i], burstTime[i], waitingTime[i], turnaroundTime[i]); 
    } 
  
    avg_wt = (float)wt/n; 
    avg_tat = (float)tat/n; 
    printf("\nAverage Waiting Time: %0.2f", avg_wt); 
    printf("\nAverage Turnaround Time: %0.2f", avg_tat); 
  
    return 0; 
}