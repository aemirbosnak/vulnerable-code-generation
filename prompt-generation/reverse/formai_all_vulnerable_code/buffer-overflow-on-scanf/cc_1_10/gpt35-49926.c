//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>

/* Function to print binary representation of a number */
void printBinary(int num) {
    int binary[32], i = 0;
    printf("Binary Representation: ");
    while(num > 0) {
        binary[i++] = num % 2;
        num /= 2;
    }

    for(int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
    printf("\n");
}

int main() {
    int num1, num2, choice, result;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Choose a bitwise operation \n");
    printf("1. AND \n");
    printf("2. OR \n");
    printf("3. XOR \n");
    printf("4. Left Shift \n");
    printf("5. Right Shift \n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result = num1 & num2;
            printf("AND Operation: %d & %d = %d \n", num1, num2, result);
            printBinary(num1);
            printBinary(num2);
            printBinary(result);
            break;
        case 2:
            result = num1 | num2;
            printf("OR Operation: %d | %d = %d \n", num1, num2, result);
            printBinary(num1);
            printBinary(num2);
            printBinary(result);
            break;
        case 3:
            result = num1 ^ num2;
            printf("XOR Operation: %d ^ %d = %d \n", num1, num2, result);
            printBinary(num1);
            printBinary(num2);
            printBinary(result);
            break;
        case 4:
            result = num1 << num2;
            printf("Left Shift Operation: %d << %d = %d \n", num1, num2, result);
            printBinary(num1);
            printBinary(result);
            break;
        case 5:
            result = num1 >> num2;
            printf("Right Shift Operation: %d >> %d = %d \n", num1, num2, result);
            printBinary(num1);
            printBinary(result);
            break;

        default:
            printf("Invalid choice! \n");
    }

    return 0;
}