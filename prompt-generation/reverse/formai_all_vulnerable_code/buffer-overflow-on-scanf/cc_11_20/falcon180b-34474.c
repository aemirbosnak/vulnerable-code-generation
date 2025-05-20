//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>

#define SIZE 32

int main() {
    unsigned int a, b;
    int i, j;
    char input[SIZE];

    printf("Enter a binary number: ");
    scanf("%s", input);

    a = 0;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '1') {
            a |= (1 << (SIZE - 1 - i));
        }
    }

    printf("Enter a binary number: ");
    scanf("%s", input);

    b = 0;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '1') {
            b |= (1 << (SIZE - 1 - i));
        }
    }

    printf("Enter an operation (+, -, *, /, ^, |, &, <<, >>): ");
    scanf("%s", input);

    switch (input[0]) {
        case '+':
            printf("Result: %d\n", a + b);
            break;
        case '-':
            printf("Result: %d\n", a - b);
            break;
        case '*':
            printf("Result: %d\n", a * b);
            break;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("Result: %d\n", a / b);
            }
            break;
        case '^':
            printf("Result: %d\n", a ^ b);
            break;
        case '|':
            printf("Result: %d\n", a | b);
            break;
        case '&':
            printf("Result: %d\n", a & b);
            break;
        case '<':
            printf("Result: %d\n", a << b);
            break;
        case '>':
            printf("Result: %d\n", a >> b);
            break;
        default:
            printf("Error: Invalid operation\n");
    }

    return 0;
}