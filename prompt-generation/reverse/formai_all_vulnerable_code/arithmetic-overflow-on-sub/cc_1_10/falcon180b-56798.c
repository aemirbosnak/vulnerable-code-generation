//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    char op;
    int result;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter operator (+, -, *, /, %): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%d", &b);

    switch(op) {
        case '+':
            result = a + b;
            printf("The result is %d\n", result);
            break;

        case '-':
            result = a - b;
            printf("The result is %d\n", result);
            break;

        case '*':
            result = a * b;
            printf("The result is %d\n", result);
            break;

        case '/':
            if(b == 0) {
                printf("Error! Division by zero is not allowed.\n");
            } else {
                result = a / b;
                printf("The result is %d\n", result);
            }
            break;

        case '%':
            if(b == 0) {
                printf("Error! Division by zero is not allowed.\n");
            } else {
                result = a % b;
                printf("The result is %d\n", result);
            }
            break;
    }

    return 0;
}