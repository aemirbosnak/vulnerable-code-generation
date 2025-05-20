//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define RANGE 100

int main() {
    int i, j, n, max, min, range;
    int *a, *b;
    double start, end;

    srand(time(NULL));
    n = rand() % MAX + 1;
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        a[i] = rand() % RANGE;
    }
    max = a[0];
    min = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    range = max - min + 1;
    b = (int *)malloc(range * sizeof(int));
    for (i = 0; i < range; i++) {
        b[i] = 0;
    }
    for (i = 0; i < n; i++) {
        b[a[i] - min]++;
    }
    for (i = 1; i < range; i++) {
        b[i] += b[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        b[a[i] - min]--;
        j = b[a[i] - min];
        a[j] = a[i];
    }
    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);
    free(b);
    return 0;
}