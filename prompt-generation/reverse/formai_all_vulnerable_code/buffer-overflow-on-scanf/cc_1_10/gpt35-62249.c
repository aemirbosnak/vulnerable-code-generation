//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for(i=1;i<n;i++) {
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void selection_sort(int arr[], int n) {
    int i,j,min,temp;
    for(i=0;i<n-1;i++) {
        min=i;
        for(j=i+1;j<n;j++) {
            if(arr[j]<arr[min])
                min=j;
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

int main () {

    clock_t begin, end;
    double time_spent;

    int arr[ARRAY_SIZE], i, choice;

    printf("Please select the sorting algorithm you want to benchmark: \n");
    printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n");
    printf("Enter your choice (1, 2 or 3): ");
    scanf("%d", &choice);

    srand(time(NULL));

    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000000;
    }

    switch (choice) {
        case 1:
            begin = clock();
            bubble_sort(arr, ARRAY_SIZE);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Time taken by Bubble Sort: %f seconds.\n", time_spent);
            break;
        case 2:
            begin = clock();
            insertion_sort(arr, ARRAY_SIZE);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Time taken by Insertion Sort: %f seconds.\n", time_spent);
            break;
        case 3:
            begin = clock();
            selection_sort(arr, ARRAY_SIZE);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Time taken by Selection Sort: %f seconds.\n", time_spent);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}