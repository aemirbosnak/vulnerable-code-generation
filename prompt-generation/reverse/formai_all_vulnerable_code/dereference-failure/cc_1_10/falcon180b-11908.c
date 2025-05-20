//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int main() {
    int i, j, n, max, min;
    int *a, *b;

    srand(time(NULL));
    a = (int *)malloc(MAX * sizeof(int));
    b = (int *)malloc(MAX * sizeof(int));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    max = a[0];
    min = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    for (i = 0; i <= max - min; i++) {
        b[i] = 0;
    }

    for (i = 0; i < n; i++) {
        b[a[i] - min]++;
    }

    for (i = 1; i <= max - min; i++) {
        b[i] += b[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        j = a[i] - min + b[a[i] - min] - 1;
        b[a[i] - min]--;
        a[j] = a[i];
    }

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    free(a);
    free(b);

    return 0;
}