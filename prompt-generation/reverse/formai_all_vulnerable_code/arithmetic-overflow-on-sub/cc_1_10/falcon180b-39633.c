//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int i, j, k, n, m, sum, avg;
    double start, end;
    int arr[1000];
    int temp;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(m = 0; m < 10; m++) {
        for(i = 0; i < n-1; i++) {
            for(j = 0; j < n-i-1; j++) {
                if(arr[j] > arr[j+1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(k = 0; k < 10; k++) {
        sum = 0;
        start = clock();
        for(i = 0; i < n; i++) {
            sum += arr[i];
        }
        end = clock();
        avg = (double)sum / n;
        printf("Average of the array: %.2f\n", avg);
        printf("Time taken: %.6f seconds\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    }

    return 0;
}