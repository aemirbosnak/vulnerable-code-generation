#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int num1, num2, choice;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Choose operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Result: %d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case 2:
            printf("Result: %d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case 3:
            printf("Result: %d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case 4:
            if (num2 != 0)
                printf("Result: %d / %d = %d\n", num1, num2, num1 / num2);
            else
                printf("Error: Division by zero\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
