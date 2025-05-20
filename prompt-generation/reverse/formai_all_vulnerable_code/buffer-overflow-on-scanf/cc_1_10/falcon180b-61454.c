//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, choice, i;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("\nSelect an option:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Bitwise Shift Left\n");
    printf("6. Bitwise Shift Right\n");
    printf("7. Bitwise Complement\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1: // Bitwise AND
            printf("\nBitwise AND: %d\n", num1 & num2);
            break;
        case 2: // Bitwise OR
            printf("\nBitwise OR: %d\n", num1 | num2);
            break;
        case 3: // Bitwise XOR
            printf("\nBitwise XOR: %d\n", num1 ^ num2);
            break;
        case 4: // Bitwise NOT
            printf("\nBitwise NOT of num1: %d\n", ~num1);
            printf("\nBitwise NOT of num2: %d\n", ~num2);
            break;
        case 5: // Bitwise Shift Left
            printf("\nBitwise Shift Left by 2: %d\n", num1 << 2);
            printf("\nBitwise Shift Left by 3: %d\n", num2 << 3);
            break;
        case 6: // Bitwise Shift Right
            printf("\nBitwise Shift Right by 2: %d\n", num1 >> 2);
            printf("\nBitwise Shift Right by 3: %d\n", num2 >> 3);
            break;
        case 7: // Bitwise Complement
            printf("\nBitwise Complement of num1: %d\n", ~num1);
            printf("\nBitwise Complement of num2: %d\n", ~num2);
            break;
        default:
            printf("\nInvalid choice!");
            break;
    }

    return 0;
}