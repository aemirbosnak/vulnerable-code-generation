//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int key;
    int value;
} KeyValue;

int main() {
    clock_t start, end;
    double cpu_time_used;
    int i, j, n;
    KeyValue *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (KeyValue *) malloc(n * sizeof(KeyValue));

    printf("Enter %d key-value pairs:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].key, &arr[i].value);
    }

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].key > arr[j].key) {
                KeyValue temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].key, arr[i].value);
    }

    printf("Time taken: %lf seconds\n", cpu_time_used);

    free(arr);
    return 0;
}