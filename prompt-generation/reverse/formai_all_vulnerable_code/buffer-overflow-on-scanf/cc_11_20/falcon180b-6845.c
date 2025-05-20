//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, operator;
    char input[10];
    float decimal1, decimal2, decimalResult;
    int count = 0;
    float sum = 0;
    float average;
    int arr[10];
    int i;

    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    while (1) {
        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter second number: ");
        scanf("%s", input);
        if (strcmp(input, "+") == 0) {
            operator = 1;
        } else if (strcmp(input, "-") == 0) {
            operator = 2;
        } else if (strcmp(input, "*") == 0) {
            operator = 3;
        } else if (strcmp(input, "/") == 0) {
            operator = 4;
        } else {
            printf("Invalid operator\n");
            continue;
        }
        if (operator == 1 || operator == 2 || operator == 3) {
            result = num1 + num2;
        } else if (operator == 4) {
            if (num2 == 0) {
                printf("Division by zero\n");
                continue;
            }
            result = num1 / num2;
        }
        printf("Result: %d\n", result);
        count++;
        if (count == 10) {
            average = (float) sum / 10;
            printf("Average: %.2f\n", average);
            count = 0;
            sum = 0;
        }
    }
}