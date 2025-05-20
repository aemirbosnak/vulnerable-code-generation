//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int main() {
    int i, j, n;
    int *a, *b;
    int sum = 0;
    int *result;

    // get input from user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    printf("Enter the elements of array a: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    b = (int *)malloc(n * sizeof(int));
    if (b == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    printf("Enter the elements of array b: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    // generate random key
    srand(time(0));
    int key = rand() % n;

    // perform addition
    result = (int *)malloc((n + 1) * sizeof(int));
    if (result == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    for (i = 0; i < n; i++) {
        result[i] = (a[i] + b[i]) % n;
    }
    result[n] = sum;

    // encrypt using key
    for (i = 0; i < n; i++) {
        result[i] = (result[i] + key) % n;
    }

    // print result
    printf("Result of addition: ");
    for (i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}