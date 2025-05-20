//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, i, j, k, temp, sum = 0;
    int arr1[100], arr2[100];
    int choice, bitwise_op;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n);

    printf("Enter the elements of the first array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &m);

    printf("Enter the elements of the second array:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("Enter the bitwise operation you want to perform:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    scanf("%d", &bitwise_op);

    switch (bitwise_op) {
        case 1:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    sum = arr1[i] & arr2[j];
                    printf("%d ", sum);
                }
            }
            break;

        case 2:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    sum = arr1[i] | arr2[j];
                    printf("%d ", sum);
                }
            }
            break;

        case 3:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    sum = arr1[i] ^ arr2[j];
                    printf("%d ", sum);
                }
            }
            break;

        default:
            printf("Invalid bitwise operation!\n");
    }

    return 0;
}