//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define RANGE 1000000

int main() {
    int i, j, n, *arr;
    double start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % RANGE;
    }

    start = clock();

    for (i = 0; i < n; i++) {
        if (arr[i] == 0) {
            continue;
        }
        for (j = 0; j < MAX; j++) {
            if (arr[j] == arr[i]) {
                break;
            }
        }
        if (j == MAX) {
            printf("Error: Bucket overflow\n");
            exit(1);
        }
        arr[j] = 0;
    }

    end = clock();
    printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        if (arr[i]!= 0) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}