//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    int size;
    int *array;
    char operation;
    int num1, num2, result;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    array = (int *) malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for(int i=0; i<size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the arithmetic operation: ");
    scanf(" %c", &operation);

    switch(operation) {
        case '+':
            printf("Enter the numbers to be added: ");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case '-':
            printf("Enter the numbers to be subtracted: ");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case '*':
            printf("Enter the numbers to be multiplied: ");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case '/':
            printf("Enter the numbers to be divided: ");
            scanf("%d %d", &num1, &num2);
            if(num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = num1 / num2;
                printf("Result: %d\n", result);
            }
            break;
        default:
            printf("Invalid operation\n");
    }

    free(array);
    return 0;
}