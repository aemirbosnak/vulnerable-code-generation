//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to perform bitwise operations */
void bitwise_operations(int num1, int num2, int operation) {
    int result = 0;

    switch (operation) {
        case 0: /* AND operation */
            result = num1 & num2;
            break;
        case 1: /* OR operation */
            result = num1 | num2;
            break;
        case 2: /* XOR operation */
            result = num1 ^ num2;
            break;
        case 3: /* NOT operation */
            result = ~num1;
            break;
        case 4: /* Left Shift operation */
            result = num1 << num2;
            break;
        case 5: /* Right Shift operation */
            result = num1 >> num2;
            break;
        default:
            printf("Invalid operation.\n");
            exit(1);
    }

    printf("Result: %d\n", result);
}

int main(int argc, char **argv) {
    int num1, num2, operation, choice;

    do {
        printf("Enter two integers:\n");
        scanf("%d %d", &num1, &num2);

        printf("Enter the operation you want to perform:\n");
        printf("1. AND\n");
        printf("2. OR\n");
        printf("3. XOR\n");
        printf("4. NOT\n");
        printf("5. Left Shift\n");
        printf("6. Right Shift\n");
        scanf("%d", &operation);

        bitwise_operations(num1, num2, operation);

        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}