//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result;
    int choice;
    char input[3];
    srand(time(NULL));

    printf("Welcome to the Bitwise Operations Program!\n");
    printf("Please choose an operation:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");
    scanf("%d", &choice);

    printf("Enter two numbers:\n");
    scanf("%d%d", &num1, &num2);

    switch(choice) {
        case 1:
            result = num1 & num2;
            printf("Result: %d\n", result);
            break;
        case 2:
            result = num1 | num2;
            printf("Result: %d\n", result);
            break;
        case 3:
            result = num1 ^ num2;
            printf("Result: %d\n", result);
            break;
        case 4:
            result = ~num1;
            printf("Result: %d\n", result);
            break;
        case 5:
            result = num1 << 2;
            printf("Result: %d\n", result);
            break;
        case 6:
            result = num1 >> 2;
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}