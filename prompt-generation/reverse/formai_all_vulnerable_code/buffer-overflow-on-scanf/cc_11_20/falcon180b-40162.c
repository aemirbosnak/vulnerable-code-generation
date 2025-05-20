//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int i, n, choice, position;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nChoose an operation:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Bitwise AND
            printf("\nBitwise AND of the array: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i] & arr[0]);
            }
            printf("\n");
            break;
        case 2: // Bitwise OR
            printf("\nBitwise OR of the array: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i] | arr[0]);
            }
            printf("\n");
            break;
        case 3: // Bitwise XOR
            printf("\nBitwise XOR of the array: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i] ^ arr[0]);
            }
            printf("\n");
            break;
        case 4: // Bitwise NOT
            printf("\nBitwise NOT of the array: ");
            for (i = 0; i < n; i++) {
                printf("%d ", ~arr[i]);
            }
            printf("\n");
            break;
        case 5: // Left Shift
            printf("\nLeft shift the array by: ");
            scanf("%d", &position);
            printf("\nLeft shifted array: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i] << position);
            }
            printf("\n");
            break;
        case 6: // Right Shift
            printf("\nRight shift the array by: ");
            scanf("%d", &position);
            printf("\nRight shifted array: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i] >> position);
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}