//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(float arr[], int n)
{
    int i, j;
    float min, max, range, *buckets;
    buckets = (float*) malloc(n * sizeof(float)); 

    min = max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        else if (arr[i] > max) max = arr[i];
    }

    range = (max - min) / (float) (n - 1);

    for (i = 0; i < n; i++) {
        j = (int) ((arr[i] - min) / range); 
        buckets[j] = arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (buckets[i] > buckets[j]) {
                float temp = buckets[i];
                buckets[i] = buckets[j];
                buckets[j] = temp;
            }
        }
    } 

    for (i = 0; i < n; i++) {
        arr[i] = buckets[i];
    }

    free(buckets);
}

int main()
{
    int n, i;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    float *arr = (float*) malloc(n * sizeof(float));
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    free(arr);
    return 0;
}