//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n, m, i, j, k, l, count = 0, flag = 0, sum = 0, product = 1;
    double avg, median, mode;
    char op;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);

    switch(op) {
        case '+':
            for(i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("Sum = %d\n", sum);
            break;
        case '-':
            for(i = 0; i < n; i++) {
                sum -= arr[i];
            }
            printf("Sum = %d\n", sum);
            break;
        case '*':
            for(i = 0; i < n; i++) {
                product *= arr[i];
            }
            printf("Product = %d\n", product);
            break;
        case '/':
            for(i = 0; i < n; i++) {
                if(arr[i] == 0) {
                    printf("Division by zero is not allowed.\n");
                    exit(0);
                }
                else {
                    product *= arr[i];
                }
            }
            printf("Product = %d\n", product);
            break;
        default:
            printf("Invalid operator.\n");
    }

    return 0;
}