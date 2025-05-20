//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 100

int main() {
    int i, j, k, n;
    int a[MAX], b[MAX], c[MAX];
    int sum, carry;
    int choice;
    char ch;

    printf("Enter the size of the numbers: ");
    scanf("%d", &n);

    printf("Enter the numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the second number:\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &b[i]);
            }
            for (i = 0; i < n; i++) {
                sum = a[i] + b[i];
                c[i] = sum % 10;
                carry = sum / 10;
            }
            printf("Result:\n");
            for (i = n - 1; i >= 0; i--) {
                printf("%d", c[i]);
            }
            printf("\n");
            break;
        case 2:
            printf("Enter the number to subtract:\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &b[i]);
            }
            for (i = 0; i < n; i++) {
                sum = a[i] - b[i];
                c[i] = sum % 10;
                carry = sum / 10;
            }
            printf("Result:\n");
            for (i = n - 1; i >= 0; i--) {
                printf("%d", c[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("Enter the number to multiply:\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &b[i]);
            }
            for (i = 0; i < n; i++) {
                sum = a[i] * b[i];
                c[i] = sum % 10;
                carry = sum / 10;
            }
            printf("Result:\n");
            for (i = n - 1; i >= 0; i--) {
                printf("%d", c[i]);
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}