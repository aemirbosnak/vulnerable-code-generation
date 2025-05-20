//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    double x, y, z;
    char choice;

    // Prompt user to enter a number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Prompt user to choose an operation
    printf("Choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf(" %c", &choice);

    // Perform selected operation
    switch (choice) {
        case '1':
            x = n;
            y = n;
            z = x + y;
            printf("Result: %d + %d = %.2f\n", x, y, z);
            break;
        case '2':
            x = n;
            y = n;
            z = x - y;
            printf("Result: %d - %d = %.2f\n", x, y, z);
            break;
        case '3':
            x = n;
            y = n;
            z = x * y;
            printf("Result: %d * %d = %.2f\n", x, y, z);
            break;
        case '4':
            x = n;
            y = n;
            z = x / y;
            printf("Result: %d / %d = %.2f\n", x, y, z);
            break;
        default:
            printf("Invalid operation selected.\n");
            break;
    }

    return 0;
}