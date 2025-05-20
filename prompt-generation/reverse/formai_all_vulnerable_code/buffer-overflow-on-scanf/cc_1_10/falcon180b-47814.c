//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int main() {
    int i, j, n, flag = 0;
    int *a, *b;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int *) malloc(n * sizeof(int));
    b = (int *) malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    start = clock();
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
        flag = 0;
    }
    end = clock();

    if (flag == 0)
        printf("Sorted array: ");
    else
        printf("Not sorted array: ");

    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    printf("\nTime taken: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    return 0;
}