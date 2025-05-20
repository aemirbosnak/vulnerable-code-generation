//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of operations:\n");
    scanf("%d", &n);

    int op[MAX_SIZE];
    printf("Enter %d operations:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &op[i]);
    }

    int result = arr[0];
    for (int i = 0; i < n; i++) {
        switch (op[i]) {
            case 1:
                result += arr[i + 1];
                break;
            case 2:
                result -= arr[i + 1];
                break;
            case 3:
                result *= arr[i + 1];
                break;
            case 4:
                result /= arr[i + 1];
                break;
            case 5:
                result = pow(arr[i + 1], result);
                break;
            default:
                printf("Invalid operation.\n");
                return 0;
        }
    }

    printf("Result: %d\n", result);

    return 0;
}