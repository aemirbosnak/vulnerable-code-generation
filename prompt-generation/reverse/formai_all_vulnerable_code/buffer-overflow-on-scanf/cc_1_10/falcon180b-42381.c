//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, i, j, k, sum;
    char operation;

    printf("Enter the number of terms: ");
    scanf("%d", &num);

    int arr[num];

    for(i = 0; i < num; i++) {
        printf("Enter term %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    switch(operation) {
        case '+':
            sum = 0;
            for(i = 0; i < num; i++) {
                sum += arr[i];
            }
            printf("The sum of the terms is %d", sum);
            break;
        case '-':
            for(i = 1; i < num; i++) {
                arr[i-1] -= arr[i];
            }
            printf("The difference of the terms is %d", arr[0]);
            break;
        case '*':
            for(i = 1; i < num; i++) {
                arr[i-1] *= arr[i];
            }
            printf("The product of the terms is %d", arr[0]);
            break;
        case '/':
            for(i = 1; i < num; i++) {
                arr[i-1] /= arr[i];
            }
            printf("The quotient of the terms is %d", arr[0]);
            break;
        default:
            printf("Invalid operation entered");
    }

    return 0;
}