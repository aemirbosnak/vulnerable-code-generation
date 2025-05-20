//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operation, result, i;
    char input[100];
    time_t start, end;
    double time_taken;

    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%s", input);

    sscanf(input, "%d", &num2);

    printf("Enter the operation (+, -, *, /): ");
    scanf("%s", input);

    operation = input[0];

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                return 0;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operation\n");
            return 0;
    }

    time(&start);
    for (i = 0; i < 100000000; i++) {
        result += i;
    }
    time(&end);
    time_taken = difftime(end, start);

    printf("The result is: %d\n", result);
    printf("Time taken: %.6lf seconds\n", time_taken);

    return 0;
}