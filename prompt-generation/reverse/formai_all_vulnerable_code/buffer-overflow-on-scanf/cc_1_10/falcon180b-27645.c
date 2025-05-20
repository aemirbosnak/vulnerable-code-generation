//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define a function to perform bitwise operations */
void bitwise_operations(int a, int b, char operation) {
    switch (operation) {
        case '&': /* Bitwise AND operation */
            printf("Bitwise AND of %d and %d is %d\n", a, b, a & b);
            break;
        case '|': /* Bitwise OR operation */
            printf("Bitwise OR of %d and %d is %d\n", a, b, a | b);
            break;
        case '^': /* Bitwise XOR operation */
            printf("Bitwise XOR of %d and %d is %d\n", a, b, a ^ b);
            break;
        case '~': /* Bitwise NOT operation */
            printf("Bitwise NOT of %d is %d\n", a, ~a);
            break;
        case '<<': /* Bitwise left shift operation */
            printf("Bitwise left shift of %d by %d is %d\n", a, b, a << b);
            break;
        case '>>': /* Bitwise right shift operation */
            printf("Bitwise right shift of %d by %d is %d\n", a, b, a >> b);
            break;
        default:
            printf("Invalid operation\n");
    }
}

int main() {
    int num1, num2, choice;

    /* Prompt user to enter two numbers */
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    /* Prompt user to choose bitwise operation */
    printf("Choose bitwise operation:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Bitwise left shift\n");
    printf("6. Bitwise right shift\n");
    scanf("%d", &choice);

    /* Perform bitwise operation */
    switch (choice) {
        case 1:
            bitwise_operations(num1, num2, '&');
            break;
        case 2:
            bitwise_operations(num1, num2, '|');
            break;
        case 3:
            bitwise_operations(num1, num2, '^');
            break;
        case 4:
            bitwise_operations(num1, num2, '~');
            break;
        case 5:
            bitwise_operations(num1, num2, '<<');
            break;
        case 6:
            bitwise_operations(num1, num2, '>>');
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}