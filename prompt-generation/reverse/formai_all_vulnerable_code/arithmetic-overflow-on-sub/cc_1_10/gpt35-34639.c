//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 1024
#define BOOT_TIME 25
#define MAX_BOOT_TIME 50

typedef struct{
    int pid;
    int start_time;
    int duration;
} process;

void swap(process *a, process *b){
    process temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(process arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j].start_time > arr[j+1].start_time)
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void runProcesses(process processes[], int n){
    int time = 0;
    int i;
    
    for(i=0; i<n; i++){
        process p = processes[i];
        if(p.start_time > time)
            time = p.start_time;
        time += p.duration;
    }
}

int main(){
    srand(time(NULL));
    process processes[MAX_PROCESSES];
    int i, n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        processes[i].pid = i+1;
        processes[i].start_time = rand() % MAX_BOOT_TIME;
        processes[i].duration = rand() % (MAX_BOOT_TIME - processes[i].start_time) + 1;
    }

    printf("\nProcesses:\n");
    printf("PID\tStart Time\tDuration\n");
    for(i=0; i<n; i++){
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].start_time, processes[i].duration);
    }

    bubbleSort(processes, n);

    printf("\nProcesses (sorted):\n");
    printf("PID\tStart Time\tDuration\n");
    for(i=0; i<n; i++){
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].start_time, processes[i].duration);
    }

    printf("\nRunning processes...\n");

    runProcesses(processes, n);

    printf("\nBoot time optimized!\n");

    return 0;
}