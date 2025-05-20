//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct process {
    char name[MAX_PROCESS_NAME_LENGTH];
    int priority;
} Process;

Process processes[MAX_PROCESSES];
int num_processes;

void swap(Process* a, Process* b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    int result = 0;
    if (((Process*)a)->priority > ((Process*)b)->priority) {
        result = 1;
    } else if (((Process*)a)->priority < ((Process*)b)->priority) {
        result = -1;
    }
    return result;
}

void quicksort(Process* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex = partition(arr, left, right);
    quicksort(arr, left, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, right);
}

int partition(Process* arr, int left, int right) {
    Process pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (arr[j].priority < pivot.priority) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

int main() {
    int i;
    int num_processes_temp;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes_temp);
    for (i = 0; i < num_processes_temp; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter the priority of process %s: ", processes[i].name);
        scanf("%d", &processes[i].priority);
    }
    quicksort(processes, 0, num_processes_temp - 1);
    printf("Sorted processes:\n");
    for (i = 0; i < num_processes_temp; i++) {
        printf("%s (priority %d)\n", processes[i].name, processes[i].priority);
    }
    return 0;
}