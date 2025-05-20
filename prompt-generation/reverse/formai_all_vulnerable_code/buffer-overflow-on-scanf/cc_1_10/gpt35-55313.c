//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of processes to optimize
#define MAX_PROCESSES 100

// struct to hold information about each process
typedef struct {
    char name[20];
    int priority;
} Process;

// function to swap two processes in the list
void swap(Process *x, Process *y) {
    Process temp = *x;
    *x = *y;
    *y = temp;
}

// function to perform bubble sort on the list based on process priority
void bubbleSort(Process processes[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (processes[j].priority < processes[j+1].priority) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

int main() {
    // array to hold the list of processes to optimize
    Process processes[MAX_PROCESSES];

    // get the number of processes from the user
    int n;
    printf("Enter the number of processes to optimize (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    // get the details of each process from the user
    for (int i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i+1);
        scanf("%s", processes[i].name);
        printf("Enter the priority of process %d (1-10): ", i+1);
        scanf("%d", &processes[i].priority);
    }

    // optimize the order of the processes based on priority
    bubbleSort(processes, n);

    // display the optimized order of the processes
    printf("\nThe optimized order of processes is:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", processes[i].name);
    }

    return 0;
}