//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, choice, result;
    char repeat;

    srand(time(NULL));

    do {
        printf("Enter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);
        printf("Enter your choice:\n1. AND\n2. OR\n3. XOR\n4. NOT\n5. Left Shift\n6. Right Shift\n");
        scanf("%d", &choice);

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
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &repeat);
    } while(repeat == 'y' || repeat == 'Y');

    return 0;
}