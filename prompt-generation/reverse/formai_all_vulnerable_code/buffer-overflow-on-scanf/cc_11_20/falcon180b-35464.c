//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, n, m;
    int a[100], b[100], c[200];
    int choice, sum = 0;

    printf("Enter the size of the first array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("\nEnter the size of the second array: ");
    scanf("%d", &m);

    printf("Enter %d integers:\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    printf("\nChoose an operation:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    c[i * m + j] = a[i] & b[j];
                }
            }
            break;
        case 2:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    c[i * m + j] = a[i] | b[j];
                }
            }
            break;
        case 3:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    c[i * m + j] = a[i] ^ b[j];
                }
            }
            break;
        case 4:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    c[i * m + j] = ~a[i] & b[j];
                }
            }
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    printf("\nResult:\n");
    for (i = 0; i < n * m; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}