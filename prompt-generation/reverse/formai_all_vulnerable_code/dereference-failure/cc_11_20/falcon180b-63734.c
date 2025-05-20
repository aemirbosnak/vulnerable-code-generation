//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {

    //initialize variables
    int n = 1000;
    int i, j, k;
    int count = 0;
    int *arr = (int *)malloc(n * sizeof(int));
    int max = 0;
    int min = 1000000;

    //initialize random seed
    srand(time(NULL));

    //fill array with random integers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }

    //find max and min values in array
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    //print array
    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //sort array
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //count number of occurrences of each value in array
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
    }

    //print number of occurrences of each value
    printf("Number of occurrences:\n");
    for (i = 0; i < n; i++) {
        if (arr[i] == max) {
            printf("%d occurs %d times.\n", arr[i], count);
        }
        else if (arr[i] == min) {
            printf("%d occurs %d times.\n", arr[i], count);
        }
    }

    return 0;
}