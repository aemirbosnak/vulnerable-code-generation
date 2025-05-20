//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 1000

int main() {
    int num;
    int arr[MAX_NUM];
    int arr_size = 0;

    printf("Enter integers (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        arr[arr_size++] = num;
    }

    printf("Enter an operator (+, -, *, /):\n");
    char op;
    scanf("%c", &op);

    int result = 0;
    switch (op) {
        case '+':
            for (int i = 0; i < arr_size; i++) {
                result += arr[i];
            }
            printf("Result: %d\n", result);
            break;
        case '-':
            for (int i = 0; i < arr_size; i++) {
                result -= arr[i];
            }
            printf("Result: %d\n", result);
            break;
        case '*':
            for (int i = 0; i < arr_size; i++) {
                result *= arr[i];
            }
            printf("Result: %d\n", result);
            break;
        case '/':
            for (int i = 0; i < arr_size; i++) {
                if (arr[i] == 0) {
                    printf("Error: Division by zero\n");
                    return 1;
                }
                result /= arr[i];
            }
            printf("Result: %d\n", result);
            break;
        default:
            printf("Error: Invalid operator\n");
            return 1;
    }

    return 0;
}