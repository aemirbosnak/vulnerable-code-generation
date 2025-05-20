//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main() {
    int i, j, n, m, k, l;
    int arr1[MAX_SIZE], arr2[MAX_SIZE], sum[MAX_SIZE];
    bool carry;
    char choice;

    srand(time(NULL));
    n = rand() % 10 + 1;
    m = rand() % 10 + 1;

    printf("Enter the number of elements in the first array (max %d): ", MAX_SIZE - 1);
    scanf("%d", &k);

    printf("Enter %d integers:\n", k);
    for (i = 0; i < k; i++) {
        arr1[i] = rand() % 10 + 1;
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Enter the number of elements in the second array (max %d): ", MAX_SIZE - 1);
    scanf("%d", &l);

    printf("Enter %d integers:\n", l);
    for (i = 0; i < l; i++) {
        arr2[i] = rand() % 10 + 1;
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            for (i = 0; i < k; i++) {
                sum[i] = arr1[i] + arr2[i];
            }
            printf("The sum is:\n");
            for (i = 0; i < k; i++) {
                printf("%d ", sum[i]);
            }
            break;
        case '2':
            for (i = 0; i < k; i++) {
                sum[i] = arr1[i] - arr2[i];
            }
            printf("The difference is:\n");
            for (i = 0; i < k; i++) {
                printf("%d ", sum[i]);
            }
            break;
        case '3':
            for (i = 0; i < k; i++) {
                sum[i] = arr1[i] * arr2[i];
            }
            printf("The product is:\n");
            for (i = 0; i < k; i++) {
                printf("%d ", sum[i]);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}