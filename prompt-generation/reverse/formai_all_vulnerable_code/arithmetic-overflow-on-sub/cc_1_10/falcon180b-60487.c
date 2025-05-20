//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define INF INT_MAX

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void print_array(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int min_idx = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the burst times of the processes:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    printf("Processes sorted by burst time:\n");
    print_array(arr, n);
    int quantum = 2;
    int count = 0;
    int time_quantum[n];
    time_t start_time, end_time;
    start_time = time(NULL);
    while(count < n) {
        for(int i=0; i<n; i++) {
            if(arr[i] > quantum) {
                arr[i] -= quantum;
                time_quantum[i] += quantum;
                count++;
            } else {
                time_quantum[i] += arr[i];
                count++;
                break;
            }
        }
    }
    end_time = time(NULL);
    printf("\nTurnaround time: %ld\n", end_time - start_time);
    printf("Average turnaround time: %.2f\n", (double)end_time - start_time / n);
    return 0;
}