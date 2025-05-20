//FormAI DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    int choice;
    clock_t start, end;
    double time_taken;

    printf("Please choose an operation to benchmark:\n");
    printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n");

    scanf("%d", &choice);

    int arr[ARRAY_SIZE];

    // Filling the array with random values
    srand(time(0));
    for(int i=0; i<ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    switch(choice) {
        case 1:
            start = clock();
            // Bubble Sort algorithm
            for(int i=0; i<ARRAY_SIZE; i++) {
                for(int j=0; j<ARRAY_SIZE-i-1; j++) {
                    if(arr[j]>arr[j+1]) {
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            end = clock();
            time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
            printf("Bubble Sort took %f seconds.\n", time_taken);
            break;
        case 2:
            start = clock();
            // Insertion Sort algorithm
            for(int i=1; i<ARRAY_SIZE; i++) {
                int key = arr[i];
                int j = i-1;
                while(j>=0 && arr[j]>key) {
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = key;
            }
            end = clock();
            time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
            printf("Insertion Sort took %f seconds.\n", time_taken);
            break;
        case 3:
            start = clock();
            // Selection Sort algorithm
            for(int i=0; i<ARRAY_SIZE-1; i++) {
                int min_index = i;
                for(int j=i+1; j<ARRAY_SIZE; j++) {
                    if(arr[j]<arr[min_index]) {
                        min_index = j;
                    }
                }
                int temp = arr[min_index];
                arr[min_index] = arr[i];
                arr[i] = temp;
            }
            end = clock();
            time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
            printf("Selection Sort took %f seconds.\n", time_taken);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            exit(0);
    }

    return 0;
}